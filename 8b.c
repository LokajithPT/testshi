#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
pid_t pid = fork();
if (pid < 0) {
perror("Fork failed");
exit(1);
} else if (pid == 0) {
sleep(5);
printf("Child process is now orphaned. Parent PID: %d
", getppid());
} else {
printf("Parent process exiting...
");
exit(0);
}
return 0;
}
