//
// Exercise 1-9. Write a program to copy its input to its output,
// replacing each string of one or more blanks by a single blank.
//
#include <stdio.h>

int main(void) {
    int c = 0;
    int prev = 0;
    do {
        c = getchar();
        fflush(stdin);
        if (c == ' ' && prev == ' ') {
            continue;
        }
        putchar(c);
        prev = c;
    } while(c != EOF);
    return 0;
}
