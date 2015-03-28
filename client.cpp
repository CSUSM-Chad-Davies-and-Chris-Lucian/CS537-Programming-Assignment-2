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
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <time.h>

using namespace std;

int main(int argc, char *argv[]) {

    //Argument Validation
    if (argc < 3) {
       fprintf(stderr,"usage %s <hostname> <port>\n", argv[0]);
       exit(0);
    }

    //Assign the arguments to well-named variables
    string ipAddress = argv[1];
    string portNumber = argv[2];


    return 0;
}
