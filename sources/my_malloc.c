/*
** EPITECH PROJECT, 2023
** Memory_Workshop
** File description:
** my_malloc
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define BLOCK_SIZE sizeof(struct Block)

struct Block {
    size_t size;
    struct Block *next;
    int is_free;
};

struct Block *heap = NULL;

void *my_malloc(size_t size)
{
    if (size <= 0)
        return NULL;
    if (heap == NULL) {
        struct Block* new_block = sbrk(BLOCK_SIZE + size);
        if (new_block == (void*)-1)
            return NULL;
        new_block->size = size;
        new_block->next = NULL;
        new_block->is_free = 0;
        heap = new_block;
        return (void*)(new_block + 1);
    } else {
        struct Block* current = heap;
        while (current != NULL) {
            if (current->is_free && current->size >= size) {
                current->is_free = 0;
                return (void*)(current + 1);
            }
            current = current->next;
        }
        struct Block* new_block = sbrk(BLOCK_SIZE + size);
        if (new_block == (void*)-1)
            return NULL;
        new_block->size = size;
        new_block->next = NULL;
        new_block->is_free = 0;
        current = heap;
        while (current->next != NULL)
            current = current->next;
        current->next = new_block;
        return (void*)(new_block + 1);
    }
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 84;
    char *str = (char*)my_malloc(10 * sizeof(char));
    if (str != NULL) {
        strcpy(str, av[1]);
        printf("%s\n", str);
    }
    return 0;
}