#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int use_stdin = 1;
char* file_input_name;
FILE *file_input;

int use_stdout = 1;
char* file_output_name;
FILE *file_output;

int ignore_case = 0;

void setup(int argc, char **argv) {
    for(int i = 0; i < argc; i++) {
        // Decide whether or not to read from stdin
        if (strcmp(argv[i], "-i") == 0) {
            use_stdin = 0;
            file_input_name = argv[i + 1];
        }
        // Decide whether or not to output to stdout
        if (strcmp(argv[i], "-o") == 0) {
            use_stdout = 0;
            file_output_name = argv[i + 1];
        }
        // Decide whether or not to ignore case
        if (strcmp(argv[i], "-c") == 0) {
            ignore_case = 1;
        }
    }
    printf("\nUse STDIN: %d\nUse STDOUT: %d\nIgnore case: %d\n\n", use_stdin, use_stdout, ignore_case);
    printf("Input file: %s\nOutput file: %s\n\n", file_input_name, file_output_name);
}

int main(int argc, char **argv) {
    // Run setup
    setup(argc, argv);

    char input[50000];

    if (use_stdin != 0) {
        fgets(input, 50000, stdin);
        printf(input);
    } else {
        file_input = fopen(file_input_name, "r");
        fgets(input, 50000, file_input);
        printf(input);
        fclose(file_input);
    }
    return 0;
}
