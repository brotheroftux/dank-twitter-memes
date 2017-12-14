#include <iostream>

#include "Pipe.h"

#include "image_parser.h"
#include "image_processing.h"

#include "cpp-httplib-mixin.h"
#include <json.hpp>

using namespace std;
using namespace httplib;
using nlohmann::json;

#define BASE_DIR "/Users/brotheroftux/Documents/projects/dank-twitter-memes/dank-twitter-frontend/build"

int main (int argc, const char * argv[]) {
    Server server;
    
    server.set_base_dir(BASE_DIR);
    
    server.post("/grayscale", [] (const Request & request, Response & response) {
        json data = json::parse(request.body);
        
        string blob;
        make_pipe(data["url"])
            | fetch_image
            | process_grayscale
            | convert_to_blob
            || blob;

        response.set_header("Access-Control-Allow-Origin", "*");
        response.set_content(blob, "image/png");
    });
    
    server.listen("localhost", 8008);
    
    return 0;
}
