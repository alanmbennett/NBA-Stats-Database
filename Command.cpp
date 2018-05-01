//
//  Command.cpp
//  NBA_DB
//
//  Created by Alan Bennett on 1/18/18.
//  Copyright © 2018 Alan Bennett. All rights reserved.
//

#include "Command.h"

Command::Command() { }

Command::Command(std::string command, std::vector<std::string>& parameters)
{
    this->command = command;
    this->parameters = parameters;
}

std::string Command::getCommand()
{
    return command;
}

std::vector<std::string>& Command::getParameters()
{
    return parameters;
}

std::string Command::getParameterAt(int i)
{
    return parameters[i];
}

Command& Command::operator=(const Command& c)
{
    command = c.command;
    parameters = c.parameters;
    
    return *this;
}
