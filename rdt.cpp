int rdt_socket(int address_family, int type, int protocol)
{
  printf("rdt_socket");
  return 0;
}

int rdt_bind(int socket_descriptor,const struct sockaddr *local_address,socklen_t address_length)
{
  printf("rdt_bind");
  return 0;
}

int rdt_recv(int socket_descriptor,char *buffer, int buffer_length, int flags, struct sockaddr *from_address, int *address_length)
{
  printf("rdt_recv");
  return 0;
}

int rdt_sendto(int socket_descriptor,char *buffer,int buffer_length,int flags,struct sockaddr *destination_address,int address_length)
{
  printf("rdt_sendto");
  return 0;
}

int close(int fildes)
{
  printf("close");
  return 0;
}
