#include <stdio.h>

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if (a >= b && c >= d) {
        printf("Stay home");
    } else if (a >= b) {
        printf("Go to the pharmacy");
    } else if (c >= d) {
        printf("Go to the grocery store");
    } else {
        printf("Go to the department store");
    }
}