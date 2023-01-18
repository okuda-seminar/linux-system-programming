#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(void) {
    int ret, val;

    /* get current nice value */
    val = nice(0);

    printf("nice value is now %d\n", val);

    /* we want a nice value of 10 */
    errno = 0;
    val = 10 - val;
    ret = nice(val);

    if (ret == -1 && errno != 0) {
        perror("nice");
        return 1;
    }

    printf("nice value is now %d\n", ret);
}