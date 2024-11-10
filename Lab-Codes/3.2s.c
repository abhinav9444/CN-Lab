/*
Ques-3.2 : WAP in TCP, client will send two numbers to server and server will swap it. And send it back to the client, the client
will display it.

***Server Side***
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
	printf("\n**Server Interface\n");
	int sockfd=socket(AF_INET,SOCK_STREAM,0);
	printf("The socket value is : %d\n",sockfd);
	
	if(sockfd==-1)
	{
		perror("\nSocket creation failed !\n");
		exit(0);
	}
	struct sockaddr_in server,client;
	server.sin_port=htons(5000);
	server.sin_family=AF_INET;
	server.sin_addr.s_addr=inet_addr("127.0.0.1");
	
	int b=bind(sockfd,(struct sockaddr*)&server,sizeof(server));
	printf("value of bind = %d\n",b);
	
	if(b==-1)
	{
		printf("\nError !\n");
	}
	int l=listen(sockfd,5);
	if(l==-1)
	{
		perror("\nListen problem !\n");
	}
	else
	{
		printf("\nListen successful !\n");
	}
	
	int size=sizeof(client);
	int clientfd=accept(sockfd,(struct sockaddr*)&client,&size);
	
	if(clientfd==-1){
	perror("\nNot connected to client !\n");
	exit(0);
	}
	printf("Clientfd is : %d \n",clientfd);

	//Code for Recieving two numbers
	int a,b1;
	recv(clientfd,&a,sizeof(int),0);
	recv(clientfd,&b1,sizeof(int),0);
	//Printing numbers received
 	printf("Numbers Recieved from Client (a,b) is : %d   %d\n",a,b1);
	int temp;
	//Swapping the two numbers
	temp=a;
	a=b1;
	b1=temp;
	//Code for sending the swapped numbers
	send(clientfd,&a,sizeof(a),0);
	send(clientfd,&b1,sizeof(b1),0);
	return 0;
}