//
//  Database.cpp
//  NBA_DB
//
//  Created by Alan Bennett on 1/16/18.
//  Copyright © 2018 Alan Bennett. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Database.h"

void Database::addTable(std::string title)
{
    Table temp(title);
    tables[title] = temp;
}

void Database::addRowTo(Row* row, std::string title)
{
    auto it = tables.find(title);
   
    it->second.addRow(row);
}

void Database::printAllFrom(std::string title)
{
    auto it = tables.find(title);
    
    for(int i = 0; i < it->second.rowCount(); i++)
    {
        std::cout << it->second.getRow(i)->toString() << std::endl;
    }
}

void Database::printAllFrom(std::string title, std::string attribute, std::string desired)
{
    auto it = tables.find(title);
    
    for(int i = 0; i < it->second.rowCount(); i++)
    {
        if(it->second.getRow(i)->getAttribute(attribute) == desired)
            std::cout << it->second.getRow(i)->toString() << std::endl;
    }
}

void Database::printAllFrom(std::string title, std::vector<std::string> attributes, std::vector<std::string> desires)
{
    auto it = tables.find(title);
    
    for(int i = 0; i < it->second.rowCount(); i++)
    {
        if(hasDesired(it->second.getRow(i),attributes, desires))
            std::cout << it->second.getRow(i)->toString() << std::endl;
    }
}

bool Database::hasDesired(Row* row, std::vector<std::string> attributes, std::vector<std::string> desires)
{
    for(int i = 0; i < attributes.size(); i++)
    {
        if(row->getAttribute(attributes[i]) == "")
            continue;
        
        else if(row->getAttribute(attributes[i]) != desires[i])
            return false;
    }
    
    return true;
}

Row* Database::getBestFrom(std::string title, std::string attribute1, std::string attribute2, std::string desired)
{
    auto it = tables.find(title);
    Row* max = NULL;
    int maxInt = 0;
    std::string currentAttr;
    
    for(int i = 0; i < it->second.rowCount(); i++)
    {
        if(max == NULL && it->second.getRow(i)->getAttribute(attribute2) == desired)
        {
            max = it->second.getRow(i);
            maxInt = stoi(it->second.getRow(i)->getAttribute(attribute1));
        }
        
        else if(maxInt < stoi(it->second.getRow(i)->getAttribute(attribute1)) && it->second.getRow(i)->getAttribute(attribute2) == desired)
        {
            max = it->second.getRow(i);
            maxInt = stoi(it->second.getRow(i)->getAttribute(attribute1));
        }
    }
    
    return max;
}



