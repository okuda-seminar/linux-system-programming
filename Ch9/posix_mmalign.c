#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    void *buf;
    int ret;

    /* allocate 1 KB along a 256-byte boundary */
    ret = posix_memalign(&buf, 256, 1024);
    if (ret) {
        fprintf(stderr, "posix_memalign: %s\n", strerror(ret));
        return 1;
    }

    free(buf);
    return 0;
}