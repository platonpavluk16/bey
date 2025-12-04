#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int x = 5;
int y = 5;
int enemyX = 10;
int enemyY = 3;
char enemySymbol = '%';
char playerSymbol;

void enemy() {


}

void draw() {
    system("cls");

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 20; j++) {
            if (i == y && j == x)
                printf("%c", playerSymbol);
            else
                printf(".");
            if (i == enemyY && j == enemyX) {
                printf("%c", enemySymbol);
            }
            
        }
        printf("\n");
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
printf(" ██████   █████  ███    ███ ███████ \n");
printf("██       ██   ██ ████  ████ ██      \n");
printf("██   ███ ███████ ██ ████ ██ █████   \n");
printf("██    ██ ██   ██ ██  ██  ██ ██      \n");
printf(" ██████  ██   ██ ██      ██ ███████ \n");



    char c;

    printf("Set your player symbol: ");
    scanf(" %c", &playerSymbol);

void moveEnemy() {
    if (enemyX < x) enemyX++;
    else if (enemyX > x) enemyX--;

    if (enemyY < y) enemyY++;
    else if (enemyY > y) enemyY--;
}

    while (1) {
        draw();
        printf("Move (w a s d): ");
        scanf(" %c", &c);
        moveEnemy();

        if (enemyX == x && enemyY == y) {
                printf(
"  ██████   █████  ███    ███ ███████        ██████  ██    ██ ███████ ██████  \n"
" ██       ██   ██ ████  ████ ██            ██    ██ ██    ██ ██      ██   ██ \n"
" ██   ███ ███████ ██ ████ ██ █████         ██    ██ ██    ██ █████   ██████  \n"
" ██    ██ ██   ██ ██  ██  ██ ██            ██    ██  ██  ██  ██      ██   ██ \n"
"  ██████  ██   ██ ██      ██ ███████        ██████    ████   ███████ ██   ██ \n"
    );
            Sleep(2000);
            break;
        }
        
        if (c == 'a') {
            x--;
        };
        if (c == 'd') {
            x++;
        };
        if (c == 'w') {
            y--;
        };
        if (c == 's') {
            y++;
        };
        if (c == 'q') {
            break;
        };
        
    }


    return 0;
}


