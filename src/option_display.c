/*
** EPITECH PROJECT, 2022
** myrpg
** File description:
** option_menu.c
*/

#include "my_rpg.h"

void update_render(game_t *game, node_t **object_list);

void option_menu(game_t *game, node_t **object_list)
{
    while (game->display_mode == 2 && sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_drawSprite(WINDOW, game->settings.settings_sprite, NULL);
        update_events(game, object_list);
        sfRenderWindow_display(game->window);
    }
}
