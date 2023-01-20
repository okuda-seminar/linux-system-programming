#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

/* handler for SIGINT */
static void sigint_handler(int signo) {
    printf("\nCaught %s\n", sys_siglist[signo]);
    exit(EXIT_SUCCESS);
}

int main(void) {
    if (signal(SIGINT, sigint_handler) == SIG_ERR) {
        fprintf(stderr, "Cannot handle SIGINT\n");
        exit(EXIT_FAILURE);
    }

    for (;;) {
        pause();
    }

    return 0;
}