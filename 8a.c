#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
pid_t pid = fork();
if (pid < 0) {
perror("Fork failed");
exit(1);
} else if (pid == 0) {
printf("Child process exiting...
");
exit(0);
} else {
sleep(10);
printf("Parent process exiting after sleep...
");
}
return 0;
}
