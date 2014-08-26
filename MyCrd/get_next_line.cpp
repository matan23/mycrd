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
#include <sys/types.h>

#include "get_next_line.h"

static int	xread(int fd, char *buffer, size_t const size)
{
    int		ret;

    if ((ret = (int)read(fd, buffer, size)) == -1)
        exit(EXIT_FAILURE);
    return (ret);
}

char		*get_next_line(int const fd)
{
    static int	i = BUFF_SIZE;
    static int	current = 1;
    static char	buffer[BUFF_SIZE];
    int		j;
    char		*line;

    line = NULL;
    j = 0;
    if (current && i >= (BUFF_SIZE - 1))
    {
        i = 0;
        current = xread(fd, buffer, READ_SIZE);
        buffer[current] = '\0';
    }
    if (i < BUFF_SIZE && buffer[i])
    {
        line = (char *)malloc(sizeof(*line) * BUFF_SIZE);
        while (buffer[i] != '\n' && buffer[i])
            line[j++] = buffer[i++];
        line[j] = '\0';
        if (buffer[i])
            i++;
    }
    i = BUFF_SIZE;
    return (line);
}
