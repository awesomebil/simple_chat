#include "message_server.h"

message_server::message_server() {

    set_address((char*) "::1");
    set_port(8080);

    bzero(msg_buffer, 256);
}

message_server::message_server(char* address, int port) {

    set_address(address);
    set_port(port);

    bzero(msg_buffer, 256);
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
    } else if (debug_enabled) {
        cout << "Binding successufl..." << endl;
    }


    if(listen(server_sockfd, 5) < 0) { // 3.
        cerr << "Listen call failed, errno below: " << endl;
        cerr << strerror(errno) << endl;
    } else {
        cout << "Server listening for connections..." << endl;
        char buf[256];
        cout << "Address: " << inet_ntop(AF_INET6, &ipv6_bind_address.sin6_addr, buf, sizeof(buf))
             << " port " << ntohs(ipv6_bind_address.sin6_port) << endl;
    }

    server_accept();
}

void message_server::server_accept() {
    client_len = sizeof(ipv6_client_address);
    client_sockfd = accept(server_sockfd, (struct sockaddr*) &ipv6_client_address, &client_len); // 4.

    if(client_sockfd == -1) {
        cout << "No client connected or error..." << endl;
        return;
    }

    cout << "Client connected starting chat session." << endl << endl;

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
        char buf [256];
        cerr << "Server address: " << inet_ntop(AF_INET6, &ipv6_bind_address.sin6_addr, buf, sizeof(buf))
             << " and port: " << ntohs(ipv6_bind_address.sin6_port) << endl;
    } else {
        cout << "Connection successful chat session opened!" << endl;
        char buf[256];
        cout << "Address: " << inet_ntop(AF_INET6, &ipv6_bind_address.sin6_addr, buf, sizeof(buf))
             << " port " << ntohs(ipv6_bind_address.sin6_port) << endl << endl;
    }

    start_chat_session(client_sockfd);
}

void message_server::start_chat_session(int sockfd) {
    // Implement non-Qt specific logic here.
    struct pollfd fds[2];
    int poll_ret;
    int poll_timeout = 500;
    
    fds[POLLSTDIN].fd = STDIN_FILENO;
    fds[POLLSTDIN].events = POLLIN;

    fds[NETFD_POLL].fd = sockfd;
    fds[NETFD_POLL].events = POLLIN;

    while(1) {
        if (fds[POLLSTDIN].fd == -1 || fds[NETFD_POLL].fd == -1)
        {
            cout << endl << "Connection terminated communications completed." << endl;
            break;
        }

        poll_ret = poll(fds, 2, poll_timeout);

        if(poll_ret == -1) {
            err(1, "polling error");
        }

        for(int i = 0; i < 4; ++i) {
            if (fds[i].revents & (POLLERR | POLLNVAL))
            {
                fds[i].fd = -1;
            } 
        }

        if(fds[POLLSTDIN].revents & POLLIN) {
            fgets(this->msg_buffer, 256, stdin);
            message_server::send_data_to_network(this->msg_buffer);
        }

        if(fds[NETFD_POLL].revents & POLLIN) {
            read_data_from_network();
        }
    }
}

void message_server::set_address(char* addr) {
    this->address = addr;

    ipv6_bind_address.sin6_family = AF_INET6;
    inet_pton(AF_INET6, address, &ipv6_bind_address.sin6_addr);
}

void message_server::set_port(int p) {
    this->port = p;

    ipv6_bind_address.sin6_port = htons(this->port);
}

void message_server::set_ipv6(bool ipv6) {
    this->inet6 = ipv6;
}

void message_server::set_is_client(bool client) {
    this->is_client = client;
}

void message_server::set_debug_flag(bool debug) {
    this->debug_enabled = debug;
}

bool message_server::get_is_client() {
    return is_client;
}

void message_server::send_data_to_network(const char* buf) {

    int n = write(client_sockfd, buf, 255);

    if (debug_enabled)
    {
        cout << endl << endl << "***DEBUG DATA***" << endl;

        cout << "Number of bytes written to socket: " << n << endl;

        cout << "Message content sent over network: \t" << buf << endl << endl;
    }
    

    cout << "You:\t" << buf << endl << endl;
}

void message_server::read_data_from_network() {
    int n = read(client_sockfd, msg_buffer, 255);

    cout << "From client:\t" << msg_buffer << endl;
    if (debug_enabled)
    {
        cout << endl << endl << "***DEBUG DATA***" << endl;

        cout << "Number of bytes written to socket: " << n << endl;

        cout << "Message content sent over network: \t" << msg_buffer << endl << endl;
    }

    if (n == 0) {
        bzero(msg_buffer, 256);
        memcpy(msg_buffer, "Peer disconnected...", strlen("Peer disconnected..."));
        cout << msg_buffer << endl;
        exit(0);
        return;
    }
}

message_server::~message_server() {
    close(server_sockfd);
    close(client_sockfd);
}

