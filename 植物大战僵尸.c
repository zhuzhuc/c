
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define ROWS 5
#define COLS 9

typedef struct {
    int type;  // 植物类型
    int health;  // 生命值
    int attack;  // 攻击力
} Plant;

typedef struct {
    int type;  // 僵尸类型
    int health;  // 生命值
    int attack;  // 攻击力
} Zombie;

typedef struct {
    Plant plants[COLS];  // 存储植物的数组
    Zombie zombies[COLS];  // 存储僵尸的数组
} GameBoard;

void initBoard(GameBoard *board) {
    for (int i = 0; i < COLS; i++) {
        board->plants[i].type = -1;
        board->zombies[i].type = -1;
    }
}

void printBoard(GameBoard *board) {
    printf("  ");
    for (int i = 0; i < COLS; i++) {
        printf("%d ", i+1);
    }
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d ", i+1);
        for (int j = 0; j < COLS; j++) {
            if (board->plants[j].type != -1 && i == 0) {
                printf("P ");
            } else if (board->zombies[j].type != -1 && i == ROWS-1) {
                printf("Z ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

void placePlant(GameBoard *board, int col, int type) {
    if (board->plants[col-1].type == -1) {
        Plant newPlant;
        newPlant.type = type;
        newPlant.health = 100;
        newPlant.attack = 10;
        board->plants[col-1] = newPlant;
    }
}

void placeZombie(GameBoard *board, int col, int type) {
    if (board->zombies[col-1].type == -1) {
        Zombie newZombie;
        newZombie.type = type;
        newZombie.health = 100;
        newZombie.attack = 5;
        board->zombies[col-1] = newZombie;
    }
}

void updateBoard(GameBoard *board) {
    // 植物攻击僵尸
    for (int i = 0; i < COLS; i++) {
        if (board->plants[i].type != -1 && board->zombies[i].type != -1) {
            board->zombies[i].health -= board->plants[i].attack;
            if (board->zombies[i].health <= 0) {
                board->zombies[i].type = -1;
            }
        }
    }
    
    // 僵尸攻击植物
    for (int i = 0; i < COLS; i++) {
        if (board->plants[i].type != -1 && board->zombies[i].type != -1) {
            board->plants[i].health -= board->zombies[i].attack;
            if (board->plants[i].health <= 0) {
                board->plants[i].type = -1;
            }
        }
    }
}

int main() {
    GameBoard board;
    initBoard(&board);
    
    while (1) {
        system("cls");  // 清屏
        
        printf("Welcome to Plants vs. Zombies!\n");
        printf("Place plants (1-%d): ", COLS);
        int plantCol;
        scanf("%d", &plantCol);
        placePlant(&board, plantCol, 0);  // 这里只实现了一种植物类型，你可以自定义更多类型
        
        printf("Place zombies (1-%d): ", COLS);
        int zombieCol;
        scanf("%d", &zombieCol);
        placeZombie(&board, zombieCol, 0);  // 这里只实现了一种僵尸类型，你可以自定义更多类型
        
        updateBoard(&board);
        printBoard(&board);
        
        if (board.zombies[COLS-1].type != -1) {
            printf("Game Over! Zombies Win!\n");
            break;
        }
    }
}