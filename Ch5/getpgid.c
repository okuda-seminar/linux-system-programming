#include <stdio.h>
#include <unistd.h>

#define _XOPEN_SOURCE 500

int main(void) {
    pid_t pgid;

    pgid = getpgid(0);
    if (pgid == -1) {
        perror("getpgid");
        return 1;
    }

    printf("My process group id: %d\n", pgid); 
    return 0;
}