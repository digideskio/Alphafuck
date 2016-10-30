#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int getinput() {
    if (feof(stdin)) return EOF;
    int c = getchar();
    return c == EOF ? : isalpha(c) ? c : getinput();
}

int main() {
    int a, b;
    a = getinput();
    b = getinput();
    while(a != EOF && b != EOF) {
        putchar(
            (islower(a) && islower(b))
              ? (a - b) % 2
                  ? '-' : '+'
          : (islower(a) && isupper(b))
              ? (a - tolower(b)) % 2
                  ? '.' : ','
          : (isupper(a) && islower(b))
              ? (tolower(a) - b) % 2
                  ? '<' : '>'
          : (isupper(a) && isupper(b))
              ? (a - b) % 2
                  ? '[' : ']'
          : 0);
        a = getinput();
        b = getinput();
    }
}
