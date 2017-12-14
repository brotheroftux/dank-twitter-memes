#ifndef cpp_httplib_mixin_h
#define cpp_httplib_mixin_h

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wshorten-64-to-32"
#include <httplib.h>
#pragma clang diagnostic pop

namespace httplib {
    
class ClientExt : Client {
    void add_default_headers(Request& req);
public:
    ClientExt (const char* host, int port) : Client(host, port) {}
    std::shared_ptr<Response> put (const char* path, const std::string& body, const char* content_type);
};
    
inline std::shared_ptr<Response> ClientExt::put (
    const char* path, const std::string& body, const char* content_type)
{
    Request req;
    req.method = "PUT";
    req.path = path;
    add_default_headers(req);
    
    req.set_header("Content-Type", content_type);
    req.body = body;
    
    auto res = std::make_shared<Response>();
    
    return send(req, *res) ? res : nullptr;
}

inline void ClientExt::add_default_headers(Request& req)
{
    req.set_header("Host", host_and_port_.c_str());
    req.set_header("Accept", "text/plain");
    req.set_header("User-Agent", "cpp-httplib/0.1");
}
    
}
    
#endif /* cpp_httplib_mixin_h */
