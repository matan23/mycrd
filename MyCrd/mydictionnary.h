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

    bool has_key(const char * const key);
    bool add_value_for_key(const char * const value, const char * const key);
};

#endif /* defined(__MyCrd__mydictionnary__) */
