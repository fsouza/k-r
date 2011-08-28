#include <stdio.h>

/*
 * Write a program to print all input lines
 * that are longer than 80 characters
 *
 * How to test it (on Unix systems):
 *
 *      $ ./a.out < 1-17.in
 *
 */

#define MAXLINE 1000

int main (int argc, char const* argv[]) {
    char c, line[MAXLINE];
    int count = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            line[count] = '\0';
            if (count > 80) {
                printf("%s\n", line);
            }
            count = 0;
        } else {
            line[count] = c;
            ++count;
        }
    }
    return 0;
}
