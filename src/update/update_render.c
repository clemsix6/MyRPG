/*
** EPITECH PROJECT, 2021
** BootstrapMyRunner
** File description:
** update_render.c
*/

#include "my_rpg.h"

void display_object(game_t *game, object_t *object, int layer)
{
    if (object->layer != layer)
        return;
    sfSprite_setTextureRect(object->sprite, object->rect);
    sfSprite_setPosition(object->sprite, object->position);
    sfSprite_setScale(object->sprite, object->scale);
    sfRenderWindow_drawSprite(game->window, object->sprite, NULL);
}

void display_all_objects(game_t *game, node_t **object_list)
{
    node_t *loop_node = *object_list;
    object_t *object;

    for (int i = 0; i < 10; i++) {
        loop_node = *object_list;
        while (loop_node != NULL) {
            object = loop_node->value;
            display_object(game, object, i);
            loop_node = loop_node->next;
        }
    }
}

void update_render(game_t *game, node_t **object_list)
{
    sfRenderWindow_clear(game->window, game->clear_color);
    display_all_objects(game, object_list);
}
