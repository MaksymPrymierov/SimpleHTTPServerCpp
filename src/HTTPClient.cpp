#include <HTTPClient.h>

#include <boost/beast/core.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio.hpp>
#include <iostream>

namespace SimpleHTTPServer {

    namespace beast = boost::beast;
    namespace http = beast::http;
    namespace net = boost::asio;
    using tcp = net::ip::tcp;

    HTTPClient::HTTPClient(const std::string &_address, const unsigned short _port) :
            m_address{_address}, m_port{std::to_string(_port)} {}

    http::response<http::dynamic_body> HTTPClient::get() {
        try {
            net::io_context ioc;

            tcp::resolver resolver(ioc);
            tcp::resolver::results_type endpoints = resolver.resolve(m_address.c_str(), m_port.c_str());

            tcp::socket socket(ioc);
            net::connect(socket, endpoints);

            http::request<http::string_body> req{http::verb::get, "/", 11};
            req.set(http::field::host, m_address.c_str());
            req.set(http::field::user_agent, client_name);

            http::write(socket, req);

            beast::flat_buffer buffer;
            http::response<http::dynamic_body> res;

            http::read(socket, buffer, res);

            return res;
        }
        catch (std::exception const &e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return http::response<http::dynamic_body>{};
        }
    }

}