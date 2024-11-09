/*
Ques 3.3 : Wap in TCP, Client will send a number to server. Server will check if it is armstrong no or not. Return confirmation to client. Client will display whether Armstrong or not. 
*/
/*Server Side*/ 
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<sys/types.h>

int IfArmstrong(int num);

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

	//Code for Recieving the number
	int a;
	recv(clientfd,&a,sizeof(int),0);
	//Printing numbers received and checking if its a Armstrong number 
 	printf("Numbers Recieved from Client is : %d\n",a);
 	int result=IfArmstrong(a);
	//Code for sending the result
	send(clientfd,&result,sizeof(result),0);
	return 0;
}

int IfArmstrong(int num)
{
    int originalNum, remainder, n = 0;
    double result = 0.0;
    originalNum = num;
    // Finding the number of digits
    while (originalNum != 0) {
        originalNum /= 10;
        ++n;
    }
    originalNum = num;
    // Calculate the sum of the nth power of each digit
    while (originalNum != 0) {
        remainder = originalNum % 10;
        result += pow(remainder, n);
        originalNum /= 10;
    }
    // Check if the number is an Armstrong number
    if ((int)result == num)
        return 1;
    else
        return 0;
}