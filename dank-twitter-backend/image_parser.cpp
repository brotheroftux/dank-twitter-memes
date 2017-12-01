#include "image_parser.h"

#include <iostream>

Mat fetch_image (const string & url) {
    Url url_object(url);
    const char * host = url_object.host().c_str();
    httplib::Client * client = nullptr;
    
    if (url_object.scheme() == "https")
        client = new httplib::SSLClient(host, 443);
    else
        client = new httplib::Client(host, 80);
    
    auto response = client->get(url_object.path().c_str());
    
    if (response && response->status == 200) {
        vector<unsigned char> data(response->body.begin(), response->body.end());
        Mat data_mat(data, true);
        return imdecode(data_mat, 0);
    } else {
        return Mat();
    }
}

string parse_image (Mat image) {
    httplib::ClientExt client("localhost", 9998);
    
    vector<unsigned char> data;
    
    imencode(".tif", image, data);
    
    string body_data(data.begin(), data.end());
    
    auto response = client.put("/tika", body_data, "image/tiff");
    
    return response->body;
}

