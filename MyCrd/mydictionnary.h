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

#include <map>

typedef std::map <std::string, std::string> FakeDict;
typedef std::pair<std::string, std::string> FakePair;

class MyDictionary
{
private:
     FakeDict   *_real_obj;

public:
    MyDictionary();

    bool    has_key(const char * const key);
    bool    add_value_for_key(const char * const value, const char * const key);
    bool    delete_key(const char * const key, char **value);
    
    bool    get_value_for_key(const char * const key, char **value);
private:
    bool    extract_value_for_key(char **value, const char * const key);
    FakeDict::iterator  get_iterator_for_key(const char * const key);
    bool    get_key(const char * const key, FakeDict::iterator *it);
    bool    _add(const char * const value, const char * const key);
    bool    _update(const char * const value, FakeDict::iterator it);
};

#endif /* defined(__MyCrd__mydictionnary__) */
