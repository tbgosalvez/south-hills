#include"note.h"

Note::Note()
{
	std::chrono::time_point<std::chrono::system_clock> now;
	now = std::chrono::system_clock::now();

	std::time_t end_time = std::chrono::system_clock::to_time_t(now);

	strTimestamp = std::ctime(&end_time);

	strTitle = "New Note";
}

Note::~Note(){}

/*void Note::setTitle(const string& title)
{
	strTitle = title;
}*/

void Note::addLineItem(const string &content)
{
	LineItem newItem(content);
	arrItems.push_back(newItem);
}

int Note::getNoteWidth()
{
	int result = 1;

	for (int i = 0; i < getLineItemArray().size(); i++)
	{
		int curSize = getLineItem(i).toString().length();
		if (curSize > result)
		{
			//cout << curSize << endl;
			result = curSize + 5;
		}
	}

	return result;
}

long Note::getSize()
{
	long lTotal = sizeof(*this);

	for (LineItem l : arrItems)
	{
		lTotal += l.getSize();
	}

	return lTotal;
}