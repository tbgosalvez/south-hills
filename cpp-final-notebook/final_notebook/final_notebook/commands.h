#include<string>

using std::string;

#ifndef COMMANDS_H
#define COMMANDS_H

class COMMANDS
{
public:
	static string CREATE,EDIT,DELETE,VIEW,USE;

	COMMANDS(){ CREATE = "create", EDIT = "edit", DELETE = "delete", VIEW = "view", USE="use"; }
	~COMMANDS(){}
};

#endif