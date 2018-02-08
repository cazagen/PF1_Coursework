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

    #ifdef DEBUG
    printf("\033[1;31m");
    printf("\n\nDEBUG MODE DEBUG MODE\n\n");
    printf("\033[0m");
    printf("\nUse STDIN: %d\nUse STDOUT: %d\nIgnore case: %d\n\n", use_stdin, use_stdout, ignore_case);
    printf("Input file: %s\nOutput file: %s\n\n", file_input_name, file_output_name);
    #endif
    
}

void output(char *input) {
    if (use_stdout != 0) {
        printf("\033[1;32m");
        printf("\n\nSTART OF INPUT\n\n");
        printf("\033[0m");

        printf("%s\n", input);

        printf("\033[1;32m");
        printf("\nEND OF INPUT\n\n");
        printf("\033[0m");

        char str[] ="- This, a sample string.";
        char * current_word;
        current_word = strtok (input," ,.-\n\r\t");
        while (current_word != NULL)
        {
            printf ("%s\n",current_word);
            current_word = strtok (NULL, " ,.-\n\r\t");
        }

    } else {
        file_output = fopen(file_output_name, "w");
        fprintf(file_output, "%s\n", input);
        fclose(file_output);
    }
}

void input() {
    char *line = NULL;
    char input[50000];
    char temp[50000];
	size_t len = 0;
	ssize_t read;
    int ch;

    input[0] = '\0';

    if (use_stdin != 0) {
        printf("CTRL+Z to escape (CTRL+D on unix)\n\n");
        while ( ( ch=getchar() ) != EOF ) {
            fgets(temp, 50000, stdin);
            strcat(input, temp);
        }
        
        fgets(input, 50000, stdin);
    } else {

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
