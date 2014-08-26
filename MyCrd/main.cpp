//
//  main.cpp
//  MyCrd
//
//  Created by mataejoon on 8/26/14.
//  Copyright (c) 2014 experiences. All rights reserved.
//

#include <iostream>
#include <string>
#include "get_next_line.h"
#include "str_to_wtb.h"
#include "mydictionnary.h"

void parser(char **cmd_val, int nb_words)
{
    MyDictionary *mydict;

    mydict = new MyDictionary();

    if (nb_words == 1)
    {
        puts("recherche..");
        if (mydict->has_key(cmd_val[1]))
            puts("trouve!");
        else
            puts("non trouve");
    }
    else
    {
        if (!strcmp(cmd_val[1], "D"))
            puts("deletion");
        else
        {
            if (mydict->has_key(cmd_val[1]))
                puts("update");
            else
            {
                puts("add");
                mydict->add_value_for_key(cmd_val[1], cmd_val[0]);
            }
        }
    }
}

int main(int argc, const char * argv[])
{
    char *str;
    char **cmd_val;
    int nb_words;
    // insert code here...
    puts("LETSGO");
    while ((str = get_next_line(0)))
   {
       cmd_val = str_to_wtb(str, &nb_words);
       free(str);
       parser(cmd_val, nb_words);
//       printf("%s:%s\n", cmd_val[0], cmd_val[1]);
   }
    return 0;
}

