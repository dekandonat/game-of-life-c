#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

char **generateGrid(int n)
{
    char **grid = malloc(sizeof(char *) * n);
    for (int i = 0; i < n; i++)
    {
        grid[i] = malloc(sizeof(char *) * n);
    }

    return grid;
}

void fillGrid(char **grid, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (rand() % 100 < 25)
            {
                grid[i][j] = '#';
            }
            else
            {
                grid[i][j] = '.';
            }
        }
    }
}

void printGrid(char **grid, int n)
{
    printf("\033[H\033[J");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

char GetCell(char **grid, int n, int a, int b)
{
    if (a < 0 || a >= n || b < 0 || b >= n)
    {
        return '.';
    }

    return grid[a][b];
}

void calculateElement(char **grid, int n, int a, int b, char **tempGrid)
{
    int isAlive = (GetCell(grid, n, a, b) == '#');
    int aliveCount = 0;
    int deadCount = 0;

    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (j == 0 && i == 0)
                continue;

            if (GetCell(grid, n, i + a, j + b) == '#')
            {
                aliveCount++;
            }
            else
            {
                deadCount++;
            }
        }
    }

    if ((aliveCount != 2 && aliveCount != 3) && isAlive)
    {
        isAlive = 0;
    }
    else if (!isAlive && aliveCount == 3)
    {
        isAlive = 1;
    }

    if (isAlive)
    {
        tempGrid[a][b] = '#';
    }
    else
    {
        tempGrid[a][b] = '.';
    }
}

void startLife(char **grid, int n, char **tempGrid)
{
    while (1)
    {
        if (_kbhit())
        {
            char key = _getch();
            if (key == 'q')
            {
                break;
            }
        }

        printGrid(grid, n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                calculateElement(grid, n, i, j, tempGrid);
            }
        }
        Sleep(500);
        char **temp = grid;
        grid = tempGrid;
        tempGrid = temp;
    }
}

void freeGrid(char **grid, int n)
{
    for (int i = 0; i < n; i++)
    {
        free(grid[i]);
    }
    free(grid);
}

int main()
{
    printf("Give the size of te grid: ");
    int n;
    scanf("%d", &n);

    char **grid = generateGrid(n);
    char **tempGrid = generateGrid(n);

    fillGrid(grid, n);
    startLife(grid, n, tempGrid);

    freeGrid(grid, n);
    freeGrid(tempGrid, n);

    return 0;
}
