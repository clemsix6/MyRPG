/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** get_object.c
*/

#include "my_rpg.h"

object_t *get_by_type(char type, node_t **object_list)
{
    node_t *loop_node = *object_list;
    object_t *object;

    while (loop_node != NULL) {
        object = loop_node->value;
        if (object->type == type)
            return object;
        loop_node = loop_node->next;
    }
    return NULL;
}
