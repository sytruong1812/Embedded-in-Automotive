#include <stdio.h>

int main() {
    char *s = "Abhas";
    printf("%s", s + (s[1] - s[3]));    //s + 1
    return 0;
}