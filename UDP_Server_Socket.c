#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

#define PORT 5000

int main() {
        int sockfd;
        char buffer[100];
        struct sockaddr_in my_addr;
        struct sockaddr_in client;

        sockfd = socket(AF_INET, SOCK_DGRAM, 0);
        if(sockfd < 0 ){
                printf("\nSocket connection failed");
                return 1;
        }
        printf("\nSocket connection successfully\n");

        memset(&my_addr, 0, sizeof(my_addr));
        my_addr.sin_family = AF_INET;
        my_addr.sin_port = htons(PORT);
        my_addr.sin_addr.s_addr = INADDR_ANY;

        bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr));

        printf("\nServer is waiting....\n");

        int len = sizeof(struct sockaddr);

        while(1){
                recvfrom(sockfd, buffer, 100, 0, (struct sockaddr *)&client, &len);
                printf("\nClient: %s ", buffer);
                printf("\nServer: ");
                scanf(" %[^\n]", buffer);
                sendto(sockfd, buffer, strlen(buffer) + 1, 0, (struct sockaddr *)&client, len);
        }
        close(sockfd);
return 0;
}
