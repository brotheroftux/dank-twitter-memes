#include <iostream>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#include <httplib.h>
#pragma clang diagnostic pop

#include <json.hpp>

#include "image_parser.h"

using namespace std;
using namespace httplib;
using nlohmann::json;

int main(int argc, const char * argv[]) {
    process_grayscale("./trash_sample_meme.jpg");
    
    Server server;
    
    server.post("/parse_image", [] (const Request & request, const Response & response) {
        json data = json::parse(request.body);
    });
    
    server.listen("localhost", 8008);
    
    return 0;
}
