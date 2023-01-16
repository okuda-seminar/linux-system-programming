#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>

int main(void) {
    FILE *stream;
    int fd, ret;
    char buf[LINE_MAX];

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

    if (!fgets(buf, LINE_MAX, stream)) {
        perror("fgets");
        return 0;
    } 

    printf("%s", buf);

    // fclose automatically calls close
    ret = fclose(stream);
    if (ret == -1) {
        perror("fclose");
        return 0;
    }

    return 0;
}