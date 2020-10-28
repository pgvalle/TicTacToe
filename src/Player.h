#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>

int Player_play(char* board, char player)
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

#endif // PLAYER_H defined