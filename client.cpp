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

    string message_string = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Morbi hendrerit erat a nunc facilisis varius. Sed lectus mi, egestas eget auctor eu, elementum eget justo. Mauris lacinia viverra mi, at pretium ante iaculis bibendum. Interdum et malesuada fames ac ante ipsum primis in faucibus. Vestibulum condimentum lobortis justo id varius. Mauris quis mi lorem. Interdum et malesuada fames ac ante ipsum primis in faucibus. Vivamus sed sagittis diam. Aenean elementum elementum massa at sagittis. Suspendisse euismod magna ut pulvinar tempor. Morbi ultricies enim eros, non feugiat neque sollicitudin sed. Mauris nec viverra neque.Nulla facilisi. Quisque pharetra pellentesque tristique. Phasellus et lectus ac lacus elementum lacinia ac ut nisi. Vivamus ornare purus vulputate, aliquam risus nec, facilisis metus. Donec eu elit et diam dignissim placerat euismod a lorem. Nullam sed neque consectetur, tristique tellus ac, molestie ex. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur semper hendrerit ligula, nec convallis est nullam.";
    // string message_string = "Hello Wolds I am here to be awesome.";
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
    printf("CLIENT Sending string length %d\n", strlen(message_string.c_str()));
    rdt_sendto(socketDescriptor, const_cast<char*>(message_string.c_str()), strlen(message_string.c_str()), 0,(struct sockaddr *) &serverAddress, serverAddressLength);
    printf("CLIENT sendto done\n");

    return 0;
}
