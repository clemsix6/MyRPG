/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** load_map.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

char *read_file(const char *filepath)
{
    struct stat file;
    stat(filepath, &file);
    char *buffer = malloc(sizeof(char) * file.st_size + 1);
    int fd = STDOUT_FILENO;

    fd = open(filepath, O_RDONLY);
    ssize_t n = read(fd, buffer, file.st_size);
    buffer[n] = '\0';
    close(fd);
    return buffer;
}
