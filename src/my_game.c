/*
** EPITECH PROJECT, 2021
** My Hunter
** File description:
** my_game
*/

#include "my_rpg.h"

void load_images_xp(node_t **object_list)
{
    sfVector2f pos = {0, 0};
    sfIntRect rect = {0, 0, 150, 19};
    sfIntRect rect_xp = {0, 0, 0, 19};
    object_t *image = create_object("assets/bar.png", pos, rect_xp, 'x');
    object_t *image2 = create_object("assets/boarder.png", pos, rect, 'b');

    cly_node_push_back(object_list, image);
    cly_node_push_back(object_list, image2);
}

void load_images_life(node_t **object_list)
{
    sfVector2f pos = {0, 0};
    sfIntRect rect = {0, 0, 150, 19};
    object_t *image = create_object("assets/barre_1.png", pos, rect, 'l');
    object_t *image2 = create_object("assets/boarder.png", pos, rect, 'd');

    cly_node_push_back(object_list, image);
    cly_node_push_back(object_list, image2);
}

void initialize(game_t *game, node_t **object_list)
{
    create_map(object_list);
    create_player(object_list);
    load_images_life(object_list);
    load_images_xp(object_list);
    for (int i = 0; i < 100; i++)
        create_enemy(game, object_list);
}

int my_game(game_t *game, node_t **object_list)
{
    initialize(game, object_list);
    sfMusic_play(game->music_background);
    create_inventory(game, object_list);
    while (sfRenderWindow_isOpen(game->window)) {
        if (game->display_mode == 0)
            menu_loop(game, object_list);
        if (game->display_mode == 1) {
            set_zoom(game, 0.25f);
            game_loop(game, object_list);
        }
        if (game->display_mode == 2)
            option_menu(game, object_list);
    }
    cly_node_destroy(object_list, true);
    return 0;
}
