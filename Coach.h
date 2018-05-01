//
//  Coach.h
//  NBA_DB
//
//  Created by Alan Bennett on 1/16/18.
//  Copyright © 2018 Alan Bennett. All rights reserved.
//

#ifndef Coach_h
#define Coach_h

#include "Row.h"

class Coach : public Row
{
private:
    std::vector<std::string>& getColumns();
    bool isValidId(std::string str);
    
public:
    Coach(std::vector<std::string>& parameters);
    virtual std::string getAttribute(std::string attribute);

    std::string getId();
    std::string getYear();
    std::string getFirstName();
    std::string getLastName();
    std::string getSeasonWin();
    std::string getSeasonLoss();
    std::string getPlayoffWin();
    std::string getPlayoffLoss();
    std::string getTeam();
    std::string getNetWins();
};




#endif /* Coach_h */
