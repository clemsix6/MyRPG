/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** create_inventory.c
*/

#include "my_rpg.h"

void create_inventory(game_t *game, node_t **object_list)
{
    const int inventory_size = 3;
    object_t **slots = malloc(sizeof(object_t *) * (inventory_size + 1));
    sfVector2f pos = {0, 0};
    sfIntRect rect = {0, 0, 30, 30};
    slot_t *slot;

    for (int i = 0; i < inventory_size; i++) {
        slots[i] = create_object("assets/inventory.png", pos, rect, '&');
        slots[i]->layer = 4;
        slot = malloc(sizeof(slot_t *));
        slot->item = NULL;
        slots[i]->component = slot;
        cly_node_push_back(object_list, slots[i]);
    }
    slots[inventory_size] = NULL;
    game->inventory = slots;
}
