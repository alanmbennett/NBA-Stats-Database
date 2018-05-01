//
//  Coach.cpp
//  NBA_DB
//
//  Created by Alan Bennett on 1/18/18.
//  Copyright © 2018 Alan Bennett. All rights reserved.
//

#include <sstream>
#include "Coach.h"

Coach::Coach(std::vector<std::string>& parameters)
{
    if(!isValidId(parameters[0]))
        throw InvalidDataException("Error: ID must consist of less than 7 capital letters and two digits.");
    
    if(parameters.size() < 9)
        throw InvalidDataException("Error: Not enough arguments.");
    
    if(parameters.size() > 9)
        throw InvalidDataException("Error: Too many arguments.");
    
    if(isNeg(stoi(parameters[1])))
        throw InvalidDataException("Error: Season must be non-negative.");
    
    if(parameters[1].length() != 4)
        throw InvalidDataException("Error: Season must be a 4-digit number.");
    
    if(isNeg(stoi(parameters[4])))
        throw InvalidDataException("Error: Season Win must be non-negative.");
    
    if(isNeg(stoi(parameters[5])))
        throw InvalidDataException("Error: Season Loss must be non-negative.");
    
    if(isNeg(stoi(parameters[6])))
        throw InvalidDataException("Error: Playoff Win must be non-negative.");
    
    if(isNeg(stoi(parameters[7])))
        throw InvalidDataException("Error: Playoff Loss must be non-negative.");
    
    columns = parameters;
}

bool Coach::isValidId(std::string str)
{
    int capCount = 0;
    int digitCount = 0;
    
    if(!containsAlphaNum(str))
        return false;
    
    for(int i = 0; i < str.length(); i++)
    {
        if(isupper(str[i]))
            capCount++;
        else if(isdigit(str[i]))
            digitCount++;
    }
    
    if(capCount <= 7)
        if(digitCount <= 2)
            return true;
    
    return false;
}

std::string Coach::getAttribute(std::string attribute)
{
    std::string str;
    
    if(attribute == "Coach_ID" || attribute == "coach_ID")
        return getId();

    else if(attribute == "season")
        return getYear();
    
    else if(attribute == "first_name")
        return getFirstName();
    
    else if(attribute == "last_name" || attribute == "lastname")
        return getLastName();
    
    else if(attribute == "season_win")
        return getSeasonWin();
    
    else if(attribute == "season_loss")
        return getSeasonLoss();
    
    else if(attribute == "playoff_win")
        return getPlayoffWin();
    
    else if(attribute == "playoff_loss")
        return getPlayoffLoss();
    
    else if(attribute == "team")
        return getTeam();
    
    else if(attribute == "net_wins")
        return getNetWins();
    
    return "";
}

std::vector<std::string>& Coach::getColumns()
{
    return columns;
}

std::string Coach::getId()
{
    return columns[0];
}

std::string Coach::getYear()
{
    return columns[1];
}

std::string Coach::getFirstName()
{
    return columns[2];
}

std::string Coach::getLastName()
{
    std::string str = columns[3];
    
    size_t i = str.find_first_of("+");
    
    if(i != std::string::npos)
        str[i] = ' ';
    
    return str;
}

std::string Coach::getSeasonWin()
{
    return columns[4];
}

std::string Coach::getSeasonLoss()
{
    return columns[5];
}

std::string Coach::getPlayoffWin()
{
    return columns[6];
}

std::string Coach::getPlayoffLoss()
{
    return columns[7];
}

std::string Coach::getTeam()
{
    return columns[8];
}

std::string Coach::getNetWins()
{
    std::ostringstream oss;
    int netWins = (stoi(getSeasonWin())- stoi(getSeasonLoss())) + (stoi(getPlayoffWin()) - stoi(getPlayoffLoss()));
    oss << netWins;

    return oss.str();
}

