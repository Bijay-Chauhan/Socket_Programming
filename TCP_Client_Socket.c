#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

#define PORT 5000

int main()
{
    int sockfd;
    char buffer[100];

    struct sockaddr_in server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0)
    {
        printf("\nSocket connection failed");
        return 1;
    }

    printf("\nSocket connection successfully\n");

    memset(&server, 0, sizeof(server));

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(sockfd, (struct sockaddr *)&server,
            sizeof(struct sockaddr));

    printf("\nConnected to Server\n");

    while(1)
    {
        printf("\nClient: ");
        scanf(" %[^\n]", buffer);

        send(sockfd, buffer, strlen(buffer) + 1, 0);

        recv(sockfd, buffer, 100, 0);

        printf("\nServer: %s", buffer);
    }

    close(sockfd);

    return 0;
}