# Wordcount

The wordcount program when ran will analyse the input from either standard input or a provided text file, and will output the total word count followed by each word found, and how many time that word occurred

## Building

- Build with `gcc -o executable_name wordcount.c`
- Make the file executable with `chmod +x executable_name`

## Running

- To run the program run `./executable_name [-i input_file] [-o output_file] [-c]`

## Optional parameters

- `-i`: Add this flag followed by the path to a text file to analyse that file, otherwise standard input will be used
- `-o`: Add this flag followed by the path to a text file to output to that file, otherwise standard output will be used
- `-c`: Add this flag if you would like the analysis to be case **insensitive**

## Toolkit used

The program has been tested on and runs on `gcc (Debian 6.3.0-18) 6.3.0 20170516` and `GNU Make 4.1`