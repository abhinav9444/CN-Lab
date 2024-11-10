/*
Ques-3.5 : Wap in TCP, Client will send a student structure having data members roll, name, marks to the server. Server will 
return the sum of the marks to the Client and it will display the results on the client side.

***Server Side***
*/ 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>

struct student
{
    int roll;
    char name[20];
    int marks[6];
};

int main()
{
    printf("\n**Server Interface\n");
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    printf("The socket value is : %d\n", sockfd);

    if (sockfd == -1)
    {
        perror("\nSocket creation failed !\n");
        exit(0);
    }

    struct sockaddr_in server, client;
    server.sin_port = htons(5000);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    int b = bind(sockfd, (struct sockaddr *)&server, sizeof(server));
    printf("value of bind = %d\n", b);

    if (b == -1)
    {
        perror("\nBind failed !\n");
        exit(0);
    }

    int l = listen(sockfd, 5);
    if (l == -1)
    {
        perror("\nListen problem !\n");
        exit(0);
    }
    else
    {
        printf("\nListen successful !\n");
    }

    int size = sizeof(client);
    int clientfd = accept(sockfd, (struct sockaddr *)&client, &size);

    if (clientfd == -1)
    {
        perror("\nNot connected to client !\n");
        exit(0);
    }
    printf("Clientfd is : %d \n", clientfd);

    // Code for receiving the student structure
    struct student s;
    recv(clientfd, &s, sizeof(s), 0);

    // Printing the received student structure
    printf("\nRoll : %d\n", s.roll);
    printf("Name : %s\n", s.name);
    printf("Marks : ");
    for(int i=0; i<6; i++)
    {
        printf("%d ", s.marks[i]);
    }
    printf("\n");
    // Code for sending the sum of marks
    int sum = 0;
    for(int i=0; i<6; i++)
    {
        sum += s.marks[i];
    }
    printf("Sum of marks sent to the client successfully !\n");
    send(clientfd, &sum, sizeof(int), 0);
    
    close(sockfd);
    return 0;
}
