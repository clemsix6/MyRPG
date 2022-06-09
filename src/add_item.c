/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** add_item.c
*/

#include "my_rpg.h"

bool add_item(game_t *game, object_t *item)
{
    slot_t *slot;

    for (int i = 0; game->inventory[i] != NULL; i++) {
        slot = game->inventory[i]->component;
        if (slot->item == NULL) {
            slot->item = item;
            return true;
        }
    }
    return false;
}
