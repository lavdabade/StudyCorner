#include <stdio.h>
#include <string.h>
#include <sys/shm.h>

#define NAME_MAX_LEN 10

int main() {
    char name[NAME_MAX_LEN];
    key_t key = ftok("tmpFile", 'A');
    int key_fd = shmget(key, 1024, 0666|IPC_CREAT);
    char *ch = shmat(key_fd, NULL, 0);
    printf("Enter Name: ");
    fgets(name, NAME_MAX_LEN, stdin);
    int len = strlen(name);
    name[len-1] = '\0';
    strcpy(ch, name);
    printf("Written Name: %s", name);
    shmdt(ch);
    return 0;
}