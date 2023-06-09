#pragma once

#include <boost/asio.hpp>
#include <string>

namespace SimpleHTTPServer {

    namespace net = boost::asio;
    using tcp = net::ip::tcp;

    class HTTPServer {
    public:
        HTTPServer(const std::string &_ipAddress, const unsigned short _port);

        void start();

        void set_message(const std::string &_message);

    private:
        net::io_context m_ioc{1};
        tcp::acceptor m_acceptor;
        std::string m_message;
    };

}