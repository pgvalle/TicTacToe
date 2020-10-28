#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>

int Board_isFull(char* board) {
    short i;
    for (i = 0; i < 9 && board[i] != i + '1'; i++);
    return i == 9;
}

void Board_print(char* board) {
    printf("%c %c %c\n", board[6], board[7], board[8]);
    printf("%c %c %c\n", board[3], board[4], board[5]);
    printf("%c %c %c\n", board[0], board[1], board[2]);
}

char Board_PlayerWon(char* board)
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

#endif // BOARD_H defined