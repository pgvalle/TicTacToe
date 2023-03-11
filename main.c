#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

///////////////////////////////////////////////////////////////////////////////
// BOARD //
///////////////////////////////////////////////////////////////////////////////

char board[9] = {
    '1', '2', '3',
    '4', '5', '6',
    '7', '8', '9'
};

bool is_board_full()
{
    for (int i = 0; i < 9; i++)
        if (board[i] == i + '1') return false;
    return true;
}

void print_board()
{
    printf("%c %c %c\n", board[6], board[7], board[8]);
    printf("%c %c %c\n", board[3], board[4], board[5]);
    printf("%c %c %c\n", board[0], board[1], board[2]);
}

char has_someone_won()
{
    if (board[0] == board[3] && board[3] == board[6])
        return board[0];
    if (board[1] == board[4] && board[4] == board[7])
        return board[1];
    if (board[2] == board[5] && board[5] == board[8])
        return board[2];

    if (board[0] == board[1] && board[1] == board[2])
        return board[0];
    if (board[3] == board[4] && board[4] == board[5])
        return board[3];
    if (board[6] == board[7] && board[7] == board[8])
        return board[6];

    if (board[0] == board[4] && board[4] == board[8])
        return board[0];
    if (board[2] == board[4] && board[4] == board[6])
        return board[2];

    return 0;
}

///////////////////////////////////////////////////////////////////////////////
// PLAYER STUFF //
///////////////////////////////////////////////////////////////////////////////

#define PLAYER_1 'X'
#define PLAYER_2 'O'

char winner = 0;

int play(char player)
{
    char c = 0;
    printf("Player %c, it is your turn: ", player);
    scanf("%c", &c);
    getchar();

    if (c > '9' || c < '1')
        return 0;
    if (board[c - '1'] != c)
        return 0;

    board[c - '1'] = player;
    return 1;
}

static inline
void clear_screen()
{
    printf(
        "\x1b[2J" // clear screen
        "\x1b[H"  // moves cursor to (0, 0)
    );
    fflush(stdout);
}

int main()
{
    // setup terminal window //

    #ifdef _WIN32
        system(""); // We gotta do this to make escape codes work in windows
    #endif

    printf(
        "\x1b[?1049h" // allow saving more information on current state of terminal
        "\x1b[?47h"   // save screen
        "\x1b[s"      // save cursor
    );
    clear_screen();

    // execution //

    bool running = !is_board_full(board) && !(winner = has_someone_won(board));
    char player = PLAYER_1;
    while (running)
    {
        clear_screen();
        print_board(board);
        while (running && !play(player));
        running = !is_board_full(board) && !(winner = has_someone_won(board));
        player = player == PLAYER_1 ? PLAYER_2 : PLAYER_1;
    }

    clear_screen();
    print_board(board);
    if (winner == 0)
        printf("Well... Looks like we got no winner.\n");
    else
        printf("Congratulations, player %c. You won!\n", winner);

    printf("Press any key to quit... ");
    getchar(); // game doesn't disappear out of the blue

    printf(
        "\x1b[u"      // restore cursor
        "\x1b[?47l"   // restore screen
        "\x1b[?1049l" // we don't need to store extra information anymore
    );
    fflush(stdout);

    return 0;
}