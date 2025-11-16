#include "asio/ip/address.hpp"
#include "asio/ip/address_v4.hpp"
#include <asio/io_context.hpp>
#include <asio/ip/tcp.hpp>
#include <future>
#include <gtest/gtest.h>
#include <pocketracing/pocketracing.hpp>

TEST(All, Basics)
{
    ASSERT_NO_THROW(pocketracing::server server(0));

    pocketracing::server server(0);

    unsigned short port = server.get_port();
    ASSERT_GT(port, 0);

    ASSERT_NO_THROW(server.run_for(std::chrono::seconds(1)));
}

TEST(All, OneConnection)
{
    ASSERT_NO_THROW(pocketracing::server server(0));

    pocketracing::server server(0);

    unsigned short port = server.get_port();

    server.run_for(std::chrono::seconds(1));

    auto fut = std::async([port] {
        asio::io_context io_context;
        asio::ip::tcp::socket socket(io_context);
        socket.connect(
            asio::ip::tcp::endpoint(asio::ip::address_v4::loopback(), port));
    });

    ASSERT_NO_THROW(server.run_for(std::chrono::seconds(1)));
    ASSERT_NO_THROW(fut.get());
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
