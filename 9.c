#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
int main() {
int shmid = shmget(1234, 100, 0666 | IPC_CREAT);
char *data = shmat(shmid, NULL, 0);
if (fork() == 0) {
sleep(1);
printf("Child read: %s
", data);
} else {
sprintf(data, "Hello IPC");
printf("Parent wrote
");
}
return 0;
}
