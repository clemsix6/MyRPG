/*
** EPITECH PROJECT, 2022
** graphique
** File description:
** particle_rain.c
*/

#include "particle.h"

void init_particle_environment_rain(particle_environment_rain_t *particle_environment, \
const sfVector2f angle, const sfVector2f gravity, const sfUint8 alpha)
{
    particle_environment->angle_max = angle.x;
    particle_environment->angle_min = angle.y;
    particle_environment->gravity = gravity;
    particle_environment->alpha = alpha;
    particle_environment->speed = SPEED;
    particle_environment->rectangle_shape = sfRectangleShape_create();
    particle_environment->clock = sfClock_create();
}

void init_particule_rain(const particle_environment_rain_t *particle_environment, \
particle_rain_t *particule, const sfVector2f pos)
{
    particule->pos = pos;
    particule->color = sfColor_fromRGBA(0, 150, 255, 50);
    float angle = ((float)rand()/(float)(RAND_MAX)) * \
    (particle_environment->angle_max - particle_environment->angle_min) \
    + particle_environment->angle_min;
    particule->vel.x = cos(angle);
    particule->vel.y = sin(angle);
    particule->living = true;
    particule->size.x = 2;
    particule->size.y = 12;
}

void display_particle_rain(sfRenderWindow *window, const particle_rain_t *particule, \
sfRectangleShape *rectangle_shape)
{
    if (particule->living == true) {
        sfRectangleShape_setSize(rectangle_shape, particule->size);
        sfRectangleShape_setPosition(rectangle_shape,  particule->pos);
        sfRectangleShape_setFillColor(rectangle_shape, particule->color);
        sfRenderWindow_drawRectangleShape(window, rectangle_shape, NULL);
    }
}

void update_particle_rain(const particle_environment_rain_t *particle_environment, \
particle_rain_t *particule)
{
    if (particule->living == true) {
        particule->color.a -= 1;
        particule->vel.x += particle_environment->gravity.x;
        particule->vel.y += particle_environment->gravity.y;
        particule->pos.x += particule->vel.x * particle_environment->speed * 10;
        particule->pos.y += 14 * particle_environment->speed;
        if (particule->color.a <= 0) {
            particule->living = false;
        }
        if (particule->pos.x < 0 || particule->pos.x > 1920 ||
            particule->pos.y > 1080) {
            particule->living = false;
        }
    }
}

void add_particle_rain(const particle_environment_rain_t *particle_environment, \
particle_rain_t *particule, const size_t particle_num, const sfVector2f pos)
{
    size_t index = 0;
    for (size_t i = 0; index < particle_num; i++) {
        if (particule[i].living == false) {
            init_particule_rain(particle_environment, &particule[i], pos);
            index++;
        }
    }
}
