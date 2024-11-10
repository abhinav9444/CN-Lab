/*
Ques-3.3 : Wap in TCP, Client will send a number to server. Server will check if it is armstrong no or not. Return confirmation 
to client. Client will display whether Armstrong or not. 

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
	

	
	printf("\nEnter a number : ");
	int a;
	scanf("%d",&a);
	//Code for Sending a number
	send(sockfd,&a,sizeof(int),0);
	//Code for recieving the result if its armstrong number or not.
	int data1;
	recv(sockfd,&data1,sizeof(int),0);
	//printing the received result
	if(data1==0)
		printf("\nNot an Armstrong Number\n");
	else if(data1==1)
		printf("\nIt is an Armstrong Number\n");
	else
		printf("Error in data received !\n");
	return 0;
}