#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

    // for(int i = 0; i < argc; i++) {
    //     printf("argument %d: %s\n", i, argv[i]);
    // }

    int use_stdin = 1;
    int use_stdout = 1;

    for(int i = 0; i < argc; i++) {
        if (argv[i] == "-o") {
            printf("-o appeared");
        }
        printf("-o did not appear");
    }

    return 0;
}
