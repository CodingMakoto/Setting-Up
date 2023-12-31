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

void fs_cat_500_bytes(char const *filepath)
{
    int file = open(filepath, O_RDONLY);
    char buffer[501];
    size_t bytes = read(file, buffer, 500);

    buffer[bytes] = '\0';
    my_putstr(buffer);
    close(file);
}

void fs_cat_x_bytes(char const *filepath, int x)
{
    int file = open(filepath, O_RDONLY);
    size_t bytes;
    char buffer[x + 1];

    if (!(x))
        fs_cat_500_bytes(filepath);
    else {
        bytes = read(file, buffer, x);
        buffer[bytes] = '\0';
        my_putstr(buffer);
        close(file);
    }
}

void fs_understand_return_of_read(int fd, char *buffer, int size)
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
    close(file);
}

int fs_open_file(char const *filepath)
{
    struct stat buf;
    int file = 0;
    char *buffer = NULL;
    int size = 0;

    file = open(filepath, O_RDONLY);
    size = stat(filepath, &buf);
    buffer = malloc(buf.st_size * sizeof(char) + 1);
    if (file == -1)
        my_putstr("FAILURE");
    else
        my_putstr("SUCCESS");
    fs_understand_return_of_read(file, buffer, size);
    close(file);
    return 0;
}

int main(int argc, char **argv)
{
    if (argv[1] == NULL || open(argv[1], O_RDONLY) == -1)
        my_putstr("No such file or directory");
    else {
        check_file(argv[1]);
        return 0;
    }
}
