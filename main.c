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

void fs_understand_return_of_read(int fd, char * buffer, int size)
{
    int file;

    file = read(fd, buffer, size);
    my_putstr("\n");
    if (file == -1)
        my_putstr("read failed\n");
    if (file == 0)
        my_putstr("read has nothing more to read\n");
    if (file < size)
        my_putstr("read didn’t complete the entire buffer\n");
    if (file == size)
        my_putstr("read completed the entire buffer\n");
}

int fs_open_file(char const * filepath)
{
    struct stat buf;
    int file = 0;
    char ch;
    char * buffer = malloc(sizeof(filepath));
    int size = 0;

    file = open(filepath, O_RDONLY);
    size = fstat(file, &buf);
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
