/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** on_enemy_die.c
*/

#include "my_rpg.h"

void add_xp(game_t *game, node_t **object_list)
{
    object_t *xp = get_by_type('x', object_list);
    xp->rect.width += 150 / (game->level * 2);
    if (xp->rect.width >= 150) {
        xp->rect.width = 0;
        on_level_up(game, object_list);
    }
}

void on_enemy_die(game_t *game, node_t **object_list, object_t *target)
{
    cly_node_pop_item(object_list, target);
    add_xp(game, object_list);
    for (int i = 0; i < 2; i++)
        create_enemy(game, object_list);
}