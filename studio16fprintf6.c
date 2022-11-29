#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXPECTED_ARGS 2
#define FILENAME_ARG 1
#define FORMAT_ARG 2

int main(int argc, char* argv[]) {
    int i;
    unsigned long length = 0;
    if(argc <= EXPECTED_ARGS) {
        printf("Usage: %s file, format\n", argv[0]);
        return 1;
    }
    FILE* file = fopen(argv[FILENAME_ARG], "a");

    for(i = 2; i < argc; i++) {
        length += strlen(argv[i]) + 1;  // Add length of string and space char
    }
    fprintf(file, "%lu ", length);
    for(i = 2; i < argc; i++) {
        fprintf(file, "%s ", argv[i]);
    }
    fprintf(file, "\n");
    fclose(file);
    return 0;
}