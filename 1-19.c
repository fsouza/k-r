#include <stdio.h>
#include <string.h>

/*
 * Write a function reverse(s) that reverses the character
 * string s. Use it to write a program that reverses its input
 * a line at a time.
 *
 * How to test it (on Unix systems):
 *
 *      $ ./a.out < 1-18.in
 *
 */

#define MAXSIZE 1000

void reverse(char s[]);

int main (int argc, char const* argv[]) {
    int i;
    char c, line[MAXSIZE];

    while ((c = getchar()) != EOF) {
        for (i = 0; c != EOF && c != '\n'; i++) {
            line[i] = c;
            c = getchar();
        }
        line[i] = '\0';
        reverse(line);
        printf("%s\n", line);
    }

    return 0;
}

void reverse(char s[]) {
    int i, length = strlen(s), half = length / 2 + 1;
    char aux;

    for (i = 0; i < half; i++) {
        aux = s[i];
        s[i] = s[length - i - 1];
        s[length - i -1] = aux;
    }
}
