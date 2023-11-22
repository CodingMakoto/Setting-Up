/*
** EPITECH PROJECT, 2023
** Main
** File description:
** Main of Setting Up
*/

#include "my.h"
#include "bootstrap.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void print_file(char *buffer)
{
    int i = 0;

    while (buffer[i] != '\n') {
        my_putchar(buffer[i]);
        i++;
    }
}

void check_numbers(char *buffer, int i)
{
    int warning = 0;

    i += 1;
    while (buffer[i] == '\0') {
        if (buffer[i] != '.' && buffer[i] != 'o')
            warning++;
        i++;
    }
    if (warning > 0)
        my_putstr("The file contains other characters\n");
    else if (!(buffer[0]))
        my_putstr("The file is empty\n");
    else {
        print_file(buffer);
    }
}

void check_file(char const *filepath)
{
    struct stat buf;
    int i = 0;
    int warning = 0;
    int file = open(filepath, O_RDONLY);
    char *buffer = (char *)malloc(sizeof(char) * 256);
    size_t bytes = read(file, buffer, 500);

    my_putstr("\n");
    while (buffer[i] != '\n') {
        if (buffer[i] == '.' || buffer[i] == 'o')
            warning++;
        i++;
    }
    if (warning > 0)
        my_putstr("The file does not contains the numbers of lines");
    else {
        check_numbers(buffer, i);
    }
}
