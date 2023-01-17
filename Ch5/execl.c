#include <stdio.h>
#include <unistd.h>

int main(void) {
    if (execl("/bin/vim", "vim", "/workspace/Ch5/tmp.txt", NULL) == -1) {
        perror("execl");
        return 1;
    }
    return 0;
}