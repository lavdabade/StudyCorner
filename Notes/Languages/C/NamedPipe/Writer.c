#include <stdio.h>
#include <fcntl.h>  // required for open, O_WRONLY
#include <unistd.h> // required for write, close
#include <string.h> // required for strlen


#define NAME_MAX_LEN 10

int main() {
    int fd = open("queue", O_WRONLY);
    if(fd < 0) {
        perror("ERROR: Unable to open queue");
        return 1;
    }
    while(1) {
        char name[NAME_MAX_LEN];
        printf("Enter Name: ");
        fflush(stdout);
        fgets(name, NAME_MAX_LEN, stdin);
        int len = strlen(name);
        name[len-1]='\0';
        write(fd, name, len+1);
        printf("Written name: %s\n", name);
        fflush(stdout);
        if(strcmp(name, "EXIT") == 0) {
            printf("INFO: Exiting...");
            fflush(stdout);
            break;
        }
    }
    close(fd);
    return 0;
}