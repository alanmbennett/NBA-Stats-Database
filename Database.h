//
//  Database.h
//  NBA_DB
//
//  Created by Alan Bennett on 1/16/18.
//  Copyright © 2018 Alan Bennett. All rights reserved.
//

#ifndef Database_h_
#define Database_h_

#include <string>
#include <unordered_map>
#include "Row.h"
#include "Table.h"
#include "RuntimeException.h"

class Database
{
private:
    std::unordered_map<std::string, Table> tables;
    bool hasDesired(Row* row, std::vector<std::string> attributes, std::vector<std::string> desires);
    
public:
    void addTable(std::string title);
    void addRowTo(Row* row, std::string title);
    void printAllFrom(std::string title);
    void printAllFrom(std::string title, std::string attribute, std::string desired);
    void printAllFrom(std::string title, std::vector<std::string> attributes, std::vector<std::string> desires);
    Row* getBestFrom(std::string title, std::string attribute1, std::string attribute2, std::string desired);
};


#endif /* Database_h */
