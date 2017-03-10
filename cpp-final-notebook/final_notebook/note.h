#include<vector>
#include"line_item.h" //using namespace std

#ifndef NOTE_H
#define NOTE_H

class Note
{
public:
	Note();
	Note(const string& title) :strTitle(title){}
	~Note();

	long getSize();

	string getTitle(){ return strTitle; }
	string getTimestamp(){ return strTimestamp; }
	LineItem getLineItem(int index){ return arrItems[index]; }
	vector<LineItem> getLineItemArray(){ return arrItems; }
	
	//void setTitle(const string &title);
	void addLineItem(const string &content);
	void resizeItemArray(int newsize){ arrItems.resize(newsize); }
	int getNoteWidth();

private:
	std::vector<LineItem> arrItems;

	string strTimestamp;
	string strTitle;
};

#endif