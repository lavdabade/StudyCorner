#include <stdio.h>      // requred for printf
#include <stdlib.h>     // required for EXIT_FAILURE
#include <string.h>     // required for memset
#include <unistd.h>     // required for close
#include <arpa/inet.h>  // required for sockaddr_in struct
#include <sys/socket.h> // required for socket, bind, listen, accept, recv, close

#define PORT 8080
#define BUF_SIZE 1000
#define MAX_PENDING_QUEUE_SIZE 5

int main() {
    int client_fd;      // client file discriptor
    int server_fd;      // server file discriptor
    struct sockaddr_in server_addr;     // for server details
    struct sockaddr_in client_addr;     // for client details
    socklen_t ddr_len = sizeof(client_addr);        // hold the size of the client_addr structure (needed when accepting connections).
    char buffer[BUF_SIZE];      // to store incoming messages from the client.
    
    printf("INFO: Socket creation started...\n");
    fflush(stdout);

    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("ERROR: Socket creation failed");
        exit(EXIT_FAILURE);
    }
    /*
        a. Address Family
            AF_INET → IPv4 addresses
            AF_INET6 → IPv6

        b. Socket Type
            SOCK_STREAM → stream-based, meaning it provides a reliable, connection-oriented
            SOCK_DGRAM → connection-less

        c. Protocol number.
            0 → default protocol for provided address family + socket type.

        For AF_INET + SOCK_STREAM, the default(0) is TCP.
        For AF_INET + SOCK_DGRAM, the default(0) is UDP.
    */

    printf("INFO: Socket created successfully...\n");
    fflush(stdout);

    server_addr.sin_family = AF_INET;       // Specifies that the server will use IPv4 addresses.
    server_addr.sin_addr.s_addr = INADDR_ANY;       // Specifies that the server will accept connections from any available network interface.
    server_addr.sin_port = htons(PORT);         // Specifies the port on which the server will listen for incoming connections. htons() is used to ensure the port number is in network byte order (big-endian).

    if(bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("ERROR: Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    // bind(): Associates the server socket (server_fd) with the specified IP address and port number (server_addr).
    // (struct sockaddr*) typecast is requred to cast from sockaddr_in to sockaddr

    printf("INFO: bind completed successfully...\n");
    fflush(stdout);

    if(listen(server_fd, MAX_PENDING_QUEUE_SIZE) == -1) {
        perror("ERROR: Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    // listen Puts the server socket into listening mode, where it waits for incoming client connections. 
    // The second argument specifies the backlog queue size (maximum number of pending connections).

    printf("INFO: Waiting for the connection...\n");
    fflush(stdout);

    socklen_t client_addr_len = sizeof(client_addr);
    if((client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_addr_len)) == -1) {
        perror("ERROR: Accept failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    // When accept() returns successfully 
    // client_addr is filled by the OS with the address of the client that just connected, it contains
    // client_addr.sin_family	Address family (AF_INET for IPv4)
    // client_addr.sin_port	Client’s source port (in network byte order)
    // client_addr.sin_addr	Client’s IP address

    printf("INFO: Connection established...\n");
    fflush(stdout);

    while(1) {
        memset(buffer, 0, BUF_SIZE);
        int recvRetVal = recv(client_fd, buffer, BUF_SIZE-1, 0);
        if(recvRetVal == -1) {
            perror("ERROR: Recv failed");
            break;
        }
        else if(recvRetVal == 0) {
            printf("INFO: Client disconnected\n");
            break;
        }
        printf("Received %s\n", buffer);
    }
    /*
        | Flag         | Meaning                                             |
        | ------------ | --------------------------------------------------- |
        | 0            | Default behavior (blocking, normal receive)         |
        | MSG_DONTWAIT | Non-blocking (return immediately if no data)        |
        | MSG_PEEK     | Look at the data without removing it from the queue |
        | MSG_WAITALL  | Wait until the full requested length is received    |
    */

    close(client_fd);
    close(server_fd);
    return 0;
}