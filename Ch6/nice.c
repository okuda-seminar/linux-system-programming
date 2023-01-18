#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(void) {
    int ret;

    errno = 0;
    ret = nice(10);

    if (ret == -1 && errno != 0) {
        perror("nice");
        return 1;
    }

    printf("nice value is now %d\n", ret);
}