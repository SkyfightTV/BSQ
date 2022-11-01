/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** bsq
*/

#ifndef _BSQ_H_
    #define _BSQ_H_
    #include <sys/stat.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <stdio.h>

    #define MIN(v1, v2) ((v1) <= (v2) ? (v1) : (v2))
    #define MIN3(v1, v2, v3) MIN(MIN(v1, v2), v3)

typedef struct map_s {
    char *fc;
    char *data;
    size_t lines;
    size_t line_size;
} bsq_map;

typedef struct square_s {
    char *location;
    size_t size;
} bsq_square;

void swap_buffer(size_t **buffer1, size_t **buffer2);
void print_map(bsq_map *map, bsq_square *square);
void solve_fill_buffer(bsq_map *map, bsq_square *square, size_t line,
size_t *buffer[2]);
void solve(bsq_map *map, bsq_square *square);
#endif
