#include <stdio.h>

/*
 * Write a program to remove trailing blanks and tabs
 * from each line of input, and to delete entirely
 * blank lines.
 *
 * How to test it (on Unix systems):
 *
 *      $ ./a.out < 1-18.in
 *
 */

#define MAXLINE 1000

int main (int argc, char const* argv[]) {
    char c, line[MAXLINE];
    int i, last_nonblank;

    while ((c = getchar()) != EOF) {
        last_nonblank = 0;
        for (i = 0; c != EOF && c != '\n'; i++) {
            line[i] = c;
            if (c != ' ' && c != '\t') {
                last_nonblank = i;
            }
            c = getchar();
        }

        if (last_nonblank > 0) {
            line[last_nonblank + 1] = '\0';
            printf("%s\n", line);
        }
    }

    return 0;
}
