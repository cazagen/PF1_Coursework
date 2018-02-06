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

void output(char *input) {
    if (use_stdout != 0) {
        printf("Your data:\n%s\n", input);
    } else {
        file_output = fopen(file_output_name, "w");

        fclose(file_output);
    }
}

void input() {
    char *line = NULL;
	size_t len = 0;
	ssize_t read;
    char input[50000];

    if (use_stdin != 0) {
        fgets(input, 50000, stdin);
    } else {
        input[0] = '\0';

	    file_input = fopen(file_input_name, "r");
	
	    while ((read = getline(&line, &len, file_input)) != -1) {
            strcat(input, line);
	    }
	    free(line);
	    fclose(file_input);
    }

    output(input);
}


int main(int argc, char **argv) {
    // Run setup
    setup(argc, argv);
    input();
    
    return 0;
}
