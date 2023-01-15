#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {
    int fd;
    fd = open("./tmp.txt", O_RDONLY);
    if (fd == -1) {
        printf("failed to open file\n");
        exit(-1);
    }
    printf("opened file descriptor: %d\n", fd);
    return 0;
}