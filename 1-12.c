#include <stdio.h>

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
