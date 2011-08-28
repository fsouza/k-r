#include <stdio.h>

/*
 * Write a program detab that replaces tabs in the input
 * with the proper number of blanks to space to the next tab
 * stop. Assume a fixed set of tab stops, say every n columns.
 * Should n be a variable or a symbolic parameter?
 *
 * How to test it (on Unix systems):
 *
 *      $ ./a.out < 1-20.in
 *
 */

#define MAXSIZE 1000
#define TABSTOP 4

int main (int argc, char const* argv[]) {
    int i, j;
    char c, output[MAXSIZE];

    for (i = 0; i < MAXSIZE - 1 && (c = getchar()) != EOF; ++i) {
        if (c == '\t') {
            for (j = i; j < i + TABSTOP; ++j) {
                output[j] = ' ';
            }

            i += TABSTOP - 1;
        } else {
            output[i] = c;
        }
    }

    output[i] = '\0';
    printf("%s\n", output);

    return 0;
}
