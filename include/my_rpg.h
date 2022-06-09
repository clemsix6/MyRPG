/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** main header
*/

#ifndef MYRPG_H
    #define MYRPG_H
    #define UNUSED() __attribute__((unused))
    #define WINDOW game->window
    #define MENU1 "assets/my_menu.jpeg"
    #define MENU2 "assets/my_menu2.jpeg"
    #define BG_SETTINGS "assets/howtoplay.jpeg"
    #define TITLE "Grand Thet Auto"
    #define X_PLAYER player->position.x
    #define Y_PLAYER player->position.y
    #define X_CLODO enemy->position.x
    #define Y_CLODO enemy->position.y
    #define X_CLODO enemy->position.x
    #define Y_CLODO enemy->position.y
    #define H_CLODO enemy->rect.height
    #define W_CLODO enemy->rect.width
    #define PLAYER "assets/main.png"
    #define CLODO "assets/mechant.png"
    #define MAP "assets/map.png"
    #include "cly/cly_io.h"
    #include "cly/cly_lib.h"
    #include "cly/cly_string.h"
    #include "cly/cly_linked_list.h"
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include "pause.h"
    #include "particle.h"
    #include "menu.h"

typedef struct animation_s {
    int offset;
    int max;
    float next_time;
    float increment_time;
} animation_t;

typedef struct object_s {
    char type;
    sfVector2f position;
    sfVector2f scale;
    sfIntRect rect;
    sfTexture *texture;
    sfSprite *sprite;
    animation_t *animation;
    void *component;
    int layer;
} object_t;

typedef struct game_s {
    int display_mode;
    double time;
    double delta_time;
    float total_time;
    char tower_type;
    char **collisions;
    object_t **inventory;
    int selected_slot;
    int level;
    menu_t menu;
    settings_t settings;
    pause_t pause;
    sfRenderWindow* window;
    sfMusic *music_background;
    sfColor clear_color;
    sfClock *clock;
    sfVector2i mouse_position;
    sfView *view;
    particle_t particle[PARICULE_MAX];
    particle_environment_t particle_environment;
    particle_rain_t particle_rain[PARICULE_MAX*10];
    particle_environment_rain_t particle_environment_rain;
    object_t *image_bubble;
    sfFont *font;
    sfText *text;
} game_t;

typedef struct slot_s {
    object_t *item;
} slot_t;

typedef struct enemy_s {
    int hp;
} enemy_t;

typedef struct weapon_s {
    int damages;
} weapon_t;

int my_game(game_t *game, node_t **object_list);
void menu_loop(game_t *game, node_t **object_list);
void game_loop(game_t *game, node_t **object_list);
void pause_loop(game_t *game, node_t **object_list);
void option_menu(game_t *game, node_t **object_list);

void button_menu(game_t *game);
void button_pause(game_t *game);
void button_htp(game_t *game);

void move_enemy(node_t **object_list);
int load_map(node_t **object_list, const char *filepath);

void destroy_object(node_t **object_list, object_t *object);
void destroy_game(game_t *game, node_t **object_list);
object_t *create_object(const char *sprite_path,
    sfVector2f pos,
    sfIntRect rect,
    char type);
game_t *create_game(unsigned int width, unsigned int height);
void update_events(game_t *game, node_t **object_list);
void update_render(game_t *game, node_t **object_list);
void update_animations(game_t *game, node_t **object_list);
void move(game_t *game, node_t **object_list, int x, int y);
object_t *get_by_type(char type, node_t **object_list);
char *read_file(const char *filepath);
void load_collisions(game_t *game);
void set_zoom(game_t *game, float scale);
bool check_collision(game_t *game, sfIntRect *rect);
void create_inventory(game_t *game, node_t **object_list);
void update_inventory(game_t *game, node_t **object_list);
void create_enemy(game_t *game, node_t **object_list);
void create_player(node_t **object_list);
void create_map(node_t **object_list);
void on_hit(game_t *game, node_t **object_list);
void on_hit_enemy(game_t *game, node_t **object_list, object_t *target);
void on_enemy_die(game_t *game, node_t **object_list, object_t *target);
void on_level_up(game_t *game, node_t **object_list);
bool add_item(game_t *game, object_t *item);

#endif /* !MYRPG_H */
