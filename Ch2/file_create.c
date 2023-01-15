#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {
    int fd;
    fd = creat("./tmp.txt", 0644);
    if (fd == -1) {
        printf("failed to create a file");
        exit(-1);
    }
    printf("opened file descriptor: %d\n", fd);
    return 0;
}