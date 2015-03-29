//Chris Lucian & Chad Davies
//3/8/2015
//CS 537
//Programming Assignment 1 Web Server

#include <stdio.h>
#include <string.h>
#include "WebServer.h"
#include "WebClient.h"
#include "rdt.h"
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <time.h>
#include <stdlib.h> //exit(0);
#include <arpa/inet.h>
#include <sys/socket.h>

using namespace std;

int main(int argc, char *argv[]) {

    struct sockaddr_in serverAddress;
    char message[512];

    //Argument Validation
    if (argc < 3) {
       fprintf(stderr,"usage %s <hostname> <port>\n", argv[0]);
       exit(0);
    }

    //Assign the arguments to well-named variables
    string ipAddress = argv[1];
    int port = atoi(argv[2]);

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);

    serverAddress.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

    printf("CLIENT beforesocket\n");
    int socketDescriptor = rdt_socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    printf("CLIENT beforesend\n");
    int serverAddressLength = sizeof(serverAddress);
    rdt_sendto(socketDescriptor, message, strlen(message), 0,(struct sockaddr *) &serverAddress, serverAddressLength);
    printf("CLIENT sendto done\n");

    return 0;
}
