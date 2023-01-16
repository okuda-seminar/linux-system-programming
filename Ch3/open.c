#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
    FILE *stream;
    int fd, ret;

    fd = open("./tmp.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 0;
    }

    stream = fdopen(fd, "r");
    if (!stream) {
        perror("fdopen");
        return 0;
    }

    // fclose automatically calls close
    ret = fclose(stream);
    if (ret == -1) {
        perror("fclose");
        return 0;
    }

    return 0;
}