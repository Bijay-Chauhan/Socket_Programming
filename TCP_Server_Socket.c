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
    int sockfd, newsockfd;
    char buffer[100];
    struct sockaddr_in my_addr;
    struct sockaddr_in client;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
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
    listen(sockfd, 5);
    int len = sizeof(struct sockaddr);
    newsockfd = accept(sockfd, (struct sockaddr *)&client, &len);
    printf("\nClient connected\n");
    while(1)
    {
        recv(newsockfd, buffer, 100, 0);
        printf("\nClient: %s", buffer);
        printf("\nServer: ");
        scanf(" %[^\n]", buffer);
        send(newsockfd, buffer, strlen(buffer) + 1, 0);
    }
    close(newsockfd);
    close(sockfd);

    return 0;
}

