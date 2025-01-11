#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <string.h>

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
    }

    if(listen(sockfd, 5) < 0) { // 3.
        cerr << "Listen call failed, errno below: " << endl;
        cerr << strerror(errno) << endl;
    }

    client_len = sizeof(client_addr);
    int newsockfd = accept(sockfd, (struct sockaddr*) &client_addr, &client_len); // 4.

    int n = read(newsockfd, buffer, 255); // 4.

    cout << "Number of bytes read: " << n << endl;

    cout << "Client: " << buffer << endl;

    cout << "Received a message from the client terminating connection now..." << endl;

    close(sockfd);
    close(newsockfd);

    return 0;
}