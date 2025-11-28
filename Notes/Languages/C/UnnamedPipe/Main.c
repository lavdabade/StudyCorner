#include <stdio.h>
#include <stdlib.h>     // required for pid_t
#include <unistd.h>     // required for close
#include <string.h>     // required for strlen

#define NAME_MAX_LEN 10

int main() {
    int pipe_fd[2];
    // 0th index for read
    // 1st index for write

    // creating pipe
    if(pipe(pipe_fd) == -1) {
        perror("Error: Error while creating pipe");
        return 1;
    }

    pid_t pid = fork();
    if(pid == -1) {
        perror("Error: Error while creating child process");
        return 1;
    }

    if(pid == 0) {
        // child process
        char name[NAME_MAX_LEN];
        close(pipe_fd[1]);
        read(pipe_fd[0], name, NAME_MAX_LEN);
        printf("\nINFO: Name: %s", name);
        printf("\nINFO: Child exiting...");
    }
    else {
        // parent process
        char name[NAME_MAX_LEN];
        close(pipe_fd[0]);
        printf("Enter Name: ");
        fgets(name, NAME_MAX_LEN, stdin);
        int len = strlen(name);
        name[len-1] = '\0';
        write(pipe_fd[1], name, len+1);
        printf("INFO: Parent exiting...");
    }

    return 0;
}