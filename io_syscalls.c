#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>

int main() {
    int fd;
    char buffer[100];

    if (access("demo.txt", F_OK) == 0)
        printf("File exists\n");
    else
        printf("File does not exist\n");

    if (access("demo.txt", R_OK) == 0)
        printf("Read permission available\n");
    else
        printf("Read permission NOT available\n");

    fd = open("demo.txt", O_CREAT | O_RDWR, 0644);

    write(fd, "Hello UNIX System Calls\n", 24);

    lseek(fd, 0, SEEK_SET);

    read(fd, buffer, 24);
    buffer[24] = '\0'; /* Null terminate string */
    printf("Data read: %s", buffer);

    struct stat info;
    stat("demo.txt", &info);
    printf("\nLast access time: %s", ctime(&info.st_atime));

    close(fd);
    return 0;
}
