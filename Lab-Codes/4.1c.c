/*
Ques-4.1 : WAP in TCP for multiple clients. when one client connects to server, it will send clients their serial number.

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
    if(c==-1){
    perror("\nConnection error !\n");
    exit(0);
    }
    printf("\nSuccessfully connected !\n");

    int data1;
    recv(sockfd,&data1,sizeof(int),0);
    printf("\nSerial Number : %d\n",data1);
    return 0;
}
