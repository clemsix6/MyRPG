/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-mydefender-clement.dreiski
** File description:
** init_button
*/

#include "my_rpg.h"

void ibtt_menu(menu_t *menu)
{
    menu->vector_options.x = 1200;
    menu->vector_options.y = 900;
    menu->rect_options.width = 270;
    menu->rect_options.height = 113;
    menu->vector_howtplay.x = 770;
    menu->vector_howtplay.y = 910;
    menu->rect_howtplay.width = 375;
    menu->rect_howtplay.height = 105;
    menu->vector_quit.x = 1640;
    menu->vector_quit.y = 900;
    menu->rect_quit.width = 165;
    menu->rect_quit.height = 113;
    menu->vector_howtoplay_quit.x = 160;
    menu->vector_howtoplay_quit.y = 930;
    menu->rect_howtoplay_quit.height = 157;
    menu->rect_howtoplay_quit.width = 117;
}

void ibtt_pause(pause_t *pause)
{
    pause->vector_resume.x = 100;
    pause->vector_resume.y = 90;
    pause->rect_resume.width = 320;
    pause->rect_resume.height = 105;
    pause->http_vector.x = 1120;
    pause->http_vector.y = 90;
    pause->http_rect.width = 420;
    pause->http_rect.height = 105;
    pause->vector_quit.x = 150;
    pause->vector_quit.y = 920;
    pause->rect_quit.width = 168;
    pause->rect_quit.height = 122;
}
