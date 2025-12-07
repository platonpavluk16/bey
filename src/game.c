#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h> 
#include <conio.h> 

#define GRID_HEIGHT 10
#define GRID_WIDTH 20
#define NUM_TREES 5
#define MOVES_TO_WIN 6

int xTree[NUM_TREES];
int yTree[NUM_TREES];
int x = 5, y = 5;
int enemyX = 10, enemyY = 3;
char enemySymbol = '%';
char playerSymbol;
int score_wins = 0;
int score_losses = 0;


int prevX, prevY; 


void loadScore();
void writeScore();
void draw(int currentMoves); 
void moveEnemy();
void spawnTrees();
void gameOver();
void victory();
int isTreeAt(int checkX, int checkY);
void resetGame();



void loadScore() {
    FILE *score = fopen("score.txt", "r");
    if (score != NULL) {

        if (fscanf(score, "Wins: %d, Losses: %d", &score_wins, &score_losses) != 2) {

            score_wins = 0;
            score_losses = 0;
        }
        fclose(score);
    } else {

        score_wins = 0;
        score_losses = 0;
    }
}


void writeScore() {

    FILE *score = fopen("score.txt", "w"); 
    if (score != NULL) {
        fprintf(score, "Wins: %d, Losses: %d\n", score_wins, score_losses);
        fclose(score);
    } else {
        printf("Помилка: Не вдалося зберегти рахунок.\n");
    }
}


int isTreeAt(int checkX, int checkY) {
    for (int i = 0; i < NUM_TREES; i++) {
        if (checkX == xTree[i] && checkY == yTree[i]) {
            return 1;
        }
    }
    return 0;
}


void draw(int currentMoves) { 

    system("cls"); 
    
    printf("Гравець: %c | Ворог: %c | Ходи: %d / %d | Перемоги: %d | Поразки: %d\n", 
           playerSymbol, enemySymbol, currentMoves, MOVES_TO_WIN, score_wins, score_losses);
    printf("--------------------\n");

    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {

            if (i == y && j == x) {
                printf("%c", playerSymbol);
            } else if (i == enemyY && j == enemyX) {
                printf("%c", enemySymbol);
            } else if (isTreeAt(j, i)) {
                printf("T");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
    printf("--------------------\n");
}


void moveEnemy() {

    if (enemyX < x) enemyX++;
    else if (enemyX > x) enemyX--;

    if (enemyY < y) enemyY++;
    else if (enemyY > y) enemyY--;
}


void spawnTrees() {
    for (int i = 0; i < NUM_TREES; i++) {
        int newX, newY;
        do {
            newX = rand() % GRID_WIDTH;
            newY = rand() % GRID_HEIGHT;

        } while ((newX == x && newY == y) || (newX == enemyX && newY == enemyY));
        
        xTree[i] = newX;
        yTree[i] = newY;
    }
}


void resetGame() {
    x = 5; 
    y = 5;
    enemyX = 10;
    enemyY = 3;
    spawnTrees();
}



void gameOver() {
    system("cls");
printf(
        " ╔═══════╗ ╔═══════╗ ╔═══╗   ╔═══╗ ╔═══════╗      ╔═══════╗ ╔═╗   ╔═╗ ╔═══════╗ ╔═══════╗ \n"
        " ║ █ ═ ═ ║ ║ █ ═ █ ║ ║ █ █ ╗ ║ █ █ ║ ║ █ ═ ═ ║      ║ █ ═ ═ ║ ║ █ ╗ ║ █ ║ █ ═ ═ ║ ║ █ ═ █ ║ \n"
        " ║ █ ╔═█ ║ ║ █ ═ ═ ║ ║ █ ═ █ ║ ║ █ ║ ║ █ █ █ ║      ║ █ ═ ═ ║ ║ █ ║ ║ █ ║ █ █ █ ║ ║ █ █ █ ║ \n"
        " ║ █ ═ ═ ║ ║ █ ═ █ ║ ║ █ ═ ═ ╝ ║ █ ║ ║ █ ═ ═ ║      ║ █ ═ ═ ║ ║ █ ║ ║ █ ║ █ ═ ═ ║ ║ █ ═ █ ║ \n"
        " ╚═══════╝ ╚═══════╝ ╚═╝     ╚═╝ ╚═══════╝      ╚═══════╝ ╚═╝   ╚═╝ ╚═══════╝ ╚═══════╝ \n"
    );
    Sleep(2000);
    score_losses++;
    printf("\nПоразки: %d\n", score_losses);
    writeScore();
    Sleep(2000);
    resetGame();
}

void victory() {
    system("cls");
    printf(
        "██╗   ██╗██╗ ██████╗ ████████╗ ██████╗ ██████╗ ██╗   ██╗\n"
        "██║   ██║██║██╔═══██╗╚══██╔══╝██╔═══██╗██╔══██╗╚██╗ ██╔╝\n"
        "██║   ██║██║██║      ██║  ██║  ██║██████╔╝ ╚████╔╝ \n"
        "██║   ██║██║██║██║  ██║ ██║██╔═══╝  ╚██╔╝ \n"
        "╚██████╔╝██║╚██████╔╝  ██║  ╚██████╔╝██║        ██║   \n"
        " ╚═════╝ ╚═╝ ╚═════╝  ╚═╝   ╚═════╝ ╚═╝        ╚═╝   \n"
    );
    Sleep(2000);
    score_wins++;
    printf("\nПеремоги: %d\n", score_wins);
    writeScore();
    Sleep(2000);
    resetGame();
}


int main() {

    SetConsoleOutputCP(65001); 
    SetConsoleCP(65001);
    srand(time(NULL));


    loadScore();
    printf("Поточний Рахунок: Перемоги: %d, Поразки: %d\n", score_wins, score_losses);
    
    printf("Встановіть символ гравця: ");
    scanf(" %c", &playerSymbol);
    

    resetGame(); 

    while (1) {
        int moves = 0; 
        char c;
        
        printf("--- ГРА ПОЧАТА ---\n");
        printf("Натисніть Enter для початку.\n");
        while ((getchar()) != '\n'); 

        while (1) {
            draw(moves); 
            printf("Ходи (w a s d), q для виходу: ");
            

            c = _getch(); 
            

            prevX = x;
            prevY = y;

            if (c == 'a') x--;
            else if (c == 'd') x++;
            else if (c == 'w') y--;
            else if (c == 's') y++;
            else if (c == 'q') {
                printf("\nГра завершена користувачем.\n");
                return 0; 
            }

            if (x < 0 || x >= GRID_WIDTH || y < 0 || y >= GRID_HEIGHT) {
                x = prevX; 
                y = prevY; 
            }
            

            if (isTreeAt(x, y)) {

                x = prevX;
                y = prevY;
            } else {

                moves++; 
            }


            if (moves >= MOVES_TO_WIN) {
                victory();
                break; 
            }


            moveEnemy();


            if (enemyX == x && enemyY == y) {
                gameOver();
                break;
            }

            Sleep(100); 
        }
    }

    return 0;
}