//
//  Table.h
//  NBA_DB
//
//  Created by Alan Bennett on 1/17/18.
//  Copyright © 2018 Alan Bennett. All rights reserved.
//

#ifndef Table_h_
#define Table_h_

#include <vector>
#include <unordered_map>
#include <string>
#include "Row.h"
#include "RuntimeException.h"

class Table
{
private:
    std::string title;
    std::vector<Row*> rows;
public:
    Table();
    Table(std::string title);
    Table(const Table& t);
    void addRow(Row* row);
    size_t rowCount();
    Row* getRow(int i);
};

#endif /* Table_h */
