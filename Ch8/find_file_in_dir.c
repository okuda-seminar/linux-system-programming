#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>


int main(void) {
    struct dirent *entry;
    int ret = 1;
    DIR *dir;
    const char *file = "find_file_in_dir.c";
    const char *path = "/workspace/Ch8";

    dir = opendir(path);

    errno = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, file) == 0) {
            printf("file: %s is found in %s\n", file, path);
            break;
        }
    }

    if (errno && !entry) {
        perror("readdir");
    }

    closedir(dir);

    return 0;
}