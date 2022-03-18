#include "bsq.h"

static void swap_buffer(size_t **buffer1, size_t **buffer2)
{
    size_t *temp = *buffer1;

    *buffer1 = *buffer2;
    *buffer2 = temp;
}

void solve_fill_buffer(bsq_map *map, bsq_square *square, size_t line, size_t *buffer[2])
{
    for (size_t i = 0; i < map->line_size; i++) {
        if (map->data[line * (map->line_size + 1) + i] == 'o')
            buffer[0][i] = 0;
        else {
            buffer[0][i] = (line == 0 || i == 0) ? 0
            : MIN3(buffer[1][i], buffer[1][i - 1], buffer[0][i - 1]) + 1;
        }
        if (buffer[0][i] > square->size) {
            square->size = buffer[0][i];
            square->location = map->data + (line * (map->line_size + 1) + i);
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
    if (!alloc)
        return;
    buffer[0] = alloc;
    buffer[1] = alloc + map->line_size;
    for (size_t l = 0; l < map->lines; l++) {
        solve_fill_buffer(map, square, l, buffer);
        swap_buffer(&buffer[0], &buffer[1]);
    }
    free(alloc);
}

static void write_square(bsq_map *map, bsq_square *square)
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
}

int main(int argc, char **argv)
{
    bsq_map map = {0};
    bsq_square square = {0};

    if (parse_file(argv[1], &map) == -1)
        return 84;
    solve(&map, &square);
    write_square(&map, &square);
    printf("%s\n", map.data);
    free(map.fc);
    return 0;
}