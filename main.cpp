//
//  main.cpp
//  NBA_DB
//
//  Created by Alan Bennett on 1/16/18.
//  Copyright © 2018 Alan Bennett. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include "Command.h"
#include "Database.h"
#include "Coach.h"
#include "Team.h"
#include "RuntimeException.h"
using namespace std;

void displayMessage();
Command fetchCommand(string input);
vector<string> parseParams(istream& is, char delim, bool load);
string removeSpace(string str);

int main()
{
    Database db;
    string input;
    const string coachTitle = "Coaches", teamTitle = "Teams";
    Command cmd;

    db.addTable(coachTitle);
    db.addTable(teamTitle);
    
    displayMessage();
    
    while(getline(cin, input))
    {
        try
        {
            cmd = fetchCommand(input);
        
            if(cmd.getCommand() == "add_coach")
            {
                db.addRowTo(new Coach(cmd.getParameters()), coachTitle);
            }
            
            else if(cmd.getCommand() == "add_team")
            {
                db.addRowTo(new Team(cmd.getParameters()), teamTitle);
            }
            
            else if(cmd.getCommand() == "load_coaches")
            {
                ifstream inFile(cmd.getParameterAt(0));
                
                getline(inFile, input);
                
                while(getline(inFile, input))
                {
                    try
                    {
                        istringstream iss(input);
                        vector<string> params = parseParams(iss, ',', true);
                        db.addRowTo(new Coach(params), coachTitle);
                    }
                    catch(InvalidDataException& ex)
                    {
                        cout << ex.getMessage() << endl;
                    }
                }
                
                inFile.close();
            }
            
            else if(cmd.getCommand() == "load_teams")
            {
                ifstream inFile(cmd.getParameterAt(0));
                
                getline(inFile, input);
                
                while(getline(inFile, input))
                {
                    try
                    {
                        istringstream iss(input);
                        vector<string> params = parseParams(iss, ',', false);
                        db.addRowTo(new Team(params), teamTitle);
                    }
                    catch(InvalidDataException& ex)
                    {
                        cout << ex.getMessage() << endl;
                    }
                }
                
                inFile.close();
            }
            
            else if(cmd.getCommand() == "print_coaches")
            {
                db.printAllFrom(coachTitle);
            }
            
            else if(cmd.getCommand() == "print_teams")
            {
                db.printAllFrom(teamTitle);
            }
            
            else if(cmd.getCommand() == "coaches_by_name")
            {
                string str = cmd.getParameterAt(0);
                
                size_t j = str.find_first_of("+");
                
                if(j != std::string::npos)
                    str[j] = ' ';
                
                db.printAllFrom(coachTitle, "last_name", str);
            }
            
            else if(cmd.getCommand() == "teams_by_city")
            {
                db.printAllFrom(teamTitle, "location", cmd.getParameterAt(0));
            }
            
            else if(cmd.getCommand() == "best_coach")
            {
                Row* best = db.getBestFrom(coachTitle, "net_wins", "season", cmd.getParameterAt(0));
                cout << best->getAttribute("first_name") << " " << best->getAttribute("last_name") << endl;
                best = NULL;
            }
            
            else if(cmd.getCommand() == "search_coaches")
            {
                vector<string> fields;
                vector<string> desires;
                
                for(int i = 0; i < cmd.getParameters().size(); i++)
                {
                    istringstream iss(cmd.getParameterAt(i));
                    
                    getline(iss, input, '=');
                    
                    fields.push_back(input);
                
                    getline(iss, input);
                        
                    size_t j = input.find_first_of("+");
                        
                    if(j != std::string::npos)
                        input[j] = ' ';
                        
                    desires.push_back(input);
                }
                
                db.printAllFrom(coachTitle, fields, desires);
            }
            
            else if(cmd.getCommand() == "exit")
            {
                break;
            }
            
            else
            {
                cout << "Error: invalid command! Try again." << endl << endl;
            }
        }
        
        catch(InvalidDataException& ex)
        {
            cout << ex.getMessage() << endl;
        }
        
        displayMessage();
    }

    return 0;
}

void displayMessage()
{
    cout << "Please enter a command." << endl;
    cout << "$ ";
}

Command fetchCommand(string input)
{
    istringstream iss(input);
    string command;
    vector<string> pieces;
    
    getline(iss, command, ' ');
    
    pieces = parseParams(iss, ' ', false);
    
    return Command(command, pieces);
}

vector<string> parseParams(istream& is, char delim, bool load)
{
    string parameter;
    vector<string> parameters;
    int i = 0;
    
    while(getline(is, parameter, delim))
    {
        if(load == true && i == 2)
        {
            i++;
            continue;
        }
        else
        {
            parameter = removeSpace(parameter);
            parameters.push_back(parameter);
        }
        
        i++;
    }
    
    return parameters;
}



string removeSpace(string str)
{
    auto beg = str.find_first_not_of(' ');
    auto end = str.find_last_not_of(' ');
    
    if(beg == std::string::npos)
        return str; 
    
    return str.substr(beg, end - beg + 1);
}
