/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** create_game.c
*/

#include "my_rpg.h"

void create_menu(menu_t *menu)
{
    menu->menu_texture = sfTexture_createFromFile(MENU1, NULL);
    menu->menu_sprite = sfSprite_create();
    sfSprite_setTexture(menu->menu_sprite, menu->menu_texture, sfTrue);
    menu->menu_texture2 = sfTexture_createFromFile(MENU2, NULL);
    menu->menu_sprite2 = sfSprite_create();
    sfSprite_setTexture(menu->menu_sprite2, menu->menu_texture2, sfTrue);
    ibtt_menu(menu);
}

void create_pause(pause_t *pause)
{
    pause->pause_texture = \
        sfTexture_createFromFile("assets/pause.jpeg", NULL);
    pause->pause_sprite = sfSprite_create();
    sfSprite_setTexture(pause->pause_sprite, pause->pause_texture, sfTrue);
    sfSprite_setPosition(pause->pause_sprite, pause->pauseback_vector);
    ibtt_pause(pause);
}

void create_settings(settings_t *set)
{
    set->settings_texture = sfTexture_createFromFile(BG_SETTINGS, NULL);
    set->settings_sprite = sfSprite_create();
    sfSprite_setTexture(set->settings_sprite, set->settings_texture, sfTrue);
}

game_t *create_game(unsigned int width, unsigned int height)
{
    sfVector2f viewSize = {(float)width, (float)height};
    sfVideoMode mode = {width, height, 32};
    sfRenderWindow *win;
    game_t *game = malloc(sizeof(game_t));

    win = sfRenderWindow_create(mode, TITLE, sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(win, 60);
    game->view = sfView_create();
    sfView_setSize(game->view, viewSize);
    game->level = 1;
    game->selected_slot = 0;
    game->display_mode = 0;
    game->window = win;
    game->clear_color = sfBlack;
    game->clock = sfClock_create();
    game->music_background = \
    sfMusic_createFromFile("assets/sound_background.ogg");
    create_menu(&game->menu);
    create_settings(&game->settings);
    create_pause(&game->pause);
    load_collisions(game);
    return game;
}
