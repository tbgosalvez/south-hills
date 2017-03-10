#include<vector>
#include"line_item.h" //using namespace std

#ifndef NOTE_H
#define NOTE_H

class Note
{
public:
	Note();
	Note(const string& title);
	~Note();

	long getSize();

	LineItem &getLineItem(int index){ return arrItems[index]; }
	vector<LineItem> &getLineItemArray(){ return arrItems; }

	string getTitle(){ return strTitle; }
//	string getTimestamp(){ return strTimestamp; }
	
	//void setTitle(const string &title);
	int getNoteWidth();
	void addLineItem(const string &content);
	void resizeItemArray(int newsize){ arrItems.resize(newsize); }

private:
	std::vector<LineItem> arrItems;

//	string strTimestamp;
	string strTitle;
};

#endif