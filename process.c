/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** process
*/

#include "includes/bsq.h"

void swap_buffer(size_t **buffer1, size_t **buffer2)
{
    size_t *temp = *buffer1;

    *buffer1 = *buffer2;
    *buffer2 = temp;
}

void print_map(bsq_map *map, bsq_square *square)
{
    char *current;

    if (!map || !square)
        return;
    current = square->location;
    for (size_t l = 0; l < square->size; l++) {
        for (size_t i = 0; i < square->size; i++)
            *(current--) = 'x';
        current -= (map->line_size + 1) - square->size;
    }
    write(1, map->data, map->lines * (map->line_size + 1));
}

void solve_fill_buffer(bsq_map *map, bsq_square *square, size_t line,
size_t *buffer[2])
{
    int index = line * (map->line_size + 1);

    for (size_t i = 0; i < map->line_size; ++i, ++index) {
        if (map->data[index] == 'o')
            buffer[0][i] = 0;
        else
            buffer[0][i] = (line == 0 || i == 0) ? 1
            : MIN3(buffer[1][i], buffer[1][i - 1], buffer[0][i - 1]) + 1;
        if (buffer[0][i] > square->size) {
            square->size = buffer[0][i];
            square->location = map->data + index;
        }
    }
}

void solve(bsq_map *map, bsq_square *square)
{
    size_t *alloc;
    size_t *buffer[2];

    if (!map || !square)
        return;
    alloc = malloc(map->line_size * 2 * sizeof(size_t));
    buffer[0] = alloc;
    buffer[1] = alloc + map->line_size;
    for (size_t l = 0; l < map->lines; l++) {
        solve_fill_buffer(map, square, l, buffer);
        swap_buffer(&buffer[0], &buffer[1]);
    }
    free(alloc);
}
