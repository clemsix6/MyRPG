/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** bubble.c
*/

#include "my_rpg.h"

void create_bubble(game_t *game, node_t **object_list, sfVector2f pos)
{
    sfIntRect rect = {0, 0, 775, 380};
    object_t *image_bubble = create_object("assets/bulle.png", pos, rect, 'x');
    cly_node_push_back(object_list, image_bubble);
    game->font = sfFont_createFromFile("assets/police_bulle.ttf");
}

void bubble_chat(game_t *game, char *str, sfVector2f pos)
{
    sfText_setString(game->text, str);
    sfText_setFont(game->text, game->font);
    sfText_setCharacterSize(game->text, 50);
    sfRenderWindow_drawText(game->window, game->text, NULL);
}

void destroy_bubble(node_t **object_list, game_t *game)
{
    sfText_destroy(game->text);
    sfFont_destroy(game->font);
}