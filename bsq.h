#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define MIN(v1, v2) ((v1) <= (v2) ? (v1) : (v2))
#define MIN3(v1, v2, v3) MIN(MIN(v1, v2), v3)

struct map_s {
    char *fc;
    char *data;
    size_t lines;
    size_t line_size;
};
typedef struct map_s bsq_map;

struct square_s {
    char *location;
    size_t size;
};
typedef struct square_s bsq_square;

int parse_file(const char *file_path, bsq_map *map);