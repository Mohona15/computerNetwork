#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#define MAXLINE 1024

int main(int argc, char **argv)
{
int sockfd;
int n;
int i,j,l;
char temp;
socklen_t len;
char msg[1024];
struct sockaddr_in servaddr,cliaddr;
sockfd=socket(AF_INET,SOCK_DGRAM,0);
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=INADDR_ANY;
servaddr.sin_port=htons(5035);
printf("\n\n Binded");
bind(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
printf("\n\nListening");
printf("\n");
len=sizeof(cliaddr);
n=recvfrom(sockfd,msg,MAXLINE,0,(struct sockaddr*)&cliaddr,&len);
printf("\nClient's Message : %s\n",msg);


        sendto(sockfd,msg,n,0,(struct sockaddr*)&cliaddr,len);

        return 0;
}