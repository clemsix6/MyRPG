/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** on_enemy_hit.c
*/

#include "my_rpg.h"

int get_damages(game_t *game) {
    object_t *slot_obj = game->inventory[game->selected_slot];
    slot_t *slot = slot_obj->component;
    weapon_t *weapon;

    if (slot->item == NULL)
        return 1;
    weapon = slot->item->component;
    if (weapon == NULL)
        return 1;
    return weapon->damages;
}

void on_hit_enemy(game_t *game, node_t **object_list, object_t *target)
{
    enemy_t *enemy = target->component;

    if (enemy == NULL)
        return;
    enemy->hp -= get_damages(game);
    if (enemy->hp <= 0)
        on_enemy_die(game, object_list, target);
}
