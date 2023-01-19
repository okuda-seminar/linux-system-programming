#include <errno.h>
#include <pthread.h>
#include <stdio.h>

// ref: https://maku77.github.io/cpp/pthread/create-thread.html
void *start_routine(void* pArg) {
    int *pVal = (int*) pArg;
    printf("worker thread [%d]\n", *pVal);
    *pVal = 200;
}

int main(void) {
    pthread_t thread;
    int ret, resp;

    ret = pthread_create(&thread, NULL, start_routine, &resp);
    if (ret) {
        errno = ret;
        perror("pthread_create");
        return 1;
    }
    pthread_join(thread, NULL);

    printf("response: %d\n", resp);
}