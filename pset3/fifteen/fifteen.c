#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

int tile_a;
int tile_b;
int blank_a;
int blank_b;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

void search(int tile);
bool legalmove(void);
void swaptile(int tile);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();

        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }

    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).
 */
void init(void)
// To Do
{
    // Determines how many slots are needed
    int n = (d*d) - 1;

    // Loop through the array with the columns first then the rows
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            board[i][j] = n;
            n--;
        }
        printf("\n");
    }

    // if the number of tiles are odd, the 1 and 2 are swaped
    if (((d*d) - 1) % 2 != 0)
    {
        int temp = board[d-1][d-2];
        board[d-1][d-2] = board[d-1][d-3];
        board[d-1][d-3] = temp;
    }

    // bottom right tile is to be marked as blank
    blank_a = d-1;
    blank_b = d-1;
}

/**
 * Prints the board in its current state.
 */
void draw(void)
// To do
{
    // Printing of the board itself
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] < 10)
            {
                if (board[i][j] == 0) //if the value is 0, it prints a blank tile
                {
                    printf(" [_] "); //printing a space denotes the free space without a tile
                }
                else
                {
                printf(" [%d] ", board[i][j]);
                }
            }
            else
            {
                printf("[%d] ", board[i][j]);
            }
        }
        printf("\n"); //space between each line
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false.
 */
bool move(int tile)
// To do
{
    // See if there even is a tile
    if (tile > (d*d)-1 || tile < 1)
        return false;

    // Linear search for tile that has been inputted
    search(tile);

    // if tile is found, see if blank space is next to it
    // detects the legitamacy of the blank space
    if (legalmove())
    {
        swaptile(tile); // if allowable, swaped the tile with the free space tile
        return true;
    }
    else
        return false;

    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration),
 * else false.
 */
bool won(void)
// To do
{
    // Performs a linear search of the array and verifies it is in ascending order
    int counter = 1;

    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] == counter)
                counter++;
        }
    }

    if (counter == d*d && board[d-1][d-1] == 0)
        return true;
    else
        return false;
}

// linear search of the tile
void search(int tile)
{
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (board[i][j] == tile)
            {
                tile_a = i;
                tile_b = j;
            }
        }
    }
}

// determines if the free space tile is next to the tile
bool legalmove(void)
{
    // checks top row, if true, check for 0
    if (tile_a > 0 && board[tile_a - 1][tile_b] == 0)
        return true;
    // bottom
    if (tile_a < d-1 && board[tile_a + 1][tile_b] == 0)
        return true;
    // left
    if (tile_b > 0 && board[tile_a][tile_b - 1] == 0)
        return true;
    // right
    if (tile_b < d-1 && board[tile_a][tile_b + 1] == 0)
        return true;
    else
        return false;
}

// swaps tile with blank tile
void swaptile(tile)
{
    int temp = board[tile_a][tile_b];
    board[tile_a][tile_b] = board[blank_a][blank_b];
    board[blank_a][blank_b] = temp;

    // update position of blank tile
    blank_a = tile_a;
    blank_b = tile_b;
}
