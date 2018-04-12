/**
 * Filename: main.c
 * Project: Decimal to Binary Conversion
 * Last Updated: October 2017
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary.h"

/*
 *TODO:
 * -output negative binary strings (using "two's complement")
 *   -would require an additional digit for negative numbers
 * -modify code to accomodate for more options (maybe remove boolean?)
 *   -need an option to convert any number, regardless of
 *   how many digits are provided
 */

/**
 * Function: main()
 * Purpose: Sends arguments to init and prints errors if
 * any errors occur during program execution.
 */
int main(int argc, char **argv)
{
    int errors;

    /*
     * Initiate the program and collect errors
     * if any occur. Terminate the program if there are no
     * arguments to process.
     */
    if (argc < 2)
        errors = NO_ARGS;
    /*
     * '-l' option entered.
     */
    else if (!strcmp(argv[1], "-l")) {
        if (argc < 3)
            errors = NO_ARGS;
        else
            errors = init(argc, argv, true);
    }
    /*
     * '--help' option entered.
     */
    else if (!strcmp(argv[1], "--help")) {
        /*
         * Basic usage
         */
        printf("Usage: %s [OPTION] [NUMBER OF BITS] [ARGUMENT]...\n", argv[0]);
        /*
         * List all options and what they do.
         */
        printf("\n  -l\t\t\tlist decimal numbers alongside binary representations\n");
        /*
         * Tutorial
         */
        printf("\nBy default, %s displays a list of binary digits. To output a single\n"
               "binary string from a decimal number, type:\n"
               "\n  %s [NUMBER OF DIGITS] [DECIMAL NUMBER TO BE CONVERTED]\n",
               argv[0],
               argv[0]
            );
        printf("\nWhere %s shines is in its ability to display lists. To output a list\n"
               "of binary strings from zero to 2^[NUMBER OF DIGITS]-1, simply type:\n"
               "\n  %s [NUMBER OF DIGITS]\n",
               argv[0],
               argv[0]
            );
        printf("\n%s can even print a list from a specific range of numbers. For example\n"
               "the following command will output a list of binary numbers made up of\n"
               "five digits from 7 to 15:\n"
               "\n%s [-l] 5 7 15\n",
               argv[0],
               argv[0]
            );
        /*
          printf("\nFinally, %s can also print the binary representation of negative numbers\n"
          "using the 'two's complement' method (WORK IN PROGRESS).\n",
          argv[0]
          );
        */
        exit(EXIT_SUCCESS);
    }
    /*
     * Silly arguments.
     */
    else if (!strcmp(argv[1], "digit"))
    { PLAY(argv[1]); }
    else if (!strcmp(argv[1], "digits"))
    { PLAY(argv[1]); }
    else if (!strcmp(argv[1], "number"))
    { PLAY(argv[1]); }
    else if (!strcmp(argv[1], "numbers"))
    { PLAY(argv[1]); }
    /*
     * No option entered.
     */
    else
        errors = init(argc, argv, false);

    /*
     * No errors occurred, program execution successful.
     */
    if (!errors)
        exit(EXIT_SUCCESS);
    /*
     * Error occurred, print error message.
     */
    else {
        if (errors == NO_ARGS)
            fprintf(stderr, "%s: missing operand.\n", argv[0]);
        else if (errors == NOT_INT)
            fprintf(stderr, "%s: operand [ ARGUMENT ] must be an integer.\n", argv[0]);
        else if (errors == NEG_BITS)
            fprintf(stderr, "%s: operand [ NUMBER OF BITS ] must be a positive integer.\n", argv[0]);
        else if (errors == TOO_FEW_BITS)
            fprintf(stderr, "%s: Not enough bits entered to convert input values.\n", argv[0]);
        exit(EXIT_FAILURE);
    }
}
