//Chris Lucian & Chad Davies
//3/8/2015
//CS 537
//Programming Assignment 1 Web Server

#include <stdio.h>
#include <string.h>
//#include <sys/socket.h>
//#include <arpa/inet.h>
#include "rdt.h"
///#include <pthread.h>
#include <string>
#include <iostream>
#include <fstream>
//#include <boost/regex.hpp>
//#include <boost/algorithm/string/regex.hpp>
//#include <boost/algorithm/string.hpp>
//#include <streambuf>
//#include <vector>
//#include <boost/lexical_cast.hpp>
//#include <time.h>

using namespace std;

int main(int argc, char *argv[]) {

    int bufferLength = 1050;
    // int bufferLength = 36;
    struct sockaddr_in serverAddress, clientAddress;
    int sizeClientAddress = sizeof(clientAddress);
    char buffer[bufferLength];

    // Validate the correct number of arguments have been passed to the server
    if (argc < 2) {
        fprintf(stderr,"Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);

    printf("SERVER beforesocket\n");
    int socketDescriptor = rdt_socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    printf("SERVER beforebindsocket\n");
    rdt_bind(socketDescriptor, (struct sockaddr*)&serverAddress, sizeof(clientAddress));
    printf("SERVER beforerecieve\n");
    rdt_recv(socketDescriptor, buffer, bufferLength, 0, (struct sockaddr *) &clientAddress, &sizeClientAddress);
    printf("SERVER Recieved %s\n" , buffer );

    printf("SERVER afterrecieve\n");

    return 0;
}
