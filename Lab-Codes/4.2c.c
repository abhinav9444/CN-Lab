/*
Ques-4.2 : WAP to create a chat server between client and server using TCP..

***Client Side***
*/ 

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
    printf("\n**Client Interface\n");
    int sockfd=socket(AF_INET,SOCK_STREAM,0);
    printf("The socket value is : %d\n",sockfd);
    
    if(sockfd==-1)
    {
        perror("\nSocket creation failed !\n");
        exit(0);
    }
    struct sockaddr_in server;
    server.sin_port=htons(5000);
    server.sin_family=AF_INET;
    server.sin_addr.s_addr=inet_addr("127.0.0.1");
    int c=connect(sockfd,(struct sockaddr*)&server,sizeof(server));
    if(c==-1)
    {
        perror("\nConnection failed !\n");
        exit(0);
    }
    else
    {
        printf("\nConnection successful !\n");
    }
    char str[100];
    while(1)
    {
        printf("Client : ");
        gets(str);
        send(sockfd,str,sizeof(str),0);
    }
    return 0;
}
