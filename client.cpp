#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <iostream>

using namespace std;

// Make a hello world client socket programming implementation here.

int main(int argc, char* argv[]) {

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    int port = stoi(argv[1]);
    char buffer[256];

    if (sockfd >= 0)
    {
        cout << "Socket successfully created! File Descriptor: " << sockfd << endl;
    } else {
        cerr << "Socket creation failed :(" << endl;
        cerr << "errno: " << errno << endl;
    }

    struct sockaddr_in bind_address;

    bind_address.sin_addr.s_addr = inet_addr(argv[2]);
    bind_address.sin_port = htons(port);
    bind_address.sin_family = AF_INET;

    cout << "Attempting to connect to " << argv[2] << " on port number " << argv[1] << endl;

    if (connect(sockfd, (struct sockaddr *) &bind_address, sizeof(bind_address)) < 0)
    {
        cerr << "Error connecting to server..." << endl;
        cerr << "Error no: " << strerror(errno) << endl;
    }
    

    strcpy(buffer, "Hello from client.");

    int n = write(sockfd, buffer, strlen(buffer));

    cout << "Bytes written: " << n << endl;

    cout << "Attempted to write hello to server and exiting..." << endl;

    close(sockfd);

    return 0;
}