#ifndef MESSAGE_SERVER_H
#define MESSAGE_SERVER_H

#include <QObject>
#include <QSocketNotifier>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <QThread>
#include <poll.h>
#include <err.h>

#define POLLSTDIN 0
#define NETFD_POLL 1

using namespace std;

class message_server : public QObject
{
    Q_OBJECT

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

    int get_port();
    char* get_address();
private:
    char* address;
    int port, server_sockfd, client_sockfd;
    char msg_buffer[256];
    struct sockaddr_in6 ipv6_bind_address, ipv6_client_address;
    struct sockaddr_in ipv4_bind_address, ipv4_client_address;
    struct pollfd fds[2];
    bool is_client, inet6;
    socklen_t client_len;

    QSocketNotifier *socket_notifier;
    QThread workerThread;
    void server_accept();

signals:
    void message_received(const QString&);
    void error_received();

};

#endif // MESSAGE_SERVER_H
