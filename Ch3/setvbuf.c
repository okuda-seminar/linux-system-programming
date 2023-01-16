#include <stdio.h>

int main(void) {
    char buf[BUFSIZ];

    /* set stdin to block-buffered with a BUFSIZE buffer */
    setvbuf(stdout, buf, _IOFBF, BUFSIZ);
    printf("Arrr!\n");
    return 0;
    /* 'buf' exits scope and is freed, but stdout isn't closed until later */
}