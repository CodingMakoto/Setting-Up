/*
** EPITECH PROJECT, 2023
** Main
** File description:
** Main of Setting Up
*/

#include "my.h"
#include "bsq.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct compare
{
    int new_length;
} Compare_t;

void check_lines_second(char *buffer, struct compare *value, int i, int length)
{
    if (buffer[i] != '\n' && buffer[i] != '\0')
        value->new_length++;
    else {
        if (value->new_length != length && buffer[i] != '\0')
            my_putstr("File lines doesn't have the same size\n");
        value->new_length = 0;
    }
}

void check_lines(char const *filepath, char *buffer)
{
    int i = 0;
    int length = 0;
    Compare_t value = {0};
    int j = 0;

    while (buffer[i] != '\n') {
        i++;
    }
    i++;
    j = i;
    if (!(buffer[i]))
        my_putstr("The file need to contains at least one line");
    else {
        while (buffer[i] != '\n') {
            length++;
            i++;
        }
        i = j;
        while (buffer[i] != '\0') {
            check_lines_second(buffer, &value, i, length);
            i++;
        }
        load(filepath);
    }
}

void check_numbers(char const *filepath, char *buffer, int i)
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
        check_lines(filepath, buffer);
    }
}

void check_file(char const *filepath)
{
    struct stat buf;
    int i = 0;
    int warning = 0;
    int file = open(filepath, O_RDONLY);
    char *buffer = (char *)malloc(sizeof(char) * 500);
    size_t bytes = read(file, buffer, 500);

    while (buffer[i] != '\n') {
        if (buffer[i] == '.' || buffer[i] == 'o')
            warning++;
        i++;
    }
    if (warning > 0)
        my_putstr("The file does not contains the numbers of lines");
    else {
        if (buffer[i+1])
            check_numbers(filepath, buffer, i);
        else
            my_putstr("The file need to contains one line at least");
    }
}
