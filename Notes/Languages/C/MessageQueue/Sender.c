#include <stdio.h>      // required for printf, scanf, fgets
#include <stdlib.h>     // required for memset
#include <string.h>     // requred for strlen, strcmp
#include <sys/ipc.h>    // reqired for key_t, 
#include <sys/msg.h>    // required for msgget
#include "student.h"

struct msg_buffer {
    long mType;
    struct student data;
};

int main() {
    key_t key = ftok("tmpFile", 'A');
    int msg_fd = msgget(key, 0666 | IPC_CREAT);
    struct msg_buffer message;
    char msg[NAME_MAX_LEN];
    while(1) {
        memset(&message, 0, sizeof(message));
        printf("Enter Name of student: ");
        fgets(msg, NAME_MAX_LEN, stdin);
        int len = strlen(msg);
        msg[len-1] = '\0';
        printf("Enter Roll Number of student: ");
        int rollNo;
        scanf("%d", &rollNo);
        getchar();
        message.mType = 1;
        strcpy(message.data.name, msg);
        message.data.rollNo = rollNo;
        msgsnd(msg_fd, &message, sizeof(message) - sizeof(long), 0);
        printf("INFO: Message send -> %s\n", msg);

        if(strcmp(msg, "EXIT") == 0) {
            printf("INFO: Exiting");
            break;
        }
    }
    return 0;
}