#include<string>
#include<chrono>
#include<ctime>
#include<iostream>
#include "time.h"
#include "CONSTANTS.h"

// include everything here for simplicity.
// optimization not a concern
using namespace std;

#ifndef LINE_ITEM_H
#define LINE_ITEM_H


class LineItem
{
public:
	LineItem();
	LineItem(const string &content);

	~LineItem();

	long getSize();
	string toString(){ return strContent; }
//	string getStrTimestamp(){ return strTimestamp; }

private:
	string strContent;
//	string strTimestamp;
};

#endif