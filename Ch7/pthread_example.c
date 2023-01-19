#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void *start_thread(void *message) {
    printf("%s\n", (const char *) message);
}

int main(void) {
    pthread_t handler1, handler2;
    const char *message1 = "handler 1";
    const char *message2 = "handler 2";
    /* Create two threads, each with a different message */
    pthread_create(&handler1, NULL, start_thread, (void *) message1);
    pthread_create(&handler2, NULL, start_thread, (void *) message2);

    /* 
     * Wait for the threads to exit. If we didn't join here,
     * we'd risk termenating this main thread before the
     * other two threads finished.
    */
   pthread_join(handler1, NULL);
   pthread_join(handler2, NULL);

    return 0;
}