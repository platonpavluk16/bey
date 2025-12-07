#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h> 


int xTree[5];
int yTree[5];
int x = 5, y = 5;
int enemyX = 10, enemyY = 3;
char enemySymbol = '%';
char playerSymbol;

void draw() {
    system("cls");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 20; j++) {

if (i == y && j == x)
printf("%c", playerSymbol);
else if (i == enemyY && j == enemyX)
printf("%c", enemySymbol);
else if (
(j == xTree[0] && i == yTree[0]) ||
(j == xTree[1] && i == yTree[1]) ||
(j == xTree[2] && i == yTree[2]) ||
(j == xTree[3] && i == yTree[3]) ||
(j == xTree[4] && i == yTree[4])
            )
printf("T");
else
printf(".");
        }
printf("\n");
    }
}


void moveEnemy() {
    if (enemyX < x) enemyX++;
    else if (enemyX > x) enemyX--;

    if (enemyY < y) enemyY++;
    else if (enemyY > y) enemyY--;
}

void spawnTrees() {
    for (int i = 0; i < 5; i++) {
        xTree[i] = rand() % 20;
        yTree[i] = rand() % 10;
    }
}

void gameOver() {
    printf(
"  ██████   █████  ███    ███ ███████        ██████  ██    ██ ███████ ██████  \n"
" ██       ██   ██ ████  ████ ██            ██    ██ ██    ██ ██      ██   ██ \n"
" ██   ███ ███████ ██ ████ ██ █████         ██    ██ ██    ██ █████   ██████  \n"
" ██    ██ ██   ██ ██  ██  ██ ██            ██    ██  ██  ██  ██      ██   ██ \n"
"  ██████  ██   ██ ██      ██ ███████        ██████    ████   ███████ ██   ██ \n"
    );
    Sleep(2000);
    exit(0);
}

void victory() {
    printf(
"██╗   ██╗██╗ ██████╗ ████████╗ ██████╗ ██████╗ ██╗   ██╗\n"
"██║   ██║██║██╔═══██╗╚══██╔══╝██╔═══██╗██╔══██╗╚██╗ ██╔╝\n"
"██║   ██║██║██║                  ██║   ██║██████╔╝ ╚████╔╝ \n"
"██║   ██║██║████║   ██║   ██║██╔═══╝   ╚██╔╝  \n"
"╚██████╔╝██║╚██████╔╝   ██║   ╚██████╔╝██║        ██║   \n"
" ╚═════╝ ╚═╝ ╚═════╝    ╚═╝    ╚═════╝ ╚═╝        ╚═╝   \n"
    );
    Sleep(2000);
    exit(0);
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    srand(time(NULL));
    printf("Set your player symbol: ");
    scanf(" %c", &playerSymbol);
    spawnTrees();

for (int i = 0; i < 5; i++) {
    if (x == xTree[i] && y == yTree[i]) {
        gameOver();
    }
}


    int moves = 0; 
    char c;
;

    while (1) {
        draw();
        printf("Move (w a s d), q to quit: ");
        scanf(" %c", &c);

        if (c == 'a') x--;
        else if (c == 'd') x++;
        else if (c == 'w') y--;
        else if (c == 's') y++;
        else if (c == 'q') break;

        moves++; 

        moveEnemy();

        if (enemyX == x && enemyY == y) {
            gameOver();
        }

        for (int i = 0; i < 5; i++) {
            if (x == xTree[i] && y == yTree[i]) {
                if (x == xTree[i]){x = xTree[i] - 1;}
                if (y == yTree[i]){y = yTree[i] - 1;}

            }
}

        if (moves >= 20) {
            victory();
        }
    }

    return 0;
}
