//
// Exercise 1-8. Write a program to count blanks, tabs and newlines.
//
#include <stdio.h>

int main(void) {
    char c;
    int blanks = 0, tabs = 0, newlines = 0;
    printf("Enter something: ");
    while((c = getchar()) != EOF) {
        printf("Enter something: ");
        if (c == ' ') {
            ++blanks;
        } else if (c == '\t') {
            ++tabs;
        } else if (c == '\n') {
            ++newlines;
        }
        fflush(stdin);
    }
    printf("Blanks: %d\nTabs: %d\nNewlines: %d\n", blanks, tabs, newlines);
    return 0;
}

