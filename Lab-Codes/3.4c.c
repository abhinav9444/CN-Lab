/*
Ques 3.3 : Wap in TCP, Client will send an array of integers to the server. Server wil return the maximum, minimum, sum and 
average of the numbers to the Client and it will diplay the results on the client side.
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

    int n;
    printf("\nEnter the number of elements in the array : ");
    scanf("%d", &n);
    int arr[n];
    printf("\nEnter the elements of the array : ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Code for Sending the array of numbers
    send(sockfd, &n, sizeof(int), 0);
    send(sockfd, arr, sizeof(arr), 0);

    // Code for receiving the results
    int max, min, sum;
    float avg;
    recv(sockfd, &max, sizeof(int), 0);
    recv(sockfd, &min, sizeof(int), 0);
    recv(sockfd, &sum, sizeof(int), 0);
    recv(sockfd, &avg, sizeof(float), 0);

    // Printing the received results
    printf("\nMaximum of the array : %d\n", max);
    printf("Minimum of the array : %d\n", min);
    printf("Sum of the array : %d\n", sum);
    printf("Average of the array : %f\n", avg);

    close(sockfd);

    return 0;
}