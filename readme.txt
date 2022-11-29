1. Eric Todd
2.  roboevt@MSI_GS66:~/dev/422/422studio16$ ./studio16 abcd test
    roboevt@MSI_GS66:~/dev/422/422studio16$ cat abcd
    test
    roboevt@MSI_GS66:~/dev/422/422studio16$ ./studio16 abcd test one 2 three for five six
    roboevt@MSI_GS66:~/dev/422/422studio16$ cat abcd
    test
    one
    2
    three
    for
    five
    six
    roboevt@MSI_GS66:~/dev/422/422studio16$ ./studio16 abcd
    Usage: ./studio16 file, format
3.  #include <stdio.h>
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
            fputs(argv[i], file);
            fputs("\n", file);
        }
        fclose(file);
        return 0;
    }
4.  #include <fcntl.h>
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
5.  roboevt@MSI_GS66:~/dev/422/422studio16$ cat abcd
    roboevt@MSI_GS66:~/dev/422/422studio16$ ./studio16 abcd test
    roboevt@MSI_GS66:~/dev/422/422studio16$ cat abcd
    test 
    roboevt@MSI_GS66:~/dev/422/422studio16$ ./studio16 abcd one
    roboevt@MSI_GS66:~/dev/422/422studio16$ cat abcd 
    test one 
    roboevt@MSI_GS66:~/dev/422/422studio16$ ./studio16 abcd 2
    roboevt@MSI_GS66:~/dev/422/422studio16$ cat abcd 
    test one 2 
    roboevt@MSI_GS66:~/dev/422/422studio16$ ./studio16 abcd three
    roboevt@MSI_GS66:~/dev/422/422studio16$ ./studio16 abcd for
    roboevt@MSI_GS66:~/dev/422/422studio16$ cat abcd
    test one 2 three for 
    roboevt@MSI_GS66:~/dev/422/422studio16$ ./studio16 abcd five six seven
    roboevt@MSI_GS66:~/dev/422/422studio16$ cat abcd 
    test one 2 three for five six seven
6.  roboevt@MSI_GS66:~/dev/422/422studio16$ ./studio16 a test
    roboevt@MSI_GS66:~/dev/422/422studio16$ cat a 
    5 test 
    roboevt@MSI_GS66:~/dev/422/422studio16$ ./studio16 a one 2
    roboevt@MSI_GS66:~/dev/422/422studio16$ cat a
    5 test 
    6 one 2 
    roboevt@MSI_GS66:~/dev/422/422studio16$ ./studio16 a three for five six 7 ate nien
    roboevt@MSI_GS66:~/dev/422/422studio16$ cat a
    5 test 
    6 one 2 
    30 three for five six 7 ate nien 
    roboevt@MSI_GS66:~/dev/422/422studio16$ 
7. 