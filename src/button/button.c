/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** button
*/

#include "my_rpg.h"

int button_is_hover(game_t *game, sfIntRect rect, sfVector2f vector)
{
    game->mouse_position = sfMouse_getPositionRenderWindow(game->window);
    if (game->mouse_position.x >= vector.x && \
    game->mouse_position.x <= vector.x + rect.width\
    && game->mouse_position.y >= vector.y && \
    game->mouse_position.y <= vector.y + rect.height)
        return 1;
    else
        return 0;
}

void button_menu(game_t *game)
{
    if (button_is_hover(game, game->menu.rect_options, \
    game->menu.vector_options)) {
        game->display_mode = 2;
    }
    else if (button_is_hover(game, game->menu.rect_quit, \
    game->menu.vector_quit)) {
        sfRenderWindow_close(game->window);
    }
}

void button_pause(game_t *game)
{
    if (button_is_hover(game, game->pause.rect_resume,\
    game->pause.vector_resume)) {
        game->display_mode = 1;
    }
    else if (button_is_hover(game, game->pause.http_rect,\
    game->pause.http_vector)) {
        game->display_mode = 2;
    }
    else if (button_is_hover(game, game->pause.rect_quit,\
    game->pause.vector_quit)) {
        sfRenderWindow_close(game->window);
    }
}

void button_htp(game_t *game)
{
    if (button_is_hover(game, game->menu.rect_howtoplay_quit,\
    game->menu.vector_howtoplay_quit)) {
        game->display_mode = 0;
    }
}
