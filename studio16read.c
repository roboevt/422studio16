#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXPECTED_ARGS 2
#define FILENAME_ARG 1

int main(int argc, char* argv[]) {
    int i;
    unsigned long length = 0;
    unsigned longestLength = 0;
    unsigned currentLength = 0;
    char* buff = 0;
    if(argc != EXPECTED_ARGS) {
        printf("Usage: %s file\n", argv[0]);
        return 1;
    }
    FILE* file = fopen(argv[FILENAME_ARG], "r");

    while(fscanf(file, "%lu ", currentLength)) {
        if(!longestLength) {
            longestLength = currentLength;
            buff = malloc(longestLength);
        }
        if(currentLength > longestLength) {
            longestLength = currentLength;
            buff = realloc(buff, longestLength);
        }
        fscanf(file, "%s", buff);
    }
    fprintf(file, "\n");
    fclose(file);
    return 0;
}