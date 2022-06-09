/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** create_map.c
*/

#include "my_rpg.h"
#include <time.h>

void create_map(node_t **object_list)
{
    sfVector2f pos = {0, 0};
    sfIntRect rect = {0, 0, 3008, 3008};
    object_t *image = create_object(MAP, pos, rect, 'm');

    srand(time(NULL));
    cly_node_push_back(object_list, image);
}
