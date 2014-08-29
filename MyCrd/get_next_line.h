//
//  get_next_line.h
//  MyCrd
//
//  Created by mataejoon on 8/26/14.
//  Copyright (c) 2014 experiences. All rights reserved.
//

#ifndef get_next_line_h
#define get_next_line_h

#  define	BUFF_SIZE	1024
#  define	READ_SIZE	BUFF_SIZE - 1

char    *get_next_line(const int fd);

#define READ_B  512
#define BUFFER  4096

#define CHAR_IS_NEWLINE(c)  c == '\n'

char    *gnl(const int fd, int *index, char *buff);

#endif
