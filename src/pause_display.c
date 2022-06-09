/*
** EPITECH PROJECT, 2022
** My Defender
** File description:
** pause_display
*/

#include "my_rpg.h"

void pause_loop(game_t *game, node_t **object_list)
{
    sfVector2f pos = {-455, -55};

    sfSprite_setPosition(game->pause.pause_sprite, pos);
    while (game->display_mode == 3 && sfRenderWindow_isOpen(game->window)) {
        update_events(game, object_list);
        sfRenderWindow_clear(game->window, sfBlack);
        sfRenderWindow_drawSprite(game->window, \
            game->pause.pause_sprite, NULL);
        sfRenderWindow_display(game->window);
    }
}
