/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** update_inventory.c
*/

#include "my_rpg.h"

int get_inventory_size(game_t *game)
{
    int i = 0;

    while (game->inventory[i] != NULL)
        i++;
    return i;
}

void update_slot(object_t *slot_obj ,slot_t *slot)
{
    if (slot->item == NULL)
        return;
    slot->item->position = slot_obj->position;
}

void update_inventory(game_t *game, node_t **object_list)
{
    int inventory_size = get_inventory_size(game);
    object_t *player = get_by_type('p', object_list);
    float middle = (float)inventory_size / 2.0f;
    slot_t *slot;

    if (game->selected_slot >= inventory_size)
        game->selected_slot = 0;
    for (int i = 0; i < inventory_size; i++) {
        game->inventory[i]->position.x = \
            player->position.x + (((float)(i + 1) - middle) * 40) - 15;
        game->inventory[i]->position.y = player->position.y + 90;
        game->inventory[i]->rect.left = \
            game->selected_slot == i ? 30 : 0;
        slot = game->inventory[i]->component;
        update_slot(game->inventory[i], slot);
    }
}
