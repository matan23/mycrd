//
//  mydictionnary.cpp
//  MyCrd
//
//  Created by mataejoon on 8/26/14.
//  Copyright (c) 2014 experiences. All rights reserved.
//

#include <string.h>
#include <assert.h>
#include <exception>
#include <stdexcept>
#include "mydictionnary.h"

MyDictionary::MyDictionary()
{
    this->_hashtab = (t_list **)malloc(sizeof(*_hashtab) * HASHSIZE);
    if (!this->_hashtab)
        throw 2323;
}

MyDictionary::~MyDictionary()
{
    t_list      *old;

    while (_head)
    {
        old = _head;
        free(_head->key);
        free(_head->value);
        _head = _head->next;
        free(old);
    }
}


bool    MyDictionary::add_value_for_key(const char * const value, const char * const key)
{
    return this->upsert(key, value);
}

bool                MyDictionary::delete_key(const char * const key, char **value)
{
    t_list          *node;
    unsigned int    hashval;

    if (!(node = find_node_by_key(key)))
        return false;

    hashval = hash(key);
    assert(_hashtab[hashval]);
    *value = _hashtab[hashval]->value;
    _hashtab[hashval] = NULL;
    return true;
}

bool        MyDictionary::value_for_key(const char * const key, char ** const value)
{
    t_list  *node;

    if ((node = find_node_by_key(key)) == NULL)
        return false;
    *value = node->value;
    return true;
}


//private API

unsigned int    MyDictionary::hash(const char *s)
{
    unsigned hashval;

    for (hashval = 0; *s; ++s)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

t_list          *MyDictionary::find_node_by_key(const char *key)
{
    t_list *node;

    assert(this->_hashtab);
    assert(key);
    for (node = this->_hashtab[hash(key)]; node; node = node->next)
        if (!strcmp(key, node->key))
            return node;
    return NULL;
}

bool            MyDictionary::upsert(const char *key, const char *value)
{
    t_list      *node;
    bool        action_is_insert;

    assert(key);
    assert(value);
    action_is_insert = false;
    if (!(node = update_node_with_key_for_value(key, value)))
    {
        node = this->create_new_node_with_key_and_value(key, value);
        if (node)
        {
            this->install_new_node_in_hashtab(node, this->_hashtab);
            action_is_insert = true;
        }
    }
    return action_is_insert;
}

t_list          *MyDictionary::create_new_node_with_key_and_value(const char *key, const char *value)
{
    t_list      *new_node;
    static int  i;

    if ((new_node = (t_list *)malloc(sizeof(*new_node))))
    {
        if (i++ == 0)
            _head = new_node;
        new_node->key = strdup(key);
        new_node->value = strdup(value);
        if (!new_node->key || !new_node->value)
            return NULL;
        return new_node;
    }
    return NULL;
}

t_list              *MyDictionary::install_new_node_in_hashtab(t_list *node, t_list **hashtab)
{
    unsigned int    hashval;

    assert(hashtab);
    hashval = hash(node->key);
    node->next = hashtab[hashval];
    hashtab[hashval] = node;
    return node;
}

t_list          *MyDictionary::update_node_with_key_for_value(const char *key,const char *value)
{
    t_list      *node;

    if (!(node = find_node_by_key(key)))
        return NULL;
    assert(key);
    free(node->value);
    if (!(node->value = strdup(value)))
        return NULL;
    return node;
}