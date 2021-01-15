#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include  <netdb.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#define MAXLINE 1024

int main(int argc, char **argv)
{
int sockfd;
int n;
socklen_t len;
char sendline[1024],recvline[1024];
struct sockaddr_in servaddr;
strcpy(sendline,"");
printf("\nEnter the string : ");
fgets(sendline,1024,stdin);
sockfd=socket(AF_INET,SOCK_DGRAM,0);
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
servaddr.sin_port=htons(5035);
len=sizeof(servaddr);
sendto(sockfd,sendline,MAXLINE,0,(struct sockaddr*)&servaddr,len);
n=recvfrom(sockfd,recvline,MAXLINE,0,NULL,NULL);
recvline[n]=0;
printf("\n echo: %s\n\n",recvline);
return 0;
}