#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <iostream>
#include <poll.h>
#include <err.h>

// Macros
#define POLLSTD_IN 0
#define POLLSTD_OUT 1
#define NETFD_IN 2
#define NETFD_OUT 3

using namespace std;

// Make a hello world client socket programming implementation here.

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

    int sockfd = socket(AF_INET6, SOCK_STREAM, 0);
    int port = stoi(argv[1]);
    char buffer[256];

    if (sockfd >= 0)
    {
        cout << "Socket successfully created! File Descriptor: " << sockfd << endl;
    } else {
        cerr << "Socket creation failed :(" << endl;
        cerr << "errno: " << errno << endl;
    }

    struct sockaddr_in6 bind_address;

    inet_pton(AF_INET6, argv[2], &bind_address.sin6_addr);
    bind_address.sin6_port = htons(port);
    bind_address.sin6_family = AF_INET6;

    cout << "Attempting to connect to " << argv[2] << " on port number " << argv[1] << endl;

    if (connect(sockfd, (struct sockaddr *) &bind_address, sizeof(bind_address)) < 0)
    {
        cerr << "Error connecting to server..." << endl;
        cerr << "Error no: " << strerror(errno) << endl;
    } else {
        cout << "Connection successful chat session opened!" << endl;
    }

    // Poll for input/output in a loop

    struct pollfd fds[4];
    int poll_ret;
    int poll_timeout = 500;
    
    fds[POLLSTD_IN].fd = STDIN_FILENO;
    fds[POLLSTD_IN].events = POLLIN;

    fds[POLLSTD_OUT].fd = STDOUT_FILENO;
    fds[POLLSTD_OUT].events = POLLOUT;

    fds[NETFD_IN].fd = sockfd;
    fds[NETFD_IN].events = POLLIN;

    fds[NETFD_OUT].fd = sockfd;
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
            if (fds[i].revents & (POLLERR | POLLNVAL | POLLHUP))
            {
                fds[i].fd = -1;
            } 
        }

        if(fds[POLLSTD_IN].revents & POLLIN) {
            fgets(buffer, 256, stdin);
            write_to_network(sockfd, buffer);
        }

        if(fds[NETFD_IN].revents & POLLIN) {
            int n = read_from_network(sockfd, buffer);
            if (n == 0) {
                cout << "Connection terminated..." << endl;
                break;
            }
        }
        
    }
    

    // strcpy(buffer, "Hello from client.");

    // int n = write(sockfd, buffer, strlen(buffer));

    // cout << "Bytes written: " << n << endl;

    // cout << "Attempted to write hello to server and exiting..." << endl;

    close(sockfd);

    return 0;
}