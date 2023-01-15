#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int fd;
    unsigned long word;
    ssize_t nr;
    
    fd = open("./tmp.txt", O_RDONLY);
    if (fd == -1) {
        printf("failed to open file\n");
        exit(-1);
    }

    nr = read(fd, &word, sizeof(unsigned long));
    if (nr == -1) {
        printf("failed to read file\n");
        exit(-1);
    }
    return 0;
}