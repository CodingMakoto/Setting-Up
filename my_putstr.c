/*
** EPITECH PROJECT, 2023
** My Putstr
** File description:
** Display char one by one in a string
*/

#include "putchar.h"
#include <stdio.h>
#include <unistd.h>

int my_putstr(char const *str)
{
    int ch = 0;

    while (str[ch] != '\0') {
        my_putchar(str[ch]);
        ch = ch + 1;
    }
    return 0;
}
