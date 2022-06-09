/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** load_collisions.c
*/

#include "my_rpg.h"

void load_collisions(game_t *game)
{
    char *buffer = read_file("assets/collisions.txt");
    char **map = cly_to_wordarray(buffer, '\n');

    game->collisions = map;
}
