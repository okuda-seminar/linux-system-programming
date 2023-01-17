#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
    printf("ppid: %jd\n", (__intmax_t) getppid());
    return 0;
}