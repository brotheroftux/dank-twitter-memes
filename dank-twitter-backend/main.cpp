#include <iostream>

#include "Pipe.h"
#include "image_parser.h"
#include "image_processing.h"

#include "cpp-httplib-mixin.h"

#include <json.hpp>

using namespace std;
using namespace httplib;
using nlohmann::json;

int main(int argc, const char * argv[]) {
    Server server;
    
    server.post("/parse_image", [] (const Request & request, Response & response) {
        json data = json::parse(request.body);
        
        string extracted_text;
        make_pipe(data["url"])
            | fetch_image
            | process_grayscale
            | parse_image
            || extracted_text;
        
        cout << extracted_text << endl;
        response.set_content(extracted_text, "text/plain");
    });
    
    server.listen("localhost", 8008);
    
    return 0;
}
