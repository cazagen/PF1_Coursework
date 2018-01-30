#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int use_stdin = 1;
char* file_input;

int use_stdout = 1;
char* file_output;

int ignore_case = 0;

void setup(int argc, char **argv) {
    for(int i = 0; i < argc; i++) {
        // Decide whether or not to read from stdin
        if (strcmp(argv[i], "-i") == 0) {
            use_stdin = 0;
            file_input = argv[i + 1];
        }
        // Decide whether or not to output to stdout
        if (strcmp(argv[i], "-o") == 0) {
            use_stdout = 0;
            file_output = argv[i + 1];
        }
        // Decide whether or not to ignore case
        if (strcmp(argv[i], "-c") == 0) {
            ignore_case = 1;
        }
    }
    printf("\nUse STDIN: %d\nUse STDOUT: %d\nIgnore case: %d\n\n", use_stdin, use_stdout, ignore_case);
    printf("Input file: %s\nOutput file: %s\n", file_input, file_output);
}

int main(int argc, char **argv) {
    // Run setup
    setup(argc, argv);

    char input[50000];

    if (use_stdin != 0) {
        fgets(input, 50, stdin);
        printf(input);
    } else {
        printf("test");
    }


    return 0;
}
