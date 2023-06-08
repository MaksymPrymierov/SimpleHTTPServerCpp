#include <HTTPServer.h>

int main() {

    std::string ip = "127.0.0.1";
    unsigned short port = 8080;

    SimpleHTTPServer::HTTPServer server(ip, port);

    server.start();

    return 0;
}
