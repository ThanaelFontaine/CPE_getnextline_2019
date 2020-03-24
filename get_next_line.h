/*
** EPITECH PROJECT, 2019
** GET_NEXT_LINE_2019
** File description:
** bsq.h
*/

#ifndef GET_NEXT_LINE_
#define GET_NEXT_LINE_

#ifndef READ_SIZE
#define READ_SIZE 5
#endif /*READ_SIZE*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdarg.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>

typedef struct get_next_s
{
    int boolle;
    char *str;
    int index;
    int i;
    int rd;
    char *tmp;
    char *result;
}get_next_t;


void documentation(void);

char *my_strcat(char *str, char const *source);
int initialize(get_next_t *line);
char *get_next_line(int fd);

#endif /*GET_NEXT_LINE_*/