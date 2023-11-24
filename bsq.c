/*
** EPITECH PROJECT, 2023
** Main
** File description:
** Main of Setting Up
*/

#include "my.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int file_size(char const *filepath)
{
    struct stat buf;
    off_t size;

    int file = open(filepath, O_RDONLY);
    if (stat(filepath, &buf) == -1)
        return -84;
    return buf.st_size;
}

int load(char const *filepath)
{
    off_t size;
    char *loaded;

    int file = open(filepath, O_RDONLY);
    size = file_size(filepath);
    loaded = malloc(sizeof(char) * (size + 1));
    if (!loaded || read(file, loaded, size) == -1)
        return 0;
    loaded[size] = '\0';
    my_putstr(loaded);
}
