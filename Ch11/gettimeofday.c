#include <stdio.h>
#include <sys/time.h>
#include <errno.h>

int main(void) {
    struct timeval tv;
    int ret;

    ret = gettimeofday(&tv, NULL);
    if (ret) {
        perror("gettimeofday");
        return 1;
    }

    printf("seconds: %ld useconds: %ld\n", (long) tv.tv_sec, (long) tv.tv_usec);
    return 0;
}