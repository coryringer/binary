/**
 * Filename: binary.h
 * Project: Decimal to Binary Conversion
 * Last Updated: October 2017
 */
#ifndef BINARY_H
#define BINARY_H

#define NO_ARGS      0xFFFC
#define NOT_INT      0xFFFD
#define NEG_BITS     0xFFFE
#define TOO_FEW_BITS 0xFFFF

#define PLAY(s) {                               \
        printf("Which %s?\n", argv[1]);         \
        exit(0);                                \
    }

int init(int, char **, int);
bool is_integer(char *);
char *bin_rep(int, int);

#endif /* BINARY_H */
