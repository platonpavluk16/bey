#include <stdio.h>
#include <stdlib.h>

int x = 5;
int y = 5;
char playerSymbol;

void draw() {
    system("cls");

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 20; j++) {
            if (i == y && j == x)
                printf("%c", playerSymbol);
            else
                printf(".");
        }
        printf("\n");
    }
}

int main() {
    char c;

    printf("Set your player symbol: ");
    scanf(" %c", &playerSymbol);

    while (1) {
        draw();
        printf("Move (w a s d): ");
        scanf(" %c", &c);

        if (c == 'a') {
            x--;
        };
        if (c == 'd') {
            x++
        };
        if (c == 'w') {
            y--
        };
        if (c == 's') {
            y++
        };
        if (c == 'q') {
            break
        };
    }

    return 0;
}
