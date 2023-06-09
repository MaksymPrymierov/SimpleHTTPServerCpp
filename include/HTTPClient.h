#pragma once

#include <boost/beast/http.hpp>
#include <string>

namespace SimpleHTTPServer {

    namespace beast = boost::beast;
    namespace http = beast::http;

    class HTTPClient {
    public:
        HTTPClient(const std::string &_address, const unsigned short _port = 80);

        http::response<http::dynamic_body> get();

        static constexpr std::string_view client_name{"SimpleHTTPServer[Client]"};

    private:
        const std::string m_address;
        const std::string m_port;
    };

}