#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>

int main() {
    int fd;
    char buffer[100];

    /* Check file existence */
    if (access("demo.txt", F_OK) == 0)
        printf("File exists\n");
    else
        printf("File does not exist\n");

    /* Check read permission */
    if (access("demo.txt", R_OK) == 0)
        printf("Read permission available\n");
    else
        printf("Read permission NOT available\n");

    /* Open or create file */
    fd = open("demo.txt", O_CREAT | O_RDWR, 0644);

    /* Write to file */
    write(fd, "Hello UNIX System Calls\n", 24);

    /* Move file pointer to beginning */
    lseek(fd, 0, SEEK_SET);

    /* Read from file */
    read(fd, buffer, 24);
    buffer[24] = '\0'; /* Null terminate string */
    printf("Data read: %s", buffer);

    /* Get file access time */
    struct stat info;
    stat("demo.txt", &info);
    printf("\nLast access time: %s", ctime(&info.st_atime));

    close(fd);
    return 0;
}
