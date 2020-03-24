/*
** EPITECH PROJECT, 2019
** CPE_getnextline_2019
** File description:
** next_line.c
*/

#include "get_next_line.h"

char *my_strcat(char *str, char const *source)
{
    int length = 0;
    int size = 0;
    int j = 0;
    char *one;

    for (;str[length]; length += 1);
    for (;source[size]; size += 1);
    one = malloc(sizeof(char) * (length + size + 1));
    for (int i = 0; str[i] != '\0'; i += 1)
        one[j++] = str[i];
    for (int i = 0; source[i] != '\0'; i += 1)
        one[j++] = source[i];
    one[j] = '\0';
    return (one);
}

int initialize(get_next_t *line)
{
    line->str = malloc(sizeof(char) * READ_SIZE + 1);
    line->index = 0;
    line->i = 0;
    line->rd = READ_SIZE;
    line->tmp = malloc(sizeof(char) * (READ_SIZE + 1));
    line->result = malloc(sizeof(char));

    if (!line->result)
        return (1);
    else
        return (0);
}

static void zebi(get_next_t *line)
{
    if (line->str[line->index] == '\0') {
        line->result = my_strcat(line->result, line->tmp);
        free(line->tmp);
        line->tmp = malloc(sizeof(char) * (READ_SIZE + 1));
        line->i = 0;
        line->index = -1;
    }
}

static void zebi2(get_next_t *line)
{
    line->tmp[line->i] = '\0';
    line->result = my_strcat(line->result, line->tmp);
    line->index += 1;
}

char *get_next_line(int fd)
{
    get_next_t *line = malloc(sizeof(get_next_t));
    if (initialize(line))
        return NULL;
    line->result[0] = '\0';
    for (; line->rd == READ_SIZE; zebi(line), line->index += 1) {
        if (line->index == 0) {
            line->rd = read(fd, line->str, READ_SIZE);
            line->str[READ_SIZE] = '\0';
            if (line->rd <= 0)
                return (NULL);
        }
        if (line->str[line->index] != '\n' && line->str[line->index] != '\0') {
            line->tmp[line->i] = line->str[line->index];
            line->i += 1;
        } else if (line->str[line->index] == '\n') {
            zebi2(line);
            break;
        }
    }
    return (line->result);
}