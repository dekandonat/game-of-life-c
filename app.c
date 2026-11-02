#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

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

void startLife(char **grid, int n)
{
}

int main()
{
    printf("Give the size of te grid: ");
    int n;
    scanf("%d", &n);

    char **grid = generateGrid(n);
    char **tempGrid = generateGrid(n);

    fillGrid(grid, n);
    return 0;
}
