/*
** EPITECH PROJECT, 2023
** Memory Workshop
** File description:
** memory
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int my_malloc(int nb)
{
    if (sbrk(nb) == -1)
        return -1;
    return 0;
}

int main(int argc, char *argv[])
{
    my_malloc(5);
    return 0;
}
