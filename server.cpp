//Chris Lucian & Chad Davies
//3/8/2015
//CS 537
//Programming Assignment 1 Web Server

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "WebServer.h"
#include "WebClient.h"
#include "rdt.h"
#include <pthread.h>
#include <string>
#include <iostream>
#include <fstream>
#include <boost/regex.hpp>
#include <boost/algorithm/string/regex.hpp>
#include <boost/algorithm/string.hpp>
#include <streambuf>
#include <vector>
#include <boost/lexical_cast.hpp>
#include <time.h>

using namespace std;

int main(int argc, char *argv[]) {

    int bufferLength = 512;
    struct sockaddr_in serverAddress, clientAddress;
    int sizeClientAddress = sizeof(clientAddress);
    char buffer[bufferLength];
    char message[bufferLength];

    // Validate the correct number of arguments have been passed to the server
    if (argc < 2) {
        fprintf(stderr,"Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);

    printf("beforesocket\n");
    int socketDescriptor = rdt_socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    printf("beforebindsocket\n");
    rdt_bind(socketDescriptor, (struct sockaddr*)&serverAddress, sizeof(clientAddress));
    printf("beforerecieve\n");
    rdt_recv(socketDescriptor, buffer, bufferLength, 0, (struct sockaddr *) &clientAddress, &sizeClientAddress);
    //printf("beforesendto\n");
    //rdt_sendto(socketDescriptor, message, strlen(message), 0, clientAddress, sizeClientAddress);
    printf("end\n");

    return 0;
}
