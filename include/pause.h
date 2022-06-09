/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** pause
*/

#ifndef PAUSE_H_
    #define PAUSE_H_
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>

typedef struct pause {
    sfTexture* pause_texture;
    sfSprite* pause_sprite;
    sfVector2f pauseback_vector;
    sfIntRect rect_resume;
    sfVector2f vector_resume;
    sfIntRect http_rect;
    sfVector2f http_vector;
    sfIntRect rect_quit;
    sfVector2f vector_quit;
} pause_t;

void ibtt_pause(pause_t *pause);

#endif /* !PAUSE_H_ */
