#include <iostream>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#include <httplib.h>
#pragma clang diagnostic pop

#include <json.hpp>

using namespace std;
using namespace httplib;

int main(int argc, const char * argv[]) {
    Server server;
    
    server.post("/parse_image", [] (const Request & request, const Response & response) {
        
    });
    return 0;
}
