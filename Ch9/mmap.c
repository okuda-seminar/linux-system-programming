#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/mman.h>
#include <unistd.h>

int main(void) {
    void *p;
    int fd;

    /* open /dev/zero for reading and writing */
    fd = open("/dev/zero", O_RDWR);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    /* map [0, page size) of /dev/zero */
    p = mmap(
        NULL,
        getpagesize(),
        PROT_READ | PROT_WRITE,
        MAP_PRIVATE,
        fd,
        0
    );

    if (p == MAP_FAILED) {
        perror("mmap");
        if (close(fd)) {
            perror("close");
        }
        return 1;
    }

    /* close /dev/zero, no longer needed */
    if (close(fd)) {
        perror("close");
        return 1;
    }
    return 0;
}