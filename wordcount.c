// Cameron Sharp
// 40275188@live.napier.ac.uk
// Last Modified: 16/02/2018
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ARRAY_SIZE 10000

int use_stdin = 1;
char* file_input_name;
FILE *file_input;

int use_stdout = 1;
char* file_output_name;
FILE *file_output;

int ignore_case = 0;

struct words {
    char *name;
    int count;
};

struct words word_array[ARRAY_SIZE];

int word_count = 0;

// Do basic setup: initialise array, and read flags
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
    
    // Initialise array
    for(int i = 0; i < ARRAY_SIZE; i++){
        word_array[i].name = NULL;
        word_array[i].count = 0;
    }

}

// Sort the array by occurrence of words decreasing
void sort_array() {
    for(int i = 0; i < ARRAY_SIZE; i++) {
        for(int j = 0; j < ARRAY_SIZE - (i + 1); j++) {
            if ((word_array[j].count) < (word_array[j + 1].count)) {
                char *temp_name = word_array[j + 1].name;
                int temp_count = word_array[j + 1].count;

                word_array[j + 1].name = word_array[j].name; 
                word_array[j + 1].count = word_array[j].count;

                word_array[j].name = temp_name;
                word_array[j].count = temp_count;
            }
        }
    }
}

// Output data to stdout/file
void output(char *input) {
    #ifdef DEBUG
    printf("\033[1;32m");
    printf("\n\nSTART OF INPUT\n\n");
    printf("\033[0m");
    printf("%s", input);
    printf("\033[1;32m");
    printf("\nEND OF INPUT\n\n");
    printf("\033[0m");
    #endif

    char *current_word;
    current_word = strtok (input," ,.-?!\n\r\t");
    int index = 0;
    int is_there = 0;

    while (current_word != NULL) {
        is_there = 0;
        for(int i = 0; i < ARRAY_SIZE; i++){
            if(word_array[i].name != NULL){
                if(strcmp(current_word, word_array[i].name) == 0){
                    word_array[i].count = word_array[i].count + 1;
                    is_there = 1;
                }
            }
        }
        if(is_there == 0){
            word_array[index].name = current_word;
            word_array[index].count = 1;
        }
        index++;
        current_word = strtok(NULL, " ,.-?!\n\r\t");
    }

    word_count = index;

    sort_array();

    if(use_stdout == 1){
        printf("Total word count: %d\n\n", word_count);
        for(int i = 0; i < ARRAY_SIZE; i++){
            if(word_array[i].name != NULL){
                printf("%s: ", word_array[i].name);
                printf("%d\n", word_array[i].count);
            }
        }
    } else{
        file_output = fopen(file_output_name, "w");
        fprintf(file_output,"Total word count: %d\n\n", word_count);
        for(int i = 0; i < ARRAY_SIZE; i++){
            if(word_array[i].name != NULL){
                fprintf(file_output, "%s: %d\n", word_array[i].name, word_array[i].count);
            }
        }
        fclose(file_output);
    }

}

// Input data from stdin/file
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
    } else {

	    file_input = fopen(file_input_name, "r");
	
	    while ((read = getline(&line, &len, file_input)) != -1) {
            strcat(input, line);
	    }
	    free(line);
	    fclose(file_input);
    }

    if (ignore_case == 1) {
        for(int i = 0; input[i]; i++){
            input[i] = tolower(input[i]);
        }
    }
    output(input);
}


// Run setup and input
int main(int argc, char **argv) {
    // Run setup
    setup(argc, argv);
    input();

    return 0;
}
