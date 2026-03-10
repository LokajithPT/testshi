#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
void signal_handler(int sig){
printf("parent received signal from child (sginal number:%d)\\n",sig);
}
int main() {
pid_t pid;
signal(SIGUSR1,signal_handler);
pid=fork();
if(pid<0){
perror("fork failer");
exit(1);
}
else if(pid == 0){
sleep(2);
printf("child sending signal to parent...\\n");
kill(getpid(), SIGUSR1);
exit(0);
}
else
{
printf("parent waiting for signal ...\\n");
pause();
printf("parent process finished..\\n");
}
return 0;
}
