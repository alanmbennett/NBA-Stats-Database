//
//  Table.cpp
//  NBA_DB
//
//  Created by Alan Bennett on 1/18/18.
//  Copyright © 2018 Alan Bennett. All rights reserved.
//

#include "Table.h"

Table::Table()
{
    
}

Table::Table(const Table& t)
{
    title = t.title;
    rows = t.rows;
}

Table::Table(std::string title)
{
    this->title = title;
}

void Table::addRow(Row* row)
{
    rows.push_back(row);
}

size_t Table::rowCount()
{
    return rows.size();
}

Row* Table::getRow(int i)
{
    return rows[i];
}
