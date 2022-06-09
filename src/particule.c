/*
** EPITECH PROJECT, 2022
** graphique
** File description:
** particule.c
*/

#include "particle.h"
#include "my_rpg.h"

void init_particle_environment(particle_environment_t *particle_environment, \
const sfVector2f angle, const sfVector2f gravity, const sfUint8 alpha)
{
    particle_environment->angle_max = angle.x;
    particle_environment->angle_min = angle.y;
    particle_environment->gravity = gravity;
    particle_environment->alpha = alpha;
    particle_environment->speed = SPEED;
    particle_environment->circle_shape = sfCircleShape_create();
    particle_environment->clock = sfClock_create();
}

void init_particule(const particle_environment_t *particle_environment, \
particle_t *particule, const sfVector2f pos)
{
    particule->pos = pos;
    particule->color = sfRed;
    float angle = ((float)rand()/(float)(RAND_MAX)) * \
    (particle_environment->angle_max - particle_environment->angle_min) \
    + particle_environment->angle_min;
    particule->vel.x = cos(angle);
    particule->vel.y = sin(angle);
    particule->living = true;
    particule->radius = 2;
}

void display_particle(sfRenderWindow *window, const particle_t *particule, \
sfCircleShape *circle_shape)
{
    if (particule->living == true) {
        sfCircleShape_setRadius(circle_shape, (float)particule->radius);
        sfCircleShape_setPosition(circle_shape,  particule->pos);
        sfCircleShape_setFillColor(circle_shape, particule->color);
        sfRenderWindow_drawCircleShape(window, circle_shape, NULL);
    }
}

void update_particle(const particle_environment_t *particle_environment, \
particle_t *particule)
{
    if (particule->living == true) {
        particule->color.a -= 1;
        particule->vel.x += particle_environment->gravity.x;
        particule->vel.y += particle_environment->gravity.y;
        particule->pos.x += particule->vel.x * particle_environment->speed;
        particule->pos.y += particule->vel.y * particle_environment->speed;
        if (particule->color.a <= 0) {
            particule->living = false;
        }
        if (particule->pos.x < 0 || particule->pos.x > 1920 ||
            particule->pos.y < 0 || particule->pos.y > 1080) {
            particule->living = false;
        }
    }
}

void add_particle(const particle_environment_t *particle_environment, \
particle_t *particule, const size_t particle_num, const sfVector2f pos)
{
    size_t index = 0;
    for (size_t i = 0; index < particle_num; i++) {
        if (particule[i].living == false) {
            init_particule(particle_environment, &particule[i], pos);
            index++;
        }
    }
}
