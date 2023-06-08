#include <HTTPServer.h>

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio.hpp>
#include <iostream>

namespace SimpleHTTPServer {

    namespace beast = boost::beast;         // from <boost/beast.hpp>
    namespace http = beast::http;           // from <boost/beast/http.hpp>

    HTTPServer::HTTPServer(const std::string &_ipAddress, const unsigned short _port) :
            m_acceptor{m_ioc, {net::ip::make_address(_ipAddress.c_str()), _port}} {}

    void HTTPServer::start() {
        try {
            for (;;) {
                tcp::socket socket{m_ioc};

                m_acceptor.accept(socket);

                beast::flat_buffer buffer;

                http::request<http::string_body> req;
                http::read(socket, buffer, req);

                http::response<http::string_body> res{http::status::ok, req.version()};
                res.set(http::field::server, BOOST_BEAST_VERSION_STRING);
                res.set(http::field::content_type, "text/plain");
                res.body() = "SimpleHTTPServer";
                res.prepare_payload();

                http::write(socket, res);
            }
        }
        catch (std::exception const &e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return;
        }
    }

}