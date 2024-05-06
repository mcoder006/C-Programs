#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
#define FRUIT 'F'
#define SNAKE 'O'
#define BORDER '#'
#define SLEEP_TIME 100

int gameOver;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
char direction;

void Setup()
{
    gameOver = 0;
    direction = RIGHT;
    x = WIDTH / 2;
    y = HEIGHT / 2;
    fruitX = rand() % WIDTH;
    fruitY = rand() % HEIGHT;
    score = 0;
}

void Draw()
{
    // Create a static buffer to store the current state of the game
    static char buffer[HEIGHT][WIDTH];

    // Clear the buffer
    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++)
            buffer[i][j] = ' ';

    // Draw the snake
    buffer[y][x] = SNAKE;
    for (int i = 0; i < nTail; i++)
        buffer[tailY[i]][tailX[i]] = 'o';

    // Draw the fruit
    buffer[fruitY][fruitX] = FRUIT;

    // Draw the borders
    for (int i = 0; i < WIDTH + 2; i++)
        buffer[0][i] = buffer[HEIGHT - 1][i] = BORDER;
    for (int i = 1; i < HEIGHT - 1; i++)
        buffer[i][0] = buffer[i][WIDTH - 1] = BORDER;

    // Draw the score
    sprintf(&buffer[0][WIDTH + 2], "Score:%d", score);

    // Print the buffer to the console
    system("cls");
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH + 2 + 7; j++)
            printf("%c", buffer[i][j]);
        printf("\n");
    }
}

void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case UP:
            if (direction != DOWN)
                direction = UP;
            break;
        case DOWN:
            if (direction != UP)
                direction = DOWN;
            break;
        case LEFT:
            if (direction != RIGHT)
                direction = LEFT;
            break;
        case RIGHT:
            if (direction != LEFT)
                direction = RIGHT;
            break;
        case 'x':
            gameOver = 1;
            break;
        }
    }
}

void Logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    int i; // Move variable declaration outside the loop
    for (i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (direction)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

    // Check for collision with boundaries
    if (x >= WIDTH || x < 0 || y >= HEIGHT || y < 0)
        gameOver = 1;

    // Check for collision with fruit
    if (x == fruitX && y == fruitY)
    {
        score += 10;
        fruitX = rand() % WIDTH;
        fruitY = rand() % HEIGHT;
        nTail++;
    }

    // Check for collision with tail
    for (i = 0; i < nTail; i++)
    {
        if (tailX[i] == x && tailY[i] == y)
            gameOver = 1;
    }
}

int main()
{
    srand(time(0));
    Setup();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(SLEEP_TIME);
    }

    printf("Developed By: Sushank Ghimire\n\n");
    return 0;
}


