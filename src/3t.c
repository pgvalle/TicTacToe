#include <stdlib.h>
#include "Board.h"
#include "Player.h"

#define PLAYER_1 'X'
#define PLAYER_2 'O'

int main() {
    /// variables ///
    // board declaration
    char board[9] = {
        '1', '2', '3', '4', '5', '6', '7', '8', '9'
    };
    // say who won
    char winner = 0;
    // keep track whether the game should be running
    short shouldRun = !Board_isFull(board) && !(winner = Board_PlayerWon(board));

    // gameloop
    while (shouldRun)
    {
        system("clear");
        Board_print(board);
        while (shouldRun && !Player_play(board, PLAYER_1));
        shouldRun = !Board_isFull(board) && !(winner = Board_PlayerWon(board));

        system("clear");
        Board_print(board);
        while (shouldRun && !Player_play(board, PLAYER_2));
        shouldRun = !Board_isFull(board) && !(winner = Board_PlayerWon(board));
    }

    system("clear");
    Board_print(board);
    printf("Winner is ");
    if (winner == 0)
        printf("nobody!\n");
    else
        printf("player %c!\n", winner);

    return 0;
}