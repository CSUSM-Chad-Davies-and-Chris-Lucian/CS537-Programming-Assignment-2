#include "rdt.h"
#include <errno.h>

int rdt_socket(int address_family, int type, int protocol)
{
  int socketDescriptor = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  if (socketDescriptor == -1)
    {
        printf("RDT Socket Could not be created.\n");
    }
  return socketDescriptor;
}

int rdt_bind(int socket_descriptor,const struct sockaddr *local_address,socklen_t address_length)
{
  int bindSuccess = bind(socket_descriptor , local_address, address_length);
  if(bindSuccess == -1)
    {
        printf("RDT Socket could not be bound.\n");
    }
  return bindSuccess;
}

int get_num_packets(int buffer_length)
{
  int num_packets = buffer_length / PACKET_DATA_SIZE;
  if(buffer_length % PACKET_DATA_SIZE != 0)
  {
    num_packets++;
  }
  return num_packets;
}

int rdt_recv(int socket_descriptor,char *buffer, int buffer_length, int flags, struct sockaddr *from_address, int *address_length)
{
    //Get number of packets to recieve
    int num_packets = get_num_packets(buffer_length);

    //Create array of packets
    packet* packets = new packet[num_packets];

    //Load data into packets
    for(int i = 0; i < num_packets; i++)
    {
      char local_buffer[PACKET_SIZE];
      int recieveLength = recvfrom(socket_descriptor, local_buffer, PACKET_SIZE, flags, from_address, (socklen_t*)address_length);
      if (recieveLength == -1)
      {
        printf("RDT Reieved Failed.\n");
        return recieveLength;
      }

      memcpy(&packets[i], local_buffer, PACKET_SIZE);

      //transfer the packet data into the buffer
      for(int d = 0; d < PACKET_DATA_SIZE; d++)
      {
        int data_index = i * PACKET_DATA_SIZE + d;
        if(data_index > buffer_length)
        {
          buffer[data_index];
        }
      }
    }

  printf("RDT Recieve %d\n" , sizeof(struct packet));

  return buffer_length;
}

int rdt_sendto(int socket_descriptor,char *buffer,int buffer_length,int flags,struct sockaddr * destination_address,int address_length)
{
  //Get Number of packets to send
  int num_packets = get_num_packets(buffer_length);

  //Create array of packets to send
  packet* packets = new packet[num_packets];

  //Fill packet array with data
  for(int i = 0; i < num_packets; i++)
  {
    for(int d = 0; d < PACKET_DATA_SIZE; d++)
    {
      int data_index = i * PACKET_DATA_SIZE + d;
      if(data_index > buffer_length)
      {
        packets[i].data[d] = buffer[data_index];
      }
    }
  }

  //Send packets
  for(int i = 0; i < num_packets; i++)
  {
    int errno;
    int sendToSuccess = sendto(socket_descriptor, (void *)packets[i].data, PACKET_DATA_SIZE, flags, destination_address, address_length);
    printf("RDT sendto: %d, %i\n", sendToSuccess, errno);
    if (sendToSuccess == -1)
    {
        printf("RDT Couldn't be sent.\n");
    }
  }
  return buffer_length;
}

int close(int fildes)
{
  printf("RDT close");
  return 0;
}
