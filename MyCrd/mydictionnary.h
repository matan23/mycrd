//
//  mydictionnary.h
//  MyCrd
//
//  Created by mataejoon on 8/26/14.
//  Copyright (c) 2014 experiences. All rights reserved.
//

#ifndef __MyCrd__mydictionnary__
#define __MyCrd__mydictionnary__

#include <iostream>


#define HASHSIZE 50000

typedef struct      s_list
{
    char            *key;
    char            *value;
    struct s_list   *next;
    struct s_list   *prev;
}                   t_list;


class MyDictionary
{
private:
    t_list     **_hashtab;
    t_list      *_head;

public:
    MyDictionary();
    ~MyDictionary();

//    bool    has_key(const char * const key);
    bool    add_value_for_key(const char * const value, const char * const key);
    bool    delete_key(const char * const key, char **value);
    
    bool    value_for_key(const char * const key, char ** const value);
private:
//    bool    extract_value_for_key(char **value, const char * const key);
//    bool            get_key(const char * const key, FakeDict::iterator *it);
    unsigned int    hash(const char *s);
    t_list          *find_node_by_key(const char *s);
    bool            upsert(const char *key, const char *value);
    t_list          *create_new_node_with_key_and_value(const char *key, const char *value);
    t_list          *update_node_with_key_for_value(const char *key,const char *value);
    t_list          *install_new_node_in_hashtab(t_list *node, t_list *hashtab[HASHSIZE]);
};

#endif /* defined(__MyCrd__mydictionnary__) */
