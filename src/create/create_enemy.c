/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** create_enemy.c
*/

#include "my_rpg.h"

void create_enemy(game_t *game, node_t **object_list)
{
    sfVector2f pos_clodo = {rand() % 3008, rand() % 3008};
    sfIntRect rect_clodo = {0, 0, 43, 60};
    object_t *clodo = create_object(CLODO, pos_clodo, rect_clodo, 'c');
    enemy_t *enemy = malloc(sizeof(enemy_t));

    enemy->hp = game->level + 2;
    clodo->component = enemy;
    cly_node_push_back(object_list, clodo);
}
