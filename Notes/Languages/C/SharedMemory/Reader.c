#include <stdio.h>
#include <sys/shm.h>

int main() {
    key_t key = ftok("tmpFile", 'A');
    int key_fd = shmget(key, 1024, 0666|IPC_CREAT);
    char *ch = shmat(key_fd, NULL, SHM_RDONLY);
    printf("Name: %s", ch);
    shmdt(ch);
    shmctl(key_fd, IPC_RMID, NULL);
    return 0;
}