#include "pocketracing.hpp"

#include <asio/io_context.hpp>
#include <asio/ip/tcp.hpp>
#include <print>
#include <thread>

class server_impl
{
  public:
    asio::io_context io_context;
    asio::ip::tcp::acceptor acceptor;
    unsigned short port;

  public:
    server_impl(unsigned short port)
        : acceptor(io_context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port))
    {
        this->port = acceptor.local_endpoint().port();
        this->acceptor.set_option(asio::ip::tcp::acceptor::reuse_address(true));
        this->acceptor.listen();
        this->acceptor.async_accept([](const asio::error_code &ec, asio::ip::tcp::socket socket) {
            std::println("Accepted connection from {}", socket.remote_endpoint().address().to_string());
        });
    }
};

namespace pocketracing
{
server::server(unsigned short port)
    : impl_(new server_impl(port))
{
    
}

void server::run()
{
    std::vector<std::jthread> threads;
    for (unsigned int i = 0; i < std::thread::hardware_concurrency(); ++i)
    {
        threads.emplace_back([this]() {
            static_cast<server_impl *>(this->impl_)->io_context.run();
        });
    }
}

void server::run_for(std::chrono::duration<std::chrono::steady_clock::rep, std::chrono::steady_clock::period> duration)
{
    std::vector<std::jthread> threads;
    for (unsigned int i = 0; i < std::thread::hardware_concurrency(); ++i)
    {
        threads.emplace_back([this, duration]() {
            static_cast<server_impl *>(this->impl_)->io_context.run_for(duration);
        });
    }
}

unsigned short server::get_port() const
{
    return static_cast<server_impl *>(this->impl_)->port;
}

} // namespace pocketracing
