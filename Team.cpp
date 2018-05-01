//
//  Team.cpp
//  NBA_DB
//
//  Created by Alan Bennett on 1/21/18.
//  Copyright © 2018 Alan Bennett. All rights reserved.
//

#include "Team.h"

Team::Team(std::vector<std::string>& parameters)
{
    if(parameters.size() < 4)
        throw InvalidDataException("Error: Not enough arguments.");
    if(parameters.size() > 4)
        throw InvalidDataException("Error: Too many arguments.");
    if(!containsAlphaNum(parameters[0]))
        throw InvalidDataException("Error: ID must consist of only digits and letters");
    
    columns = parameters;
}

std::string Team::getAttribute(std::string attribute)
{
    if(attribute == "Team_ID" || attribute == "team_ID")
        return getId();
    else if(attribute == "location")
        return getLoc();
    else if(attribute == "name")
        return getName();
    else if(attribute == "league")
        return getLeague();
    
    return "";
}

std::string Team::getId()
{
    return columns[0];
}

std::string Team::getLoc()
{
    return columns[1];
}

std::string Team::getName()
{
    return columns[2];
}

std::string Team::getLeague()
{
    return columns[3];
}
