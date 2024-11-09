#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main() {
    const char *receiver_ip = "127.0.0.1";  // IP address of the receiver
    int receiver_port = 8080;  // Port number of the receiver

    int sockfd;
    struct sockaddr_in receiver_addr;
    char buffer[BUFFER_SIZE];

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&receiver_addr, 0, sizeof(receiver_addr));
    receiver_addr.sin_family = AF_INET;
    receiver_addr.sin_port = htons(receiver_port);
    receiver_addr.sin_addr.s_addr = inet_addr(receiver_ip);

    while (1) {
        printf("Enter message: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';  // Remove trailing newline

        sendto(sockfd, buffer, strlen(buffer), 0, (const struct sockaddr *)&receiver_addr, sizeof(receiver_addr));

        if (strcmp(buffer, "exit") == 0) {
            printf("Sender exiting...\n");
            break;
        }
    }

    close(sockfd);
    return 0;
}
