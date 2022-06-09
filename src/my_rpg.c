/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** main file
*/

#include "my_rpg.h"

int print_h(void)
{
    cly_write(1, "USAGE\n");
    cly_write(1, "Game\n");
    cly_write(1, "DESCRIPTION\n");
    cly_write(1, "    Your task is to catch as many bear as you can\n");
    cly_write(1, "    in this game.\n");
    return 0;
}

int main(int argc, char **argv)
{
    node_t *null_node = NULL;
    node_t **object_list = &null_node;
    game_t *game = create_game(1920, 1080);
    init_particle_environment(&game->particle_environment, (sfVector2f){PARICULE_ANGLE_MIN, PARICULE_ANGLE_MAX}, (sfVector2f){GRAVITY_X, GRAVITY_Y}, ALPHA);
    init_particle_environment_rain(&game->particle_environment_rain, \
    (sfVector2f){PARICULE_ANGLE_MIN, PARICULE_ANGLE_MAX}, \
    (sfVector2f){GRAVITY_X, GRAVITY_Y}, ALPHA);
    if (argc == 1) {
        return my_game(game, object_list);
    } else if (cly_strcmp(argv[1], "-h") == 0 && argc == 2) {
        return print_h();
    } else {
        return 84;
    }
    return 0;
}
