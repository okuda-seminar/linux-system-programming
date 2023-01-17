#include <stdio.h>
#include <unistd.h>

int main(void) {
    int ret;
    char* command = "ls";
    char* argument_list[] = {"ls", "-l", NULL};

    printf("Before calling execvp()\n");

    // Calling the execvp() system call
    ret = execvp(command, argument_list);

    if (ret == -1) {
        perror("execvp");
        return 1;
    }

    printf("This line will not be printed if execvp() runs correctly\n");
    return 0;
}