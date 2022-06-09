/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** create_player.c
*/

#include "my_rpg.h"

void create_player(node_t **object_list)
{
    sfVector2f pos = {0, 0};
    sfIntRect rect = {0, 0, 43, 60};
    object_t *player = create_object(PLAYER, pos, rect, 'p');

    cly_node_push_back(object_list, player);
}
