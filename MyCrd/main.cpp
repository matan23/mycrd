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

MyDictionary *mydict;

void add_cmd(const char * const key, const char * const value)
{
    if (mydict->add_value_for_key(value, key))
    {
        puts("\t its an insert");
    }
    else
    {
        puts("\t its an update");
    }
    puts(key);
}

void delete_cmd(const char * const key)
{
    char *value;
    
    puts("\tdeletion");
    if (mydict->delete_key(key, &value))
        puts(value);
    else
        puts("-1");
}

void parser(char **cmd_val, int nb_words)
{
    char *key;
    char *value;
    
    key = cmd_val[0];
    value = cmd_val[1];
    if (nb_words == 1)
    {
        puts("\trecherche..");
        if (mydict->value_for_key(key, &value))
            puts(value);
        else
            puts("-1");
    }
    else
    {
        if (!strcmp(cmd_val[1], "D"))
        {
            delete_cmd(key);
        }
        else
        {
            add_cmd(key, value);
        }
    }
}

int main(int argc, const char * argv[])
{
//    singleton
    mydict = new MyDictionary();
    
    char *str;
    char **cmd_val;
    int nb_words;
    // insert code here...
    puts("LETSGO");
    while ((str = get_next_line(0)))
   {
       if (*str)
       {
           cmd_val = str_to_wtb(str, &nb_words);
           parser(cmd_val, nb_words);
       }
       free(str);
       str = NULL;
   }
    return 0;
}

