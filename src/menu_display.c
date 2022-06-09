/*
** EPITECH PROJECT, 2021
** My Hunter
** File description:
** display_menu
*/

#include "my_rpg.h"

void clock_text(game_t *game, float seconds, sfClock *clock)
{
    sfRenderWindow_drawSprite(WINDOW, game->menu.menu_sprite2, NULL);
    if (seconds > 2.5f)
        sfClock_restart(clock);
}

void menu_loop(game_t *game, node_t **object_list)
{
    sfClock *clock;
    sfTime time;
    float seconds = 0.0f;
    clock = sfClock_create();

    while (game->display_mode == 0 && sfRenderWindow_isOpen(game->window)) {
        time = sfClock_getElapsedTime(clock);
        seconds = (float)time.microseconds / 1000000.0f;
        if (seconds > 1.0)
            clock_text(game, seconds, clock);
        else
            sfRenderWindow_drawSprite(WINDOW, game->menu.menu_sprite, NULL);
        update_events(game, object_list);
        sfRenderWindow_display(game->window);
    }
}
