#include <sys/types.h>
#include <netinet/in.h>
#include <inttypes.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <strings.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define routerport 15000
#define clientport 20000
#define serverport 25000



int main(int argc, char *argv[])
{
  char buffer[1024];
  int socket_fd, fsize;
  double x , random;
  time_t t;
  srand((unsigned) time(&t));
  sscanf(argv[1],"%lf",&x);
  struct sockaddr_in  router, client , server ,from;
  socket_fd = socket (AF_INET, SOCK_DGRAM, 0);
  memset((char *) &server,0, sizeof(server));
  server.sin_family = (short)AF_INET;
  server.sin_addr.s_addr = htonl(INADDR_ANY);
  server.sin_port = serverport;
  memset((char *) &router,0, sizeof(router));
  router.sin_family = (short)AF_INET;
  router.sin_addr.s_addr = htonl(INADDR_ANY);
  router.sin_port = routerport;
  memset((char *) &client,0, sizeof(client));
  client.sin_family = (short)AF_INET;
  client.sin_addr.s_addr = htonl(INADDR_ANY);
  client.sin_port = clientport;
  bind(socket_fd, (struct sockaddr *)&router, sizeof(router));
  while(1)
  {
    fsize = sizeof(from);
    recvfrom(socket_fd,buffer,1024,0,(struct sockaddr *)&from,&fsize);
    if(from.sin_port == clientport)
    {
      random = (double)rand() / (double)RAND_MAX ;
      if(!strcmp("exit\n",buffer))
      {
        sendto(socket_fd,buffer,1024,0,(struct sockaddr *)&server,sizeof(server));
        close(socket_fd);
        break;
      }
      else if(random > x )
        sendto(socket_fd,buffer,1024,0,(struct sockaddr *)&server,sizeof(server));
      else
      {
        memset(buffer,0,sizeof(buffer));
        sendto(socket_fd,buffer,1024,0,(struct sockaddr *)&client,sizeof(client));
      }
    }
    else if(!strcmp("exit\n",buffer))
    {
      sendto(socket_fd,buffer,1024,0,(struct sockaddr *)&client,sizeof(client));
      close(socket_fd);
      break;
    }
    else
      sendto(socket_fd,buffer,1024,0,(struct sockaddr *)&client,sizeof(client));
  
    }
    return 0;
}
