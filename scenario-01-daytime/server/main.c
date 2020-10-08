//
// Created by byun on 20. 10. 2..
//
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <time.h>

#define MAXLINE 4096
#define LISTENQ 1024

int main(int argc, char** argv) {
    int listenfd, connfd;
    struct sockaddr_in servaddr;
    time_t ticks;
    char buff[MAXLINE];

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(13);

    bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

    listen(listenfd, LISTENQ);

    for ( ; ; ) {
        connfd = accept(listenfd, (struct sockaddr *) NULL, NULL);
        ticks = time NULL;
        snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
        printf("[SUCCESS] %s", buff);
        write(connfd, buff, strlen(buff));
        close(connfd);
    }
}
