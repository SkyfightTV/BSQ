/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** bsq
*/

#include "includes/bsq.h"
#include "includes/read.h"

int main(int ac, char **av)
{
    bsq_map map = {0};
    bsq_square square = {0};

    if (ac != 2 || parse_file(av[1], &map))
        return 84;
    solve(&map, &square);
    print_map(&map, &square);
    free(map.fc);
    return 0;
}
