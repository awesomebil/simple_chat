#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <string.h>
#include <poll.h>
#include <err.h>

// Macros
#define POLLSTD_IN 0
#define POLLSTD_OUT 1
#define NETFD_IN 2
#define NETFD_OUT 3

using namespace std;

// Make a hello world server socket programming implementation here.

// Creating a server class to abstract out some functionality of a listening server for messages.

class message_server {

    public:
        message_server(char* bind_address, int port) {
            server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
            port = port;

            bzero(message_buffer, 256);
        }
        void chat_session(bool terminate, char* ip_addr_to_bind) {
            this->bind_address.sin_addr.s_addr = inet_addr(ip_addr_to_bind);
            
            bind(server_sockfd, (struct sockaddr*) &bind_address, port);

            while (!terminate)
            {
                /* code */
            }
            
        }

    private:
        char message_buffer[256];
        int server_sockfd, client_sockfd, port;
        struct sockaddr_in bind_address;

};

// Basic process for connections:
// 1. Open server side socket for listening.
// 2. Bind server side socket to a listening address.
// 3. Initiate a listen call in order to receive responses.
// 4. Accept a connection and exchange data.

int read_from_network(int newsockfd, char* buffer) {
    int n = read(newsockfd, buffer, 255); // 4.

    cout << buffer << endl;

    cout << endl << endl << "***DEBUG DATA***" << endl;

    cout << "Number of bytes read: " << n << endl;

    cout << "Message content: \t" << buffer << endl << endl;

    return n;
}

void write_to_network(int newsockfd, char* buffer) {
    int n = write(newsockfd, buffer, 255);

    cout << endl << endl << "***DEBUG DATA***" << endl;

    cout << "Number of bytes written to socket: " << n << endl;

    cout << "Message content sent over network: \t" << buffer << endl << endl;
}

int main(int argc, char* argv[]) {
    
    int sockfd = socket(AF_INET6, SOCK_STREAM, 0); // Returns file descriptor, 1.
    int port = stoi(argv[1]);
    socklen_t client_len = 0;

    char buffer[256];
    bzero(buffer, 256);

    string message = "";

    if (sockfd < 0)
    {
        cerr << "Socket creation failed :(" << endl;
        cerr << "errno: " << strerror(errno) << endl;
    }
    

    struct sockaddr_in6 bind_address, client_addr;

    inet_pton(AF_INET6, argv[2], &bind_address.sin6_addr);
    bind_address.sin6_port = htons(port);
    bind_address.sin6_family = AF_INET6;


    if (bind(sockfd, (struct sockaddr*) &bind_address, sizeof(bind_address)) < 0) { // 2.
        cerr << "bind failed..." << endl;
        cerr << "Error: " << strerror(errno) << endl;
        cerr << "Bind address: " << argv[2] << " on port: " << argv[1] << endl; 
    } else {
        cout << "Binding successufl..." << endl;
    }


    if(listen(sockfd, 5) < 0) { // 3.
        cerr << "Listen call failed, errno below: " << endl;
        cerr << strerror(errno) << endl;
    } else {
        cout << "Server listening for connections..." << endl;
    }

    client_len = sizeof(client_addr);
    int newsockfd = accept(sockfd, (struct sockaddr*) &client_addr, &client_len); // 4.

    cout << "Client connected starting chat session." << endl;

    // Poll for input/output in a loop

    struct pollfd fds[4];
    int poll_ret;
    int poll_timeout = 500;
    
    fds[POLLSTD_IN].fd = STDIN_FILENO;
    fds[POLLSTD_IN].events = POLLIN;

    fds[POLLSTD_OUT].fd = STDOUT_FILENO;
    fds[POLLSTD_OUT].events = POLLOUT;

    fds[NETFD_IN].fd = newsockfd;
    fds[NETFD_IN].events = POLLIN;

    fds[NETFD_OUT].fd = newsockfd;
    fds[NETFD_OUT].events = POLLOUT;

    while(1) {
        if (fds[POLLSTD_IN].fd == -1 || fds[NETFD_IN].fd == -1)
        {
            cout << endl << "Connection terminated communications completed." << endl;
            break;
        }

        poll_ret = poll(fds, 4, poll_timeout);

        if(poll_ret == -1) {
            err(1, "polling error");
        }

        for(int i = 0; i < 4; ++i) {
            if (fds[i].revents & (POLLERR | POLLNVAL))
            {
                fds[i].fd = -1;
            } 
        }

        if(fds[POLLSTD_IN].revents & POLLIN) {
            fgets(buffer, 256, stdin);
            write_to_network(newsockfd, buffer);
        }

        if(fds[NETFD_IN].revents & POLLIN) {
            int n = read_from_network(newsockfd, buffer);
            if (n == 0) {
                cout << "Connection terminated..." << endl;
                break;
            }
        }


    }

    close(sockfd);
    close(newsockfd);

    return 0;
}