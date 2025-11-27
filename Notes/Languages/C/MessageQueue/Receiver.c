#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "student.h"
#include <string.h>

struct msg_buffer {
    long mType;
    struct student data;
};

int main() {
    key_t key = ftok("tmpFile", 'A');
    int msg_fd = msgget(key, 0666 | IPC_CREAT);
    struct msg_buffer message;
    while(1) {
        msgrcv(msg_fd, &message, sizeof(message)-sizeof(long), 1, 0);
        printf("INFO: Received Msg -> Name: %s  \tRollNo: %d\n", message.data.name, message.data.rollNo);
        if(strcmp(message.data.name, "EXIT") == 0) {
            printf("INFO: Exiting...");
            break;
        }
    }
    return 0;
}