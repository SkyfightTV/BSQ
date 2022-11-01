/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** read
*/

#ifndef READ_H_
    #define READ_H_
    #include "bsq.h"
char *get_number(char * const str, size_t *number);
char *read_file_content(const char *file_path);
size_t get_line_size(char const *data);
int parse_file(const char *file_path, bsq_map *map);
#endif /* !READ_H_ */
