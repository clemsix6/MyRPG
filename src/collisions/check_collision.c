/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** check_collision.c
*/

#include "my_rpg.h"

bool check_point(game_t *game, int x, int y)
{
    return game->collisions[y / 16][x / 16] == '0';
}

bool check_line(game_t *game, sfIntRect *rect, int y)
{
    for (int x = 0; x < rect->width; x++) {
        if (!check_point(game, x + rect->left, y + rect->top))
            return false;
    }
    return true;
}

bool check_collision(game_t *game, sfIntRect *rect)
{
    for (int y = 0; y < rect->height; y++) {
        if (!check_line(game, rect, y))
            return false;
    }
    return true;
}
