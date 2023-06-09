#include <HTTPServer.h>
#include <HTTPClient.h>
#include <thread>
#include <iostream>

void start_server() {
    std::string ip = "127.0.0.1";
    unsigned short port = 8080;

    SimpleHTTPServer::HTTPServer server(ip, port);

    server.set_message("SimpleHTTPServerCpp");
    server.start();
}

int main() {
    std::thread server(start_server);

    SimpleHTTPServer::HTTPClient client("127.0.0.1", 8080);

    std::cout << client.get() << std::endl;

    server.join();

    return 0;
}
