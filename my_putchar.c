/*
** EPITECH PROJECT, 2023
** My Putchar
** File description:
** Print a character
*/

#include <stdio.h>
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
