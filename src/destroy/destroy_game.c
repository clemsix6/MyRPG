/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** destroy_game
*/

#include "my_rpg.h"

void destroy_objects(node_t **object_list)
{
    node_t *it = *object_list;
    object_t *obj;

    while (it != NULL) {
        obj = it->value;
        destroy_object(object_list, obj);
        it = it->next;
    }
}

void destroy_game(game_t *game, node_t **object_list)
{
    sfClock_destroy(game->clock);
    sfRenderWindow_close(game->window);
    destroy_objects(object_list);
}
