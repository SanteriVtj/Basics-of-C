#include "gameoflife.h"
#include <stdlib.h>
#include <stdio.h>


/* Exercise a: Allocates needed memory for the GameArea structure and
 * the actual game area. 'x_size' and 'y_size' indicate the horizontal and
 * vertical dimensions of the GameArea.
 * 
 * Returns: pointer to the GameArea structure allocated by this function.
 */

int contains(int x, int *l, int len) {
    for (int i = 0; i < len; i++) {
        if (l[i] == x) {
            return(1);
        }
    }
    return(0);
}

GameArea *createGameArea(unsigned int x_size, unsigned int y_size)
{
    GameArea *arena = malloc(sizeof(GameArea));
    arena->x_size = x_size;
    arena->y_size = y_size;
    arena->cells = malloc(y_size * sizeof(CellStatus *));
    for (unsigned int i = 0; i < x_size; i++) {
    	arena->cells[i] = malloc(sizeof(CellStatus) * x_size);
    }
    return(arena);
}

/* Free memory allocated for GameArea <a>.
 */
void releaseGameArea(GameArea *a)
{
    for (unsigned int i = 0; i < a->y_size; i++) {
    	free(a->cells[i]);
    }
    free(a->cells);
    free(a);
}

/* Exercise b: Initialize game GameArea by setting exactly <n> cells into
 * ALIVE CellStatus in the game GameArea <a>.
 */
void initGameArea(GameArea *a, unsigned int n)
{
    int arr[n];
    int j = 0;

    for (int i = 0; i < (a->x_size * a->y_size) && j < n; i++) {
        int ri = (a->x_size * a->y_size) - i;
        int rj = n - j;
        if (rand() % ri < rj) {
            arr[j++] = i;
        }
    }

    int sum_count = 0;
    for (int i = 0; i < a->y_size; i++) {
        for (j = 0; j < a->x_size; j++) {
            if (contains(sum_count, arr, n)) {
                a->cells[i][j] = ALIVE;
            } else {
                a->cells[i][j] = DEAD;
            }
            sum_count++;
        }
    }
}

/* Exercise c: Output the current CellStatus of GameArea <a>.
 */
void printGameArea(const GameArea *a)
{
    for (int i = 0; i < a->y_size; i++) {
        for (int j = 0; j < a->x_size; j++) {
            switch(a->cells[i][j]) {
                case DEAD:
                    printf("%c", '.');
                    break;
                case ALIVE:
                    printf("%c", '*');
                    break;
            }
        }
        printf("\n");
    }
}

/* Calculates number of live neighbours around position (x,y),
 * and returns the count.
 */

int inside(int x, int y, const GameArea *a) {
    if (x >= 0 && y >= 0 && x < a->x_size && y < a->y_size) {
        return (1);
    }
    return(0);
}

unsigned int live_neighbours(const GameArea *a, unsigned int x, unsigned int y)
{
    unsigned int lc = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (!(i == 0 && j == 0) && inside(x+j, y+i, a) == 1) {
                switch (a->cells[y+i][x+j])
                {
                case ALIVE:
                    lc++;
                    break;
                
                default:
                    break;
                }
            }
        }
    }
    return(lc);
}

/* Exercise d: Advance GameArea <a> by one generation.
 */
void gameTick(GameArea *a)
{
    GameArea *copy = createGameArea(a->x_size, a->y_size);
    for (int i = 0; i < a->y_size; i++) {
        for (int j = 0; j < a->x_size; j++) {
            copy->cells[i][j] = a->cells[i][j];
        }
    }

    for (int i = 0; i < a->y_size; i++) {
        for (int j = 0; j < a->x_size; j++) {
            int count = live_neighbours(copy, j, i);
            switch (copy->cells[i][j])
            {
            case ALIVE:
                if (count == 2 || count == 3 ) {
                    a->cells[i][j] = ALIVE;
                } else {
                    a->cells[i][j] = DEAD;
                }
                break;
            
            default:
                if (count == 3) {
                    a->cells[i][j] = ALIVE;
                } else {
                    a->cells[i][j] = DEAD;
                }
                break;
            }
        }
    }
    releaseGameArea(copy);
}
