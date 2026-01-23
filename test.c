#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
  int fd = open("demo.txt", O_CREAT | O_RDWR, 0644);
  char b[20];
  write(fd, "hello nigesh ", 5);
  lseek(fd, 0, SEEK_SET);
  read(fd, b, 20);
  printf("%s", b);
  close(fd);
  return 0;
}
