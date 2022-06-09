/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** move_enemy.c
*/

#include "my_rpg.h"
#include <time.h>

void rand_postion(int a, object_t *object)
{
    switch(a) {
        case 0:
            object->position.x += 1;
            object->rect.top = 130;
            break;
        case 1:
            object->position.y += 1;
            object->rect.top = 0;
            break;
        case 2:
            object->position.x -= 1;
            object->rect.top = 68;
            break;
        case 3:
            object->position.y -= 1;
            object->rect.top = 200;
            break;
    }
}

void move_enemy(node_t **object_list)
{
    node_t *loop_node = *object_list;
    object_t *object;
    int a = 0;

    srand(time(NULL));
    while (loop_node != NULL) {
        object = loop_node->value;
        if (object->type == 'c') {
            a = rand() % 3;
            rand_postion(a, object);
            object->rect.left += 50;
            if (object->rect.left == (50*3))
                object->rect.left = 50;
        }
        loop_node = loop_node->next;
    }
}
