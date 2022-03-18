#include "bsq.h"

static char *get_number(char * const str, size_t *number)
{
    char *current;

    if (!str || !number)
        return -1;
    current = str;
    *number = 0;
    for (; *current && *current != '\n' && *current >= '0' && *current <= '9'; current++)
        *number = (*number * 10) + *current - '0';
    return current;
}

static char *read_file_content(const char *file_path)
{
    struct stat f_stats = {0};
    int fd;
    char *result;
    ssize_t read_size;

    if (!file_path || stat(file_path, &f_stats) == -1)
        return 0;
    fd = open(file_path, O_RDONLY);
    if (fd == -1)
        return 0;
    if (!(result = malloc((f_stats.st_size + 1) * sizeof(char))))
        return 0;
    result[f_stats.st_size] = 0;
    read_size = read(fd, result, f_stats.st_size);
    close(fd);
    if (read_size != f_stats.st_size) {
        free(result);
        return 0;
    }
    return result;
}

ssize_t get_line_size(char const *data)
{
    ssize_t result;

    if (!data)
        return -1;
    for (result = 0; *data && *data != '\n'; data++, result++);
    if (!*data)
        return -1;
    return result;
}

int parse_file(const char *file_path, bsq_map *map)
{
    ssize_t line_size;

    if (!file_path || !map)
        return -1;
    map->fc = read_file_content(file_path);
    map->data = get_number(map->fc, &map->lines);
    if (!map->data || map->data == map->fc) {
        free(map->fc);
        return -1;
    }
    map->data++;
    line_size = get_line_size(map->data);
    if (line_size == -1) {
        free(map->fc);
        return -1;
    }
    map->line_size = line_size;
    return 0;
}