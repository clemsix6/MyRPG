/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** menu
*/

#ifndef MENU_H_
    #define MENU_H_
    #include "my_rpg.h"

typedef struct menu {
    sfTexture* menu_texture;
    sfSprite* menu_sprite;
    sfTexture* menu_texture2;
    sfSprite* menu_sprite2;
    sfIntRect rect_options;
    sfVector2f vector_options;
    sfIntRect rect_quit;
    sfVector2f vector_quit;
    sfIntRect rect_howtplay;
    sfVector2f vector_howtplay;
    sfIntRect rect_howtoplay_quit;
    sfVector2f vector_howtoplay_quit;
} menu_t;

typedef struct settings_s {
    sfSprite* settings_sprite;
    sfTexture* settings_texture;
}settings_t;

void ibtt_menu(menu_t *menu);

#endif /* !MENU_H_ */
