#include <stdio.h>
#include <sys/stat.h>   // required for mkfifo

int main() {
    const char *queue = "queue";
    printf("INFO: Creating queue...");
    if(mkfifo(queue, 0666) == -1) {
        perror("ERROR: Unable to create queue");
        return 1;
    }
    printf("\nINFO: Queue created sucessfully...");
    return 0;
}