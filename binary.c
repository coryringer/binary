/**
 * Filename: binary.c
 * Project: Decimal to Binary Conversion
 * Last Updated: October 2017
 */
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "binary.h"

/**
 * Function: init()
 * Purpose: Processes arguments and returns
 * an error code if any errors occur.
 */
int init(int num_args, char **args, int val)
{
    int i, NUM_BITS, SEC_ARG, THIRD_ARG;
    char *ptr;

    /*
     * These strings are used for formatting output.
     */
    const char heading[] = "Decimal\t\tBinary";
    const char table_output[] = "%d\t\t%s\n";
    const char single_output[] = "%s\n";

    /*
     * Check to make sure n is an integer.
     */
    if (!is_integer(args[val + 1]))
        return NOT_INT;

    NUM_BITS = atoi(args[val + 1]);

    /*
     * Check if n is positive.
     */
    if (NUM_BITS <= 0)
        return NEG_BITS;

    /**
     * If the user gives one argument of positive n:
     *   The program will print out a table
     *   of positive integers and their binary
     *   representation from 1 to 2^n-1 with n bits.
     */
    if (num_args == val + 2) {
        /*
         * Print heading if option '-l' is entered.
         */
        if (val)
            puts(heading);

        /*
         * Print table
         */
        for (i = 0; i < pow(2, NUM_BITS); i++) {
            ptr = bin_rep(NUM_BITS - 1, i);

            if (val)
                printf(table_output, i, ptr);
            else
                printf(single_output, ptr);
        }

    }
    /**
     * If the user gives two arguments of positive n
     * and (positive or negative) m:
     *   The program will print out the binary
     *   representation of m with n bits.
     *
     *   The program will give an error message if there
     *   is not enough bits to convert m to binary.
     */
    else if (num_args == val + 3) {
        if (!is_integer(args[val + 2]))
            return NOT_INT;

        SEC_ARG = atoi(args[val + 2]);

        if (pow(2, NUM_BITS) <= SEC_ARG)
            return TOO_FEW_BITS;

        if (val)
            puts(heading);

        ptr = bin_rep(NUM_BITS - 1, SEC_ARG);

        /*
         * Print value
         */
        if (val)
            printf(table_output, SEC_ARG, ptr);
        else
            printf(single_output, ptr);
    }
    /**
     * If the user gives three arguments of positive n,
     * (positive or negative) m, and (positive or negative) l:
     */
    else if (num_args == val + 4) {
        if ((!is_integer(args[val + 2])) || (!is_integer(args[val + 3])))
            return NOT_INT;

        SEC_ARG = atoi(args[val + 2]);
        THIRD_ARG = atoi(args[val + 3]);

        if (val)
            puts(heading);

        /*
         * If m < l:
         *   The program will print out a table of integers m to l
         *   and their binary representation of n bits.
         *
         *   The program will give an error message if there is not
         *   enough bits to convert m or l to binary.
         */
        if (SEC_ARG < THIRD_ARG) {
            if ((pow(2, NUM_BITS) <= SEC_ARG) || (pow(2, NUM_BITS) <= THIRD_ARG))
                return TOO_FEW_BITS;

            for (i = SEC_ARG; i <= THIRD_ARG; i++) {
                ptr = bin_rep(NUM_BITS - 1, i);

                if (val)
                    printf(table_output, i, ptr);
                else
                    printf(single_output, ptr);
            }
        }
        /*
         * If m > l:
         *   The program will print out a table of integers l to m
         *   and their binary representation of n bits.
         *
         *   The program will give an error message if there is not
         *   enough bits to convert m or l to binary.
         */
        else if (SEC_ARG > THIRD_ARG) {
            if ((pow(2, NUM_BITS) <= SEC_ARG) || (pow(2, NUM_BITS) <= THIRD_ARG))
                return TOO_FEW_BITS;

            for (i = SEC_ARG; i >= THIRD_ARG; i--) {
                ptr = bin_rep(NUM_BITS - 1, i);

                if (val)
                    printf(table_output, i, ptr);
                else
                    printf(single_output, ptr);
            }
        }
        /*
         * If m == l:
         *   The program will print out the binary
         *   representation of m with n bits.
         *
         *   The program will give an error message if there
         *   is not enough bits to convert m to binary.
         */
        else if (SEC_ARG == THIRD_ARG) {
            if (pow(2, NUM_BITS) <= SEC_ARG)
                return TOO_FEW_BITS;

            /*
             * Print value
             */
            ptr = bin_rep(NUM_BITS - 1, SEC_ARG);

            if (val)
                printf(table_output, SEC_ARG, ptr);
            else
                printf(single_output, ptr);
        }
    }

    free(ptr);
    return EXIT_SUCCESS;
}

/**
 * Function: is_integer()
 * Purpose: Checks to see if char* s is an integer.
 */
bool is_integer(char* s)
{
    int i;

    /*
     * If input is a negative integer, don't
     * flag the negative symbol.
     */
    i = 0;
    if (s[i] == '-')
        i++;

    /*
     * Flag array if it contains any non-numerical
     * characters.
     */
    for (i; s[i] != '\0'; i++) {
        if (!isdigit(s[i]))
            return false;
    }

    return true;
}

/**
 * Function: bin_rep()
 * Purpose: Converts a decimal number n
 * into its binary representation using a
 * user defined number of bits. Returns a
 * binary string.
 */
char *bin_rep(int num_binbits, int dec_num)
{
    int curr_bit;
    char *binary_str;

    binary_str = (char *) malloc(num_binbits + 1);

    curr_bit = 0;
    while(num_binbits >= curr_bit) {
        /*
         * If the decimal number after the
         * bitshift of the number of bits minus
         * the current bit count is 1, record a
         * 1 for the current bit index in
         * the array.
         */
        if (!(dec_num >> num_binbits - curr_bit & 1))
            binary_str[curr_bit] = '0';
        else
            binary_str[curr_bit] = '1';
        curr_bit++;
    }

    /*
     * Make binary string a zero-terminating string.
     */
    binary_str[curr_bit] = '\0';

    return binary_str;
}
