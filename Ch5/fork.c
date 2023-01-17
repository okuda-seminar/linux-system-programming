#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
    __pid_t pid;
    int ret;
    char* command = "ls";
    char* argument_list[] = {"ls", "-l", NULL};

    if (ret == -1) {
        perror("execvp");
        return 1;
    }

    pid = fork();
    if (pid > 0) {
        // TODO: fix the problem that this line prevents the program finishing. Maybe it's related to join.
        // printf("I'm the parent process (pid: %d)\n", getppid());
        printf("I'm the parent process\n");
    } else if (!pid) {
        printf("I'm the child process (pid: %d)\n", pid);
        ret = execvp(command, argument_list);
    } else if (pid == -1) {
        perror("fork");
        return 1;
    }

    return 0;
}