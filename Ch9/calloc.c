#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(void) {
    int *x;

    x = calloc(50, sizeof(int));
    if (!x) {
        perror("malloc");
        return 1;
    }
}