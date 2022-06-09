/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** move.c
*/

#include "my_rpg.h"

int direction_player(int x, int y)
{
    if (x == 0 && y == -1)
        return 200;
    if (x == 0 && y == 1)
        return 0;
    if (x == -1 && y == 0)
        return 68;
    if (x == 1 && y == 0)
        return 130;
    return 0;
}

void move_player(game_t *game, object_t *player, int x, int y)
{
    sfVector2f pos = sfView_getCenter(game->view);

    pos.x += (float)(x * 1000 * game->delta_time);
    pos.y += (float)(y * 1000 * game->delta_time);
    player->rect.top = direction_player(x, y);
    player->rect.left += 50;
    if (player->rect.left == (50*3))
        player->rect.left = 50;
    player->position = pos;
}

void move(game_t *game, node_t **object_list, int x, int y)
{
    object_t *player = get_by_type('p', object_list);
    object_t *xp = get_by_type('x', object_list);
    object_t *boarder = get_by_type('b', object_list);
    object_t *boarder2 = get_by_type('d', object_list);
    object_t *life  = get_by_type('l', object_list);
    sfVector2f pos = player->position;
    sfIntRect rect;

    move_player(game, player, x, y);
    xp->position.x = player->position.x + 70;
    xp->position.y = player->position.y - 100;
    boarder->position.x = player->position.x + 70;
    boarder->position.y = player->position.y - 100;
    life->position.x = player->position.x + 70;
    life->position.y = player->position.y - 130;
    boarder2->position.x = player->position.x + 70;
    boarder2->position.y = player->position.y - 130;
    rect = player->rect;
    rect.left = (int)player->position.x;
    rect.top = (int)player->position.y;
    if (!check_collision(game, &rect))
        player->position = pos;
    sfView_setCenter(game->view, player->position);
    sfRenderWindow_setView(game->window, game->view);
}

void set_zoom(game_t *game, float scale)
{
    sfView_zoom(game->view, scale);
    sfRenderWindow_setView(game->window, game->view);
}
