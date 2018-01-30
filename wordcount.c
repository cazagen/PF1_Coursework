#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

    // for(int i = 0; i < argc; i++) {
    //     printf("argument %d: %s\n", i, argv[i]);
    // }

    int use_stdin = 1;
    int use_stdout = 1;
    int ignore_case = 0;

    for(int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "-i") == 0) {
            use_stdin = 0;
        }
        if (strcmp(argv[i], "-o") == 0) {
            use_stdout = 0;
        }
        if (strcmp(argv[i], "-c") == 0) {
            ignore_case = 1;
        }
    }

    printf("\nUse STDIN: %d\nUse STDOUT: %d\nIgnore case: %d\n\n", use_stdin, use_stdout, ignore_case);

    return 0;
}
