#include<iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<string.h>
#include<stdio.h>
#include<time.h>


using namespace std;

#define PORT 5555
#define MAXSIZE 100

int main(int argc,char * argv[]){
  
  int fd;
  struct sockaddr_in server;
  struct hostent *hp;
  int cnct;

  char buf[50]={' '};
  int ctr=0;

  server.sin_family=AF_INET;
  server.sin_port=htons(PORT);
  server.sin_addr.s_addr=INADDR_ANY;

  fd=socket(AF_INET,SOCK_STREAM,0);
  if(fd<0){
    cout<<"Error creating socket\n";
    return 0;
  }

  cout<<"Socket created\n";

  hp=gethostbyname(argv[1]);
  bcopy((char *)hp->h_addr,(char *)&server.sin_addr.s_addr,hp->h_length);

  cnct=connect(fd,(struct sockaddr*)&server,sizeof(server));

  if(cnct<0){
    cout<<"Error connecting\n";
    return 0;
  }
 
  cout<<"Connection has been made\n";
  recv(fd,buf,sizeof(buf),0);
  cout<< buf;

  close(fd);
  shutdown(fd,0);
  cout<<"Socket closed\n";

  return 0;
} 
