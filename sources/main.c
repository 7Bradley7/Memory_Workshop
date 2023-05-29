/*
** EPITECH PROJECT, 2023
** Memory Workshop
** File description:
** memory
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *str = malloc(sizeof(char) * 13);
    strcpy(str, "Hello World!");
    return 0;
}
