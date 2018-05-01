//
//  Row.h
//  NBA_DB
//
//  Created by Alan Bennett on 1/16/18.
//  Copyright © 2018 Alan Bennett. All rights reserved.
//

#ifndef Row_h_
#define Row_h_

#include <string>
#include <vector>
#include "RuntimeException.h"
#include "InputCheck.h"

class RowException : public RuntimeException
{
public:
    RowException() { message = "Error: Generic rows not allowed."; }
};

class Row
{
protected:
    std::vector<std::string> columns;
    
public:
    size_t columnCount() { return columns.size(); }
    std::string getColumn(int i) { return columns[i]; }
    virtual std::string getAttribute(std::string attribute) { throw RowException(); }
    
    std::string toString()
    {
        std::string str;
        
        for(int i = 0; i < columns.size(); i++)
        {
            size_t j = columns[i].find_first_of("+");
            
            if(j != std::string::npos)
                columns[i][j] = ' ';
            
            str += columns[i];
            str += " ";
        }
        
        return str;
    }
};

#endif /* Row_h */
