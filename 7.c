#include <stdio.h>
#include <stdlib.h>
int main() {
FILE *fp;
char data[100];
fp = popen("date", "r"); // run another command
if (fp == NULL) {
printf("Error opening pipe.
");
return 1;
}
while (fgets(data, sizeof(data), fp) != NULL) {
}
printf("output: %s", data);
pclose(fp);
return 0;
}
