//Commenting some ifs while sending will make it multicasting

#include<iostream>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netdb.h>
#include<time.h>
#include<stdio.h>

using namespace std;

#define PORT 5555
#define BACKLOG 5

int main(){
  
  int fd,fd1,fd2,fd3,fd4,fd5;
  //Instead of having integers,we can have an array of file descriptors and that's how the internet works
  //each accept returns a unique integer value hence we can distinguish a client based on the integer values
  int bnd,lstn;
  char buf[50]={' '};  
  struct sockaddr_in server,client;
  int ctr=0;
  time_t t;
  
  fd=socket(AF_INET,SOCK_STREAM,0);
  if(fd<0){
    cout<<"Error creating socket\n";
    return 0;
  }
  cout<<"Socket created\n";

  server.sin_family=AF_INET;
  server.sin_port=htons(PORT);
  server.sin_addr.s_addr=INADDR_ANY;
  
  
  bnd=bind(fd,(struct sockaddr *)&server,sizeof(server));
  if(bnd<0){
    cout<<"Error binding\n";
    return 0;
  }
  
  lstn=listen(fd,BACKLOG);
  if(lstn<0){
    cout<<"Error listening\n";
    return 0;
  }
  
  cout<<"Server is listening\n";
  
  while(ctr<5){
    if(ctr==0){
      socklen_t len=sizeof(client);
      fd1=accept(fd,(struct sockaddr*)&client,&len);
      if(fd1<0){
	cout<<"Error accepting\n";
	return 0;
      }
    }
    else if(ctr==1){
      socklen_t len=sizeof(client);
      fd2=accept(fd,(struct sockaddr*)&client,&len);
      if(fd2<0){
	cout<<"Error accepting\n";
	return 0;
      }
    }
    else if(ctr==2){
      socklen_t len=sizeof(client);
      fd3=accept(fd,(struct sockaddr*)&client,&len);
      if(fd3<0){
	cout<<"Error accepting\n";
	return 0;
      }
      }
    else if(ctr==3){
      socklen_t len=sizeof(client);
      fd4=accept(fd,(struct sockaddr*)&client,&len);
      if(fd4<0){
	cout<<"Error accepting\n";
	return 0;
      }
    }
    else if(ctr==4){
      socklen_t len=sizeof(client);
      fd5=accept(fd,(struct sockaddr*)&client,&len);
      if(fd5<0){
	cout<<"Error accepting\n";
	return 0;
      }
      }
    ctr++;
  }

    ctr=0;
    t=time(NULL);
    snprintf(buf,sizeof(buf),ctime(&t));
    while(ctr<5)
     {
	if(ctr==0){
	  send(fd1,buf,sizeof(buf),0);
	}
	else if(ctr==1){
	  send(fd2,buf,sizeof(buf),0);
	}
	else if(ctr==2)
	  {
	    send(fd3,buf,sizeof(buf),0);
	  }
	else if(ctr==3){
	  send(fd4,buf,sizeof(buf),0);
	}
	else if(ctr==4){
	  send(fd5,buf,sizeof(buf),0);
	}
	ctr++;
      }
  
  close(fd1);
  close(fd2);
  shutdown(fd1,0);
  shutdown(fd2,0);
  
  return 0;
}
