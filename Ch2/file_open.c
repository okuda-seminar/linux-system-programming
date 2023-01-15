#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    int fd;
    fd = open("./tmp.txt", O_RDONLY);
    if (fd == -1) {
        printf("failed to open file\n");
        exit(-1);
    }
    printf("opened file descriptor: %d\n", fd);

    if (close(fd) == -1) {
        perror("close");
    }
    return 0;
}