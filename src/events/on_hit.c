/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** on_hit.c
*/

#include "my_rpg.h"

bool hitbox(object_t *enemy, object_t *player)
{
    if (Y_PLAYER >= Y_CLODO - 10 && Y_PLAYER <= Y_CLODO + H_CLODO + 10) {
        if (X_PLAYER >= X_CLODO - 10 && X_PLAYER <= X_CLODO + W_CLODO + 10)
            return true;
    }
    return false;
}

object_t *get_enemy(node_t **object_list)
{
    node_t *loop_node = *object_list;
    object_t *enemy;
    object_t *player = get_by_type('p', object_list);

    while (loop_node != NULL) {
        enemy = loop_node->value;
        if (enemy->type == 'c' && hitbox(enemy, player))
            return enemy;
        loop_node = loop_node->next;
    }
    return NULL;
}

void on_hit(game_t *game, node_t **object_list)
{
    object_t *target = get_enemy(object_list);
    if (target == NULL)
        return;
    sfVector2f pos = target->position;
    add_particle(&game->particle_environment, game->particle, \
    20, (sfVector2f){pos.x, pos.y});
    on_hit_enemy(game, object_list, target);
}
