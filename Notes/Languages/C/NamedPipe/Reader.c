#include <stdio.h>
#include <fcntl.h>  // required for open, O_RDONLY
#include <unistd.h> // requred for read, close
#include <string.h> // required for strcmp

#define NAME_MAX_LEN 10

int main() {
    int fd = open("queue", O_RDONLY);
    if(fd < 0) {
        perror("ERROR: Unable to open queue");
        return 1;
    }
    while(1) {
        char name[NAME_MAX_LEN];
        read(fd, name, NAME_MAX_LEN);
        printf("INFO: Name: %s\n", name);
        if(strcmp(name, "EXIT") == 0) {
            printf("INFO: Exiting...");
            break;
        }
    }
    close(fd);
    return 0;
}