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
#define serverport 25000

int main(int argc, char *argv[])
{
  char buffer[1024];
  memset(buffer,0, 1024);
  int socket_fd , fsize;
  struct sockaddr_in  router,server;
  socket_fd = socket (AF_INET, SOCK_DGRAM, 0);

  memset((char *) &router,0, sizeof(router));
  router.sin_family = (short)AF_INET;
  router.sin_addr.s_addr = htonl(INADDR_ANY);
  router.sin_port = routerport;

  memset((char *) &server,0, sizeof(server));
  server.sin_family = (short)AF_INET;
  server.sin_addr.s_addr = htonl(INADDR_ANY);
  server.sin_port = serverport;
  
  bind(socket_fd, (struct sockaddr *)&server, sizeof(server));
  while(1)
  {
    fsize = sizeof(server);
    recvfrom(socket_fd,buffer,1024,0,(struct sockaddr *)&server,&fsize);
    if(!strcmp("exit\n",buffer))
    {
      printf("client close the socket");
      close(socket_fd);
      break;
    }
    else
      printf("%s\n",buffer);
    memset(buffer,0, 1024);
    fgets(buffer,1024,stdin);
    sendto(socket_fd,buffer,1024,0,(struct sockaddr *)&router,sizeof(router));
    if(!strcmp("exit\n",buffer))
    {
      printf("close the socket");
      close(socket_fd);
      break;
    }
  }
  return 0;
}