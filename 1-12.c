#include <stdio.h>

/*
 * Write a program that print its input one word per line.
 *
 * How to test it (on Unix systems):
 *
 *      $ ./a.out < README
 */

int main (int argc, char const* argv[]) {
    char c;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t') {
            printf("\n");
        } else {
            printf("%c", c);
        }
    }

    return 0;
}
