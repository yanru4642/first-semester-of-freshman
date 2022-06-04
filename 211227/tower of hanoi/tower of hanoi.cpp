#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int moved = 0;

void hanoi(int n, char From, char Aux, char To) {
    if (n == 1) {
        printf("Move sheet 1 from %c to %c\n", From, To);
        moved++;
    }
    else {
        hanoi(n - 1, From, To, Aux);
        printf("move sheet %d from %c to %c\n",n, From, To);
        moved++;
        hanoi(n - 1, Aux, From, To);
    }
}

int main(void) {
    hanoi(4, 'A', 'B', 'C');
    printf("\nTotal moved %d steps\n\n", moved);
    system("pause");
    return 0;
}