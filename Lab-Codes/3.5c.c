/*
Ques 3.5 : Wap in TCP, Client will send a student structure having data members roll, name, marks to the server. Server will 
return the sum of the marks to the Client and it will display the results on the client side.
*/
/*Client Side*/ 

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
    printf("\n**Client Interface\n");
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    printf("The socket value is : %d\n", sockfd);

    if (sockfd == -1)
    {
        perror("\nSocket creation failed !\n");
        exit(0);
    }

    struct sockaddr_in server;
    server.sin_port = htons(5000);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    int c = connect(sockfd, (struct sockaddr *)&server, sizeof(server));
    if (c == -1)
    {
        perror("\nConnection error !\n");
        exit(0);
    }
    printf("\nSuccessfully connected !\n");

    struct student s;
    printf("\nEnter the roll number : ");
    scanf("%d", &s.roll);
    printf("\nEnter the name : ");
    scanf("%s", s.name);
    printf("\nEnter the marks of 6 subjects: ");
    for (int i = 0; i < 6; i++)
    {
        scanf("%d", &s.marks[i]);
    }

    // Code for sending the student structure
    send(sockfd, &s, sizeof(s), 0);
    
    // Code for receiving the sum of the marks
    int sum;
    recv(sockfd, &sum, sizeof(int), 0);
    
    // Printing the received sum
    printf("\nSum of the marks : %d\n", sum);
    
    close(sockfd);
    return 0;
}
