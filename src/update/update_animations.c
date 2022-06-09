/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** update_animation
*/

#include "my_rpg.h"

void update_animation(game_t *game, object_t *object)
{
    if (game->total_time < object->animation->next_time)
        return;
    object->rect.left += object->animation->offset;
    if (object->rect.left > object->animation->max)
        object->rect.left = 0;
    object->animation->next_time += object->animation->increment_time;
    sfSprite_setTextureRect(object->sprite, object->rect);
}

void update_animations(game_t *game, node_t **object_list)
{
    node_t *it = *object_list;
    object_t *obj;

    while (it != NULL) {
        obj = it->value;
        if (obj->animation != NULL)
            update_animation(game, obj);
        it = it->next;
    }
}
