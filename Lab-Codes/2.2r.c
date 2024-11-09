#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main() {
    const char *receiver_ip = "127.0.0.1";  // IP address to bind the receiver
    int receiver_port = 8080;  // Port number to bind the receiver

    int sockfd;
    struct sockaddr_in receiver_addr, sender_addr;
    char buffer[BUFFER_SIZE];
    socklen_t sender_addr_len = sizeof(sender_addr);

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&receiver_addr, 0, sizeof(receiver_addr));
    receiver_addr.sin_family = AF_INET;
    receiver_addr.sin_port = htons(receiver_port);
    receiver_addr.sin_addr.s_addr = inet_addr(receiver_ip);

    if (bind(sockfd, (const struct sockaddr *)&receiver_addr, sizeof(receiver_addr)) < 0) {
        perror("bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    while (1) {
        int n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&sender_addr, &sender_addr_len);
        buffer[n] = '\0';
        printf("Received message: %s\n", buffer);

        if (strcmp(buffer, "exit") == 0) {
            printf("Receiver exiting...\n");
            break;
        }

        // Echo the message back to the sender
        sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&sender_addr, sender_addr_len);
    }

    close(sockfd);
    return 0;
}
