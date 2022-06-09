/*
** EPITECH PROJECT, 2022
** Particle
** File description:
** particle
*/

#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <math.h>           // cos() & sin()
#include <stdlib.h>         // exit()
#include <stdbool.h>        // bool
#include <string.h>         // memeset()

#define PARICULE_ANGLE_MIN (0)
#define PARICULE_ANGLE_MAX (M_PI * 2)
#define GRAVITY_X (1.0f * 0)
#define GRAVITY_Y (1.0f * 0)
#define ALPHA (1)

#define PARICULE_MAX (10000)
#define SPEED (3.0f)

typedef struct particle_environment_s particle_environment_t;
typedef struct particle_s particle_t;
typedef struct particle_environment_rain_s particle_environment_rain_t;
typedef struct particle_rain_s particle_rain_t;

struct particle_s
{
    sfVector2f pos;
    sfVector2f vel;
    sfColor color;
    size_t radius;
    bool living;
};

struct particle_environment_s
{
    float angle_min;
    float angle_max;
    float speed;
    sfVector2f gravity;
    sfUint8 alpha;
    sfClock *clock;
    sfCircleShape *circle_shape;
};

struct particle_rain_s
{
    sfVector2f pos;
    sfVector2f vel;
    sfColor color;
    size_t radius;
    sfVector2f size;
    bool living;
};

struct particle_environment_rain_s
{
    float angle_min;
    float angle_max;
    float speed;
    sfVector2f gravity;
    sfUint8 alpha;
    sfClock *clock;
    sfRectangleShape *rectangle_shape;
};
void init_particle_environment(particle_environment_t *particle_environment, \
const sfVector2f angle, const sfVector2f gravity, const sfUint8 alpha);
void init_particule(const particle_environment_t *particle_environment, \
particle_t *particule, const sfVector2f pos);
void display_particle(sfRenderWindow *window, const particle_t *particule, \
sfCircleShape *circle_shape);
void update_particle(const particle_environment_t *particle_environment, \
particle_t *particule);
void add_particle(const particle_environment_t *particle_environment, \
particle_t *particule, const size_t particle_num, const sfVector2f pos);
void add_particle_rain(const particle_environment_rain_t *particle_environmen\
t, particle_rain_t *particule, const size_t particle_num, const sfVector2f pos);
void update_particle_rain(const particle_environment_rain_t *particle_environ\
ment, particle_rain_t *particule);
void display_particle_rain(sfRenderWindow *window, const particle_rain_t *part\
icule, sfRectangleShape *rectangle_shape);
void init_particule_rain(const particle_environment_rain_t *particle_environm\
ent, particle_rain_t *particule, const sfVector2f pos);
void init_particle_environment_rain(particle_environment_rain_t *particle_envi\
ronment, const sfVector2f angle, const sfVector2f gravity, const sfUint8 alpha);

#endif
