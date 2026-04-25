#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }
    printf("Socket fd = %d\n", sockfd);
    struct sockaddr_in addr = {0};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(8080);
    if (bind(sockfd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("bind");
        close(sockfd);
        return 1;
    }
    if (listen(sockfd, 5) < 0) {
        perror("listen");
        close(sockfd);
        return 1;
    }
    printf("Listening on port 8080...\n");
    int connfd = accept(sockfd, NULL, NULL);
    if (connfd < 0) {
        perror("accept");
        close(sockfd);
        return 1;
    }
    char buf[256] = {0};
    recv(connfd, buf, sizeof(buf), 0);
    printf("Received: %s\n", buf);
    send(connfd, "ACK\n", 4, 0);
    close(connfd);
    close(sockfd);
    return 0;
}