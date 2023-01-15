#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd;
    const char *buf = "My ship is solid!\n";
    ssize_t nr;
    size_t count;

    fd = creat("./tmp.txt", 0644);
    if (fd == -1) {
        printf("failed to create a file");
        exit(-1);
    }
    count = strlen(buf);
    nr = write(fd, buf, strlen(buf));
    if (nr == -1) {
        printf("failed to write data\n");
        exit(-1);
    } else if (nr != count) {
        printf("partial write happened\n");
    }

    if (close(fd) == -1) {
        perror("close");
    }
    return 0;
}