#include "message_server.h"

message_server::message_server() {
    this->address = (char*)"::1";
    this->port = htons(8080);

    ipv6_bind_address.sin6_port = this->port;
    ipv6_bind_address.sin6_family = AF_INET6;
    inet_pton(AF_INET6, address, &ipv6_bind_address.sin6_addr);

    bzero(msg_buffer, 256);
    socket_notifier = nullptr;
}

message_server::message_server(char* address, int port) {

    this->address = address;
    this->port = htons(port);

    ipv6_bind_address.sin6_port = this->port;
    ipv6_bind_address.sin6_family = AF_INET6;
    inet_pton(AF_INET6, address, &ipv6_bind_address.sin6_addr);

    bzero(msg_buffer, 256);
    socket_notifier = nullptr;

}

void message_server::setup_server() {

    server_sockfd = socket(AF_INET6, SOCK_STREAM, 0);

    if (server_sockfd < 0) {
        cerr << "Socket creation failed :(" << endl;
        cerr << "errno: " << strerror(errno) << endl;
    }

    if (::bind(server_sockfd, (struct sockaddr*) &ipv6_bind_address, sizeof(ipv6_bind_address)) < 0) { // 2.
        cerr << "bind failed..." << endl;
        cerr << "Error: " << strerror(errno) << endl;
        cerr << "Bind address: " << address << " on port: " << port << endl;
    } else {
        cout << "Binding successufl..." << endl;
    }


    if(listen(server_sockfd, 5) < 0) { // 3.
        cerr << "Listen call failed, errno below: " << endl;
        cerr << strerror(errno) << endl;
    } else {
        cout << "Server listening for connections..." << endl;
    }

    client_len = sizeof(ipv6_client_address);
    client_sockfd = accept(server_sockfd, (struct sockaddr*) &ipv6_client_address, &client_len); // 4.

    cout << "Client connected starting chat session." << endl;

    start_chat_session(client_sockfd);

}

void message_server::setup_client() {

    client_sockfd = socket(AF_INET6, SOCK_STREAM, 0);

    if (client_sockfd < 0) {
        cerr << "Socket creation failed :(" << endl;
        cerr << "errno: " << strerror(errno) << endl;
    }

    if (::connect(client_sockfd, (struct sockaddr *) &ipv6_bind_address, sizeof(ipv6_bind_address)) < 0)
    {
        cerr << "Error connecting to server..." << endl;
        cerr << "Error no: " << strerror(errno) << endl;
    } else {
        cout << "Connection successful chat session opened!" << endl;
    }

    start_chat_session(client_sockfd);
}

void message_server::start_chat_session(int sockfd) {
    socket_notifier = new QSocketNotifier(sockfd, QSocketNotifier::Read, this);
    connect(socket_notifier, &QSocketNotifier::activated, this, &message_server::read_data_from_network);
}

void message_server::set_address(char* addr) {
    this->address = addr;
}

void message_server::set_port(int p) {
    this->port = p;
}

void message_server::send_data_to_network(const char* buf) {
    int n = write(client_sockfd, buf, 255);

    cout << endl << endl << "***DEBUG DATA***" << endl;

    cout << "Number of bytes written to socket: " << n << endl;

    cout << "Message content sent over network: \t" << buf << endl << endl;
}

void message_server::read_data_from_network() {
    int n = read(client_sockfd, msg_buffer, 255);

    cout << msg_buffer << endl;

    cout << endl << endl << "***DEBUG DATA***" << endl;

    cout << "Number of bytes read: " << n << endl;

    cout << "Message content: \t" << msg_buffer << endl << endl;

    emit message_received(QString::fromUtf8(msg_buffer, n));
}

message_server::~message_server() {
    close(server_sockfd);
    close(client_sockfd);
    delete socket_notifier;
}
