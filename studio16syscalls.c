#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define EXPECTED_ARGS 2
#define FILENAME_ARG 1
#define FORMAT_ARG 2

int main(int argc, char* argv[]) {
    int i;
    if(argc <= EXPECTED_ARGS) {
        printf("Usage: %s file, format\n", argv[0]);
        return 1;
    }
    int fd = open(argv[FILENAME_ARG], O_WRONLY | O_TRUNC);
    for(i = 2; i < argc; i++) {
        write(fd, argv[i], strlen(argv[i]));
        write(fd, "\n", 2);
    }
    close(fd);
    return 0;
}