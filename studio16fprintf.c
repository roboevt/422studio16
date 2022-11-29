#include <stdio.h>
#include <stdlib.h>

#define EXPECTED_ARGS 2
#define FILENAME_ARG 1
#define FORMAT_ARG 2

int main(int argc, char* argv[]) {
    int i;
    if(argc <= EXPECTED_ARGS) {
        printf("Usage: %s file, format\n", argv[0]);
        return 1;
    }
    FILE* file = fopen(argv[FILENAME_ARG], "w");

    for(i = 2; i < argc; i++) {
        fprintf(file, "%s\n", argv[i]);
    }
    fclose(file);
    return 0;
}