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

void fs_print_first_line(char const *filepath)
{
    struct stat buf;
    int i = 0;
    int j = 0;
    int file = open(filepath, O_RDONLY);
    char *buffer = (char *)malloc(sizeof(char) * 256);
    size_t bytes = read(file, buffer, 500);

    my_putstr("\n");
    while (buffer[i] != '\n') {
        my_putchar(buffer[i]);
        i++;
    }
    my_putstr("\n");
    bytes = read(file, buffer, i);
    buffer[bytes] = '\0';
    close(file);
}

void array_1d_print_chars(char const *arr)
{
    int i = 0;

    while (arr[i] != '\0') {
        my_putchar(arr[i]);
        if (arr[i+1] != '\0')
            my_putstr("\n");
        i++;
    }
}
