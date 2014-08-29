//
//  get_next_line.c
//  MyCrd
//
//  Created by mataejoon on 8/26/14.
//  Copyright (c) 2014 experiences. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

#include "get_next_line.h"

static int	xread(int fd, char *buffer, size_t const size)
{
    int		ret;

    if ((ret = (int)read(fd, buffer, size)) == -1)
        exit(EXIT_FAILURE);
    return (ret);
}

void            resize(char *str, int i, int *index)
{
    int           ind;

    ind = -1;
    while (++ind < (*index - i))
        str[ind] = str[i + ind];
    *index -= i;
}

char        *_strndup(char const *src, unsigned int i)
{
    char    *dest;

    dest = (char *)malloc(sizeof(*src) * (i + 1));
    strncpy(dest, src, i);
    return dest;
}

char            *getnl(char *str, int *index, const int fd)
{
    int           i;
    char          *ret;
    int           f;

    i = -1;
    f = 0;
    ret = 0;
    while (++i < *index)
        if (!str[i] || CHAR_IS_NEWLINE(*(str + i)))
        {
            ret = (char *)malloc((i + 1) * sizeof(*ret) + 1);
            ret = strncpy(ret, str, i);
            ret[i + 1] = '\0';
            resize(str, i + 1, index);
            return (ret);
        }
    if (i == *index && i != 0)
    {
        ret = _strndup(str, i);
        resize(str, i, index);
        ret = strcat(ret, gnl(fd, index, str));
        return (ret);
    }
    return (0);
}

char            *gnl(const int fd, int *index, char *buff)
{
    char          *tmp;
    int           offset;

    tmp = getnl(buff, index, fd);
    offset = 1;
    while (tmp == 0 && offset > 0)
    {
        if ((*index) + READ_B > BUFFER)
            offset = xread(fd, buff + (*index), BUFFER - (*index));
        else
            offset = xread(fd, buff + (*index), READ_B);
        if (offset > 0)
            (*index) += offset;
        tmp = getnl(buff, index, fd);
    }
    if (offset == 0 && tmp == 0 && (*index) > 0)
    {
        tmp = _strndup(buff, *index);
        (*index) = 0;
    }
    return (tmp);
}

char            *get_next_line(const int fd)
{
    static int    index = 0;
    static char   buff[BUFFER + 1];
    
    if (fd == -1)
    {
        index = 0;
        buff[0] = 0;
    }
    else
        return (gnl(fd, &index, buff));
    return (0);
}