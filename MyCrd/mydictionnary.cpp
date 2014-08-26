//
//  mydictionnary.cpp
//  MyCrd
//
//  Created by mataejoon on 8/26/14.
//  Copyright (c) 2014 experiences. All rights reserved.
//

#include "mydictionnary.h"

MyDictionary::MyDictionary()
{
    _real_obj = new FakeDict;
}

bool    MyDictionary::has_key(const char *const key)
{
//    map<int,Bar>::iterator it = m.find('2');

    if (_real_obj->find(key) != _real_obj->end())
        return true;
    else
        return false;
}

bool    MyDictionary::add_value_for_key(const char * const value, const char * const key)
{
    bool    is_update = false;

    _real_obj->insert(FakePair(key, value));

    return is_update;
}