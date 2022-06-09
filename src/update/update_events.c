/*
** EPITECH PROJECT, 2021
** MyRPG
** File description:
** update_events.c
*/

#include "my_rpg.h"

void menu_event(game_t *game, sfEvent event, node_t **object_list)
{
    if (event.type == sfEvtClosed)
        destroy_game(game, object_list);
    else if (event.type == sfEvtMouseButtonPressed)
        button_menu(game);
    else if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyEscape)
            destroy_game(game, object_list);
        else
            game->display_mode = 1;
    }
    if (event.type == sfEvtKeyPressed)
        game->display_mode = 1;
}

void htp_event(game_t *game, sfEvent event, node_t **object_list)
{
    if (event.type == sfEvtClosed)
        destroy_game(game, object_list);
    else if (event.type == sfEvtMouseButtonPressed)
        button_htp(game);
    else if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyEscape)
            destroy_game(game, object_list);
    }
}

void game_event(game_t *game, sfEvent event, node_t **object_list)
{
    if (event.type == sfEvtClosed)
        destroy_game(game, object_list);
    else if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyP) {
            game->display_mode = 3;
        }
        if (event.key.code == sfKeyUp) {
            move(game, object_list, 0, -1);
        }
        if (event.key.code == sfKeyDown) {
            move(game, object_list, 0, 1);
        }
        if (event.key.code == sfKeyRight) {
            move(game, object_list, 1, 0);
        }
        if (event.key.code == sfKeyLeft) {
            move(game, object_list, -1, 0);
        }
        if (event.key.code == sfKeyA) {
            on_hit(game, object_list);
        }
        if (event.key.code == sfKeySpace) {
            game->selected_slot += 1;
        }
    }
}

void pause_event(game_t *game, sfEvent event, node_t **object_list)
{
    if (event.type == sfEvtClosed)
        destroy_game(game, object_list);
    else if (event.type == sfEvtMouseButtonPressed)
        button_pause(game);
    else if (event.type == sfEvtKeyPressed) {
        if (event.key.code == sfKeyEscape) {
            destroy_game(game, object_list);
        }
    }
}

void update_events(game_t *game, node_t **object_list)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (game->display_mode == 0)
            menu_event(game, event, object_list);
        if (game->display_mode == 1)
            game_event(game, event, object_list);
        if (game->display_mode == 2)
            htp_event(game, event, object_list);
        if (game->display_mode == 3)
            pause_event(game, event, object_list);
    }
}
