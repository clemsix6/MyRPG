/*
** EPITECH PROJECT, 2022
** My Defender
** File description:
** game_display
*/

#include "my_rpg.h"
#include "menu.h"
#include <time.h>

void update_time(game_t *game)
{
    sfTime time = sfClock_getElapsedTime(game->clock);
    float total_time = (float)((double)time.microseconds / 1000000.0);
    game->delta_time = total_time - game->total_time;
    game->total_time = total_time;
}

void check_pause(game_t *game, node_t **object_list)
{
    if (game->display_mode == 3) {
        set_zoom(game, 4);
        game->pause.pauseback_vector.x = 0;
        game->pause.pauseback_vector.y = 0;
        sfSprite_setPosition(game->pause.pause_sprite,\
        game->pause.pauseback_vector);
        pause_loop(game, object_list);
    }
}

void life(game_t *game UNUSED(), node_t **object_list)
{
    sfClock *clock = sfClock_create();
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds =  0.0;
    seconds = time.microseconds / 10000.0;
    object_t *object = get_by_type('l', object_list);
    if (seconds > 1.0) {
        sfClock_restart(clock);
        object->rect.width -= 1;
    }

}

void display_all_particle(game_t *game)
{
    for (size_t index = 0; index != PARICULE_MAX; index++)
        update_particle(&game->particle_environment, &game->particle[index]);
    for (size_t index = 0; index != PARICULE_MAX; index++)
        display_particle(game->window, &game->particle[index], \
        game->particle_environment.circle_shape);
    for (size_t index = 0; index != PARICULE_MAX*10; index++)
        update_particle_rain(&game->particle_environment_rain, \
        &game->particle_rain[index]);
    for (size_t index = 0; index != PARICULE_MAX*10; index++)
        display_particle_rain(game->window, &game->particle_rain[index], \
        game->particle_environment_rain.rectangle_shape);
}

void game_loop(game_t *game, node_t **object_list)
{
    sfTime time;
    while (game->display_mode != 0 && sfRenderWindow_isOpen(game->window)) {
        add_particle_rain(&game->particle_environment_rain, game->particle_rain, \
    20, (sfVector2f){rand() % 1920, -100});
        check_pause(game, object_list);
        time = sfClock_getElapsedTime(game->clock);
        sfClock_restart(game->clock);
        game->delta_time = (double)time.microseconds / 1000000.0;
        game->time += game->delta_time;
        move_enemy(object_list);
        life(game, object_list);
        update_events(game, object_list);
        update_inventory(game, object_list);
        update_render(game, object_list);
        display_all_particle(game);
        sfRenderWindow_display(game->window);
    }
}
