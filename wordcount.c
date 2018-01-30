#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void setup(int argc, char **argv) {
    int use_stdin = 1;
    int use_stdout = 1;
    int ignore_case = 0;

    for(int i = 0; i < argc; i++) {
        // Decide whether or not to read from stdin
        if (strcmp(argv[i], "-i") == 0) {
            use_stdin = 0;
        }
        // Decide whether or not to output to stdout
        else if (strcmp(argv[i], "-o") == 0) {
            use_stdout = 0;
        }
        // Decide whether or not to ignore case
        else if (strcmp(argv[i], "-c") == 0) {
            ignore_case = 1;
        }
    }

    printf("\nUse STDIN: %d\nUse STDOUT: %d\nIgnore case: %d\n\n", use_stdin, use_stdout, ignore_case);
}

int main(int argc, char **argv) {

    // Run setup
    setup(argc, argv);

    return 0;
}
