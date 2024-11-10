/*
Ques-3.4 : Wap in TCP, Client will send an array of integers to the server. Server wil return the maximum, minimum, sum and 
average of the numbers to the Client and it will diplay the results on the client side.

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

    // Code for Receiving the array of numbers
    int n;
    recv(clientfd, &n, sizeof(int), 0);
    int arr[n];
    int bytes_received = recv(clientfd, arr, sizeof(arr), 0);
    if (bytes_received != sizeof(arr))
    {
        perror("Error receiving array");
        exit(1);
    }

    // Printing numbers received
    printf("Numbers Received from Client : ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    int max = arr[0], min = arr[0], sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
        sum += arr[i];
    }
    float avg = (float)sum / n;

    // Code for sending the results
    send(clientfd, &max, sizeof(max), 0);
    send(clientfd, &min, sizeof(min), 0);
    send(clientfd, &sum, sizeof(sum), 0);
    send(clientfd, &avg, sizeof(avg), 0);

    close(clientfd);
    close(sockfd);

    return 0;
}