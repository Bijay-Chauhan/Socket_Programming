#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

#define PORT 5000

int main() {
        int sockfd;
        char buffer[100];
        struct sockaddr_in server;

        sockfd = socket(AF_INET, SOCK_DGRAM, 0);
        if(sockfd < 0) {
                printf("socket connection failed");
                return 1;
        }
        printf("\nSocket connection successfully\n");

        memset(&server, 0, sizeof(server));
        server.sin_family = AF_INET;
        server.sin_port = htons(PORT);
        inet_aton("127.0.0.1", &(server.sin_addr));

        int server_len = sizeof(struct sockaddr);
        while(1){
                printf("\nClient: ");
                scanf(" %[^\n]", buffer);
                sendto(sockfd, buffer, strlen(buffer) + 1, 0, (struct sockaddr *)&server, server_len);
                recvfrom(sockfd, buffer, 100, 0, (struct sockaddr *)&server, &server_len);
                printf("\nServer: %s \n", buffer);

        }
        close(sockfd);
return 0;

}

