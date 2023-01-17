#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
    printf("pid: %jd\n", (__intmax_t) getpid());
    return 0;
}