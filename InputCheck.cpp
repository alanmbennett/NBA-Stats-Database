//
//  InputCheck.cpp
//  NBA_DB
//
//  Created by Alan Bennett on 1/20/18.
//  Copyright © 2018 Alan Bennett. All rights reserved.
//

#include "InputCheck.h"

bool isNeg(int num)
{
    if(num < 0)
        return true;
    
    return false;
}

bool containsAlphaNum(std::string str)
{
    std::string temp = "";
    
    for(int i = 0; i < str.length(); i++)
    {
        if (!isalnum(str[i]))
            return false;
    }
    
    return true;
}

