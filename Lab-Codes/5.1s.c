/*
Ques-5.1 : WAP in UDP in which sender sends two numbers to the receiver and receiver sends back the sum of the numbers to the 
sender and diplay it.

***Sender Side***
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
    printf("\n**Sender Interface\n");
    int sockfd=socket(AF_INET,SOCK_DGRAM,0);
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
    char str[100];
    printf("Enter two numbers : ");
    gets(str);
    int s=sendto(sockfd,str,sizeof(str),0,(struct sockaddr*)&server,sizeof(server));
    if(s==-1)
    {
        perror("\nSend failed !\n");
        exit(0);
    }
    else
    {
        printf("Numbers sent !\n");
    }
    int size=sizeof(server);
    char sumstr[100];
    int n=recvfrom(sockfd,sumstr,sizeof(sumstr),0,(struct sockaddr*)&server,&size);
    if(n==-1)
    {
        perror("\nReceive failed !\n");
        exit(0);
    }
    else
    {
        printf("Sum : %s\n",sumstr);
    }
    return 0;
}