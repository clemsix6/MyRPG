/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** on_level_up.c
*/

#include "my_rpg.h"

void give_item_1(game_t *game, node_t **object_list)
{
    sfVector2f pos = {0, 0};
    sfIntRect rect = {0, 0, 24, 24};
    object_t *knife = create_object("assets/knife/knife_1.png", pos, rect, ',');
    weapon_t *weapon = malloc(sizeof(weapon_t));

    weapon->damages = 2;
    knife->component = weapon;
    cly_node_push_back(object_list, knife);
    knife->layer = 9;
    add_item(game, knife);
}

void give_item_2(game_t *game, node_t **object_list)
{
    sfVector2f pos = {0, 0};
    sfIntRect rect = {0, 0, 24, 24};
    object_t *knife = create_object("assets/knife/knife_2.png", pos, rect, ',');
    weapon_t *weapon = malloc(sizeof(weapon_t));

    weapon->damages = 5;
    knife->component = weapon;
    cly_node_push_back(object_list, knife);
    knife->layer = 9;
    add_item(game, knife);
}

void give_item_3(game_t *game, node_t **object_list)
{
    sfVector2f pos = {0, 0};
    sfIntRect rect = {0, 0, 24, 24};
    object_t *knife = create_object("assets/knife/knife_3.png", pos, rect, ',');
    weapon_t *weapon = malloc(sizeof(weapon_t));

    weapon->damages = 10;
    knife->component = weapon;
    cly_node_push_back(object_list, knife);
    knife->layer = 9;
    add_item(game, knife);
}

void on_level_up(game_t *game, node_t **object_list)
{
    game->level++;
    if (game->level == 2)
        give_item_1(game, object_list);
    else if (game->level == 3)
        give_item_2(game, object_list);
    else if (game->level == 4)
        give_item_3(game, object_list);
}