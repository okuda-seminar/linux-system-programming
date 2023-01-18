#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

int main(void) {
    int prio, ret;

    prio = getpriority(PRIO_PROCESS, 0);
    printf("current priority is %d.\n", prio);

    ret = setpriority(PRIO_PGRP, 0, 10);
    if (ret == -1) {
        perror("setpriority");
        return 1;
    }
    prio = getpriority(PRIO_PROCESS, 0);
    printf("current priority is %d.\n", prio);
}