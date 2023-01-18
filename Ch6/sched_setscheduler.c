#include <stdio.h>
#include <sched.h>

int main(void) {
    int ret, policy;
    struct sched_param sp = {.sched_priority = 1};

    // TODO: fix the error: Operation not permitted
    ret = sched_setscheduler(0, SCHED_RR, &sp);

    if (ret == -1) {
        perror("sched_setscheduler");
        return 1;
    }

    policy = sched_getscheduler(0);

    switch (policy)
    {
    case SCHED_OTHER:
        printf("Policy is normal.\n");
        break;
    case SCHED_RR:
        printf("Policy is round-robin.\n");
        break;
    case SCHED_FIFO:
        printf("Policy is FIFO.\n");
        break;
    case -1:
        perror("sched_getscheduler");
        return 1;
    default:
        fprintf(stderr, "Unknown policy.\n");        
        return 1;
    }

    return 0;
}