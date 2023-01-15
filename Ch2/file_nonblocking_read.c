#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main() {
    int fd;
    char buf[BUFSIZ];
    ssize_t nr;
    
    fd = open("./empty.txt", O_RDONLY | O_NONBLOCK);
    if (fd == -1) {
        printf("failed to open file\n");
        exit(-1);
    }

    start:
    nr = read(fd, buf, BUFSIZ);
    if (nr == -1) {
        if (errno == EINTR) {
            goto start;
        }
        if (errno == EAGAIN) {
            /* resubmit later */
        } else {
            printf("failed to read file\n");
            exit(-1);
        }
    }
    return 0;
}