#ifndef MESSAGE_SERVER_H
#define MESSAGE_SERVER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <poll.h>
#include <err.h>

#define POLLSTDIN 0
#define NETFD_POLL 1

using namespace std;

class message_server
{

public:
    message_server(char* address, int port);
    message_server();
    ~message_server();

    void setup_server();
    void setup_client();
    void start_chat_session(int);
    void send_data_to_network(const char*);
    void read_data_from_network();

    void set_address(char*);
    void set_port(int);
    void set_ipv6(bool);
    void set_is_client(bool);
    void set_debug_flag(bool);

    int get_port();
    char* get_address();
    bool get_ipv6();
    bool get_is_client();
    bool get_debug_flag(bool);
private:
    char* address;
    int port, server_sockfd, client_sockfd;
    char msg_buffer[256];
    struct sockaddr_in6 ipv6_bind_address, ipv6_client_address;
    struct sockaddr_in ipv4_bind_address, ipv4_client_address;
    struct pollfd fds[2];
    bool is_client, inet6, debug_enabled;
    socklen_t client_len;

    void server_accept();

};

#endif // MESSAGE_SERVER_H

