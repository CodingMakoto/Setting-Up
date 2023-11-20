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

void fs_understand_return_of_read(int fd, char * buffer, int size)
{
    if (fd == -1)
        my_putstr("read failed\n");
    if (fd == 0)
        my_putstr("read has nothing more to read\n");
    if (fd < size)
        my_putstr("read didn’t complete the entire buffer\n");
    if (fd == size)
        my_putstr("read completed the entire buffer\n");
}

int fs_open_file(char const * filepath)
{
    int file = 0;
    char ch;
    char * buffer;
    int size = sizeof(buffer);

    file = open(filepath, O_RDONLY);
    if (file == -1)
        my_putstr("FAILURE");
    else
        my_putstr("SUCCESS");
    fs_understand_return_of_read(file, buffer, size);
    return 0;
}

int main(int argc, char **argv)
{
    fs_open_file(argv[1]);
    return 0;
}
