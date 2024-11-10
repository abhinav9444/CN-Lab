/*
Ques-3.1 : WAP in TCP, client will send two numbers to server and server will calculate the sum. And send it back to the client, the client will display it.

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
	

	
	printf("\nEnter 2 numbers : ");
	int a,b;
	scanf("%d %d",&a,&b);
	//Code for Sending 2 numbers
	send(sockfd,&a,sizeof(int),0);
	send(sockfd,&b,sizeof(int),0);
	//Code for recieving the sum of sent 2 numbers
	int data2;
	recv(sockfd,&data2,sizeof(int),0);
	//printing the received sum
	printf("\nSum of the 2 number is : %d\n",data2);
	return 0;
}