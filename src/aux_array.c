/*
** EPITECH PROJECT, 2025
** minishell2 [WSL: Ubuntu-24.04]
** File description:
** aux_array
*/

#include "../include/my.h"
#include "../include/helper_array.h"

int get_col_len(char *map_one_dim, int start_pos, char sep1, char sep2)
{
    int len = 0;
    int count_m = start_pos;

    while (map_one_dim[count_m] != sep1 &&
        map_one_dim[count_m] != sep2 && map_one_dim[count_m] != '\0') {
        len++;
        count_m++;
    }
    return len;
}

int get_rows(char *map_one_dim, char sep1, char sep2)
{
    int i = 0;
    int rows = 0;

    if (map_one_dim == NULL) {
        return 0;
    }
    while (map_one_dim[i]) {
        if (is_end_of_row(map_one_dim[i], map_one_dim[i + 1], sep1, sep2)) {
            rows++;
        }
        i++;
    }
    return rows;
}

static char infer_sep2(char sep1)
{
    if (sep1 == '\n')
        return ' ';
    if (sep1 == ' ')
        return '\t';
    return ' ';
}

static void copy_row(char *src, char **dest, int row, int *pos)
{
    int col = 0;
    char sep1 = '\n';
    char sep2 = ' ';
    int temp_pos = *pos;

    while (src[temp_pos] != '\0' &&
        !is_separator(src[temp_pos], '\n', ' ') &&
        !is_separator(src[temp_pos], '\t', '\0')) {
        temp_pos++;
    }
    if (src[temp_pos] != '\0') {
        sep1 = src[temp_pos];
        sep2 = infer_sep2(sep1);
    }
    while (!is_end_of_column(src[*pos], sep1, sep2)) {
        dest[row][col] = src[*pos];
        col++;
        (*pos)++;
    }
}

void free_allocated_memory(char **map, int rows)
{
    for (int i = 0; i < rows; i++) {
        free(map[i]);
    }
    free(map);
}

int allocate_row(char **map, int row_idx, int col_len)
{
    map[row_idx] = init_malloc(col_len);
    if (map[row_idx] == NULL) {
        free_allocated_memory(map, row_idx);
        return 0;
    }
    return 1;
}

char **get_array(char *map_one_dim, char sep1, char sep2)
{
    int map_pos = 0;
    int row_idx = 0;
    int total_rows = get_rows(map_one_dim, sep1, sep2);
    int col_len = 0;
    char **map = malloc(sizeof(char *) * (total_rows + 1));

    if (map == NULL)
        return NULL;
    while (row_idx < total_rows) {
        skip_separators(map_one_dim, &map_pos, sep1, sep2);
        col_len = get_col_len(map_one_dim, map_pos, sep1, sep2);
        if (!allocate_row(map, row_idx, col_len))
            return NULL;
        copy_row(map_one_dim, map, row_idx, &map_pos);
        row_idx++;
    }
    map[row_idx] = NULL;
    return map;
}
