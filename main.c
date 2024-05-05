#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 3000

void server_shutdown(int server_fd){
    printf("Shutting down server...\n");
    shutdown(server_fd, SHUT_RDWR);
}

int main(int argc, char **argv){

    // create a socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    // specify address and port
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // bind address and port to socket
    if(bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0){
        fprintf(stderr, "Error binding address and port to socket!/n");
        server_shutdown(server_fd);
    }

    return 0;
}