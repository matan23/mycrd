//
//  mydictionnary.cpp
//  MyCrd
//
//  Created by mataejoon on 8/26/14.
//  Copyright (c) 2014 experiences. All rights reserved.
//

#include <string>
#include "mydictionnary.h"

MyDictionary::MyDictionary()
{
    _real_obj = new FakeDict;
}

bool    MyDictionary::has_key(const char *const key)
{
//    map<int,Bar>::iterator it = m.find('2');
    FakeDict::iterator it;

    if (_real_obj->size())
    {
        if (this->get_key(key, &it))
            return true;
        else
            return false;
    }
    return false;
}

bool    MyDictionary::add_value_for_key(const char * const value, const char * const key)
{
    FakeDict::iterator it;
    
    if (this->get_key(key, &it))
    {
        this->_update(value, it);
        return true;
    }
    else
    {
        this->_add(value, key);
        return false;
    }
}

bool    MyDictionary::delete_key(const char * const key, char **value)
{
    FakeDict::iterator it;
    std::string extracted;
    
    if (this->get_key(key, &it))
    {
        extracted = it->second.c_str();
        *value = strdup(extracted.c_str());
//        value = strdup(->c_str());
        _real_obj->erase(it);
        return true;
    }
    return false;
}

bool    MyDictionary::get_value_for_key(const char * const key, char **value)
{
    return this->extract_value_for_key(value, key);
}

//private
bool    MyDictionary::_add(const char * const value, const char * const key)
{
    _real_obj->insert(FakePair(key, value));
    return true;
}

bool    MyDictionary::_update(const char * const value, FakeDict::iterator it)
{
    it->second = std::string(value);
    return true;
}

bool  MyDictionary::extract_value_for_key(char **value, const char * const key)
{
    FakeDict::iterator it;
    
    if (this->get_key(key, &it))
    {
        *value = strdup(it->second.c_str());
        return true;
    }
    return false;
}

bool  MyDictionary::get_key(const char * const key, FakeDict::iterator *it)
{
    *it = _real_obj->find(key);
    return (*it != _real_obj ->end());
}

FakeDict::iterator  MyDictionary::get_iterator_for_key(const char * const key)
{
    return _real_obj->find(key);
}
