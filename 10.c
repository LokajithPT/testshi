#include <stdio.h>
#include <unistd.h>
#include <signal.h>
int main() {
int pid = fork();
if (pid == 0) {
while (1) {
printf("Running...
");
sleep(1);
}
} else {
sleep(5);
kill(pid, SIGKILL);
printf("child ended.
");
}
return 0;
}
