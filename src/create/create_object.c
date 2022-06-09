/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** create_object.c
*/

#include "my_rpg.h"

object_t *init_object(sfSprite *sprite, sfTexture *texture,
sfVector2f pos, sfIntRect rect)
{
    object_t *object = malloc(sizeof(object_t));
    sfVector2f scale = {1, 1};

    sfSprite_setTexture(sprite, texture, sfTrue);
    object->position = pos;
    object->scale = scale;
    object->rect = rect;
    object->texture = texture;
    object->sprite = sprite;
    return object;
}

object_t *create_object(const char *sprite_path,
    sfVector2f pos,
    sfIntRect rect,
    char type)
{
    object_t *object;
    sfTexture *texture;
    sfSprite *sprite;

    texture = sfTexture_createFromFile(sprite_path, NULL);
    if (texture == NULL)
        return NULL;
    sprite = sfSprite_create();
    if (sprite == NULL) {
        sfTexture_destroy(texture);
        return NULL;
    }
    object = init_object(sprite, texture, pos, rect);
    object->type = type;
    object->layer = 1;
    object->animation = NULL;
    return object;
}
