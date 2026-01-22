#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>

int main() {
    pid_t pid;
    struct stat fileStat;
    DIR *dir;
    struct dirent *entry;
    int fd;

    printf("Parent Process ID: %d\n", getpid());

    /* fork system call */
    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    /* Child process */
    if (pid == 0) {
        printf("\nChild Process\n");
        printf("Child PID: %d\n", getpid());

        /* exec system call */
        execlp("ls", "ls", "-l", NULL);

        /* exec returns only on error */
        perror("Exec failed");
        exit(1);
    }
    /* Parent process */
    else {
        wait(NULL); /* wait system call */
        printf("\nChild process finished execution.\n");

        /* stat system call */
        if (stat("unix_syscalls_demo.c", &fileStat) == 0) {
            printf("\nFile Size: %ld bytes\n", fileStat.st_size);
        } else {
            perror("stat failed");
        }

        /* opendir and readdir system calls */
        dir = opendir(".");
        if (dir == NULL) {
            perror("opendir failed");
            exit(1);
        }
        printf("\nDirectory Contents:\n");
        while ((entry = readdir(dir)) != NULL) {
            printf("%s\n", entry->d_name);
        }
        closedir(dir);

        /* open and close system calls */
        fd = open("temp.txt", O_CREAT | O_WRONLY, 0644);
        if (fd >= 0) {
            write(fd, "Hello UNIX\n", 11);
            close(fd); /* close system call */
            printf("\nFile temp.txt created and closed successfully.\n");
        }

        exit(0); /* exit system call */
    }

    return 0;
}
