#include <stdio.h>
#include <sched.h>

int main(void) {
    struct timespec tp;
    int ret;

    /* get the crrent tasks's timeslice length */
    ret = sched_rr_get_interval(0, &tp);
    if (ret == -1) {
        perror("sched_rr_get_interval");
        return 1;
    }

    /* convert the seconds and nanoseconds to milliseconds */
    printf("Our time quantum is %.2lf milliseconds.\n", (tp.tv_sec * 1000.0f) + (tp.tv_nsec / 1000000.0f));
    return 0;
}