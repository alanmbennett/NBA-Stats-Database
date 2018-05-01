//
//  Command.h
//  NBA_DB
//
//  Created by Alan Bennett on 1/17/18.
//  Copyright © 2018 Alan Bennett. All rights reserved.
//

#ifndef Command_h
#define Command_h

#include <string>
#include <vector>

class Command
{
private:
    std::string command;
    std::vector<std::string> parameters;
public:
    Command();
    Command(std::string, std::vector<std::string>&);
    std::string getCommand();
    std::vector<std::string>& getParameters();
    std::string getParameterAt(int i);
    Command& operator=(const Command&);
    
    
    
};

#endif /* Command_h */
