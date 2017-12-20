#include <sys/types.h>
#include <netinet/in.h>
#include <inttypes.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <strings.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#define routerport 15000
#define clientport 20000

int main(int argc, char *argv[])
{
  char buffer[1024];
  int socket_fd , fsize;
  struct sockaddr_in  router,client;
  socket_fd = socket (AF_INET, SOCK_DGRAM, 0);
  memset((char *) &router,0, sizeof(router));
  router.sin_family = (short)AF_INET;
  router.sin_addr.s_addr = htonl(INADDR_ANY);
  router.sin_port = routerport;
  memset((char *) &client,0, sizeof(client));
  client.sin_family = (short)AF_INET;
  client.sin_addr.s_addr = htonl(INADDR_ANY);
  client.sin_port = clientport;
  bind(socket_fd, (struct sockaddr *)&client, sizeof(client));
  while(1)
  {
    memset(buffer,0, 1024);
    fgets(buffer,1024,stdin);
    sendto(socket_fd,buffer,1024,0,(struct sockaddr *)&router,sizeof(router));
    if(!strcmp("exit\n",buffer))
    {
      printf("close the socket");
      close(socket_fd);
      break;
    }
    memset(buffer,0, 1024);
    fsize = sizeof(client);
    recvfrom(socket_fd,buffer,1024,0,(struct sockaddr *)&client,&fsize);
    if(!strcmp("exit\n",buffer))
    {
      printf("server close the socket");
      close(socket_fd);
      break;
    }
    else
      printf("%s\n",buffer); 
    }
    return 0;
}