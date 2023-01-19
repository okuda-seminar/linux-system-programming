#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int i;
    int n = 5;
    char c = '*';

    for (i = 1; i < n; i++) {
        char *s;
        int j;

        /*
         * Allocate and zero an i+2 element array
         * of chars, Note that 'sizeof (char)'
         *  is always 1.
        */

        s = calloc(i + 2, 1);
        if (!s) {
            perror("calloc");
            break;
        }

        for (j = 0; j < i; j++) {
            s[j] = c;
        }

        printf("%s\n", s);

        free(s);
    }

    return 0;
}