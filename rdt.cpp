#include "rdt.h"
#include <errno.h>

int rdt_socket(int address_family, int type, int protocol)
{
  int socketDescriptor = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  if (socketDescriptor == -1)
    {
        printf("Socket Could not be created.\n");
    }
  return socketDescriptor;
}

int rdt_bind(int socket_descriptor,const struct sockaddr *local_address,socklen_t address_length)
{
  int bindSuccess = bind(socket_descriptor , local_address, address_length);
  if(bindSuccess == -1)
    {
        printf("Socket could not be bound.\n");
    }
  return bindSuccess;
}

int rdt_recv(int socket_descriptor,char *buffer, int buffer_length, int flags, struct sockaddr *from_address, int *address_length)
{
  int recieveLength = recvfrom(socket_descriptor, buffer, buffer_length, flags, from_address, (socklen_t*)address_length);
  if (recieveLength == -1)
        {
          printf("Reieved Failed.\n");
        }

  return recieveLength;
}

int rdt_sendto(int socket_descriptor,char *buffer,int buffer_length,int flags,struct sockaddr * destination_address,int address_length)
{
  int errno;
  int sendToSuccess = sendto(socket_descriptor, (void *)buffer, buffer_length, flags, destination_address, address_length);
  printf("sendto: %d, %i\n", sendToSuccess, errno);
  if (sendToSuccess == -1)
        {
            printf("Couldn't be sent.\n");
        }
  return sendToSuccess;
}

int close(int fildes)
{
  printf("close");
  return 0;
}
