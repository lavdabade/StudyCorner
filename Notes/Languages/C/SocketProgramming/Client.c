#include <stdio.h>      // required for printf
#include <stdlib.h>     // required for EXIT_FAILURE
#include <arpa/inet.h>  // required for sockaddr_in structure
#include <sys/socket.h> // required for socket, connect, recv, close
#include <string.h>     // required for 
#include <unistd.h>     // required for close

#define PORT 8080
#define BUF_SIZE 1000

int main() {
    int client_fd;      // client file discriptor
    struct sockaddr_in server_addr;     // for server details
    char buffer[BUF_SIZE];      // to store outgoing messages from the client.

    printf("INFO: Socket creation started...\n");
    fflush(stdout);

    if((client_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
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

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    //    server_addr.sin_family = AF_INET;: Specifies the address family as IPv4.
    //    server_addr.sin_port = htons(PORT);: Converts the port number to network byte order.
    //    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");: Sets the server IP address.
    //        "127.0.0.1" is the loopback address (localhost).
    //        inet_addr() converts the string IP to a 32-bit network byte order format.

    if(connect(client_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("ERROR: Connect to server failed");
        close(client_fd);
        exit(EXIT_FAILURE);
    }

    printf("INFO: Connection Established...\n");
    fflush(stdout);


    while(1) {
        printf("Enter name of the student to be send: ");
        fgets(buffer, BUF_SIZE, stdin);
        int len = strlen(buffer);
        buffer[len-1] = '\0';
        if(strcmp(buffer, "EXIT") == 0) {
            printf("INFO: Done with the sending...\n");
            fflush(stdout);
            break;
        }
        if(send(client_fd, buffer, BUF_SIZE, 0) == -1) {
            perror("ERROR: Connect to server failed");
            break;
        }
    }
    /*
        | Flag         | Meaning                                                                    |
        | ------------ | -------------------------------------------------------------------------- |
        | 0            | Default behavior (blocking, normal send)                                   |
        | MSG_DONTWAIT | Non-blocking (return immediately if send would block)                      |
        | MSG_OOB      | Send out-of-band data (rarely used)                                        |
        | MSG_NOSIGNAL | Do not generate SIGPIPE if the peer has closed the connection (Linux only) |
    */

    close(client_fd);

    return 0;
}