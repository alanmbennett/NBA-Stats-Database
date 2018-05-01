//
//  Team.h
//  NBA_DB
//
//  Created by Alan Bennett on 1/17/18.
//  Copyright © 2018 Alan Bennett. All rights reserved.
//

#ifndef Team_h
#define Team_h

#include "InputCheck.h"
#include "RuntimeException.h"
#include "Row.h"

class Team : public Row
{
private:
    
public:
    Team(std::vector<std::string>& parameters);
    virtual std::string getAttribute(std::string attribute);
    
    std::string getId();
    std::string getLoc();
    std::string getName();
    std::string getLeague();
    
    
    
    
};

#endif /* Team_h */
