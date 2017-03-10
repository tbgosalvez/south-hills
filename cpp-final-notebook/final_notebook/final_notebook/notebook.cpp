#include"notebook.h"
#include<iomanip>

Notebook::Notebook(const string &name)
{
	/*
	std::chrono::time_point<std::chrono::system_clock> now;
	now = std::chrono::system_clock::now();

	std::time_t end_time = std::chrono::system_clock::to_time_t(now);

	strTimestamp = std::ctime(&end_time);
	strTimestamp = strTimestamp.substr(0,strTimestamp.find('\n'));
	*/

	strName = name;
}

void Notebook::createNote(const string &content)
{
	Note newNote(content);
	arrNotes.push_back(newNote);
}

bool Notebook::getNote(Note &out, string name)
{
	for (int a = 0; a < arrNotes.size();a++)
	{
		if (arrNotes[a].getTitle() == name)
		{
			out = arrNotes[a];
			return 1;
		}
	}

	return false;
}

void Notebook::updateNote(Note &in, string name)
{
	for (int a = 0; a < arrNotes.size(); a++)
	{
		if (arrNotes[a].getTitle() == name)
		{
			arrNotes[a].resizeItemArray(in.getLineItemArray().size());
			arrNotes[a] = in;
		}
	}
}
void Notebook::displayNotes(string strName)
{
	//todo: lots of iostream & iomanip formatting

	int lineWidth = 10; //default

	// loop through all Notes
	if (strName == "all")
	{
		for (int a = 0; a < arrNotes.size(); a++)
		{
			lineWidth = getNoteWidth(a);
			cout.width(lineWidth);
			cout.fill('-'); //draw top
			cout << '\n';
			cout.fill(' ');	//reset to blank for everything else

			//draw note name/title
			cout << arrNotes[a].getTitle() << ":\n\n";

			//draw item list (all items)
			for (int b = 0; b < arrNotes[a].getLineItemArray().size(); b++)
			{
				cout <<  "|+ " << arrNotes[a].getLineItem(b).toString() << "\n";
			}
			cout.width(lineWidth);
			cout.fill('-');
			cout << '\n';

			if (dbg)
			{
				cout << "size of this note: " << arrNotes[a].getSize() << '\n';
			}
		}
	}
	else
	{
		Note curNote;
		if (!getNote(curNote, strName))
		{
			cout << "Note not found.\n";
		}
		else
		{
			lineWidth = curNote.getNoteWidth();
			cout.width(lineWidth);
			cout.fill('-'); //draw top
			cout << '\n';
			cout.fill(' ');	//reset to blank for everything else

			//draw note name/title
			cout << curNote.getTitle() << ":\n\n";

			//draw item list (all items)
			for (int b = 0; b < curNote.getLineItemArray().size(); b++)
			{
				cout << "|+ " << curNote.getLineItem(b).toString() << "\n";
			}
			cout.width(lineWidth);
			cout.fill('-');
			cout << '\n';

			if (dbg)
			{
				cout << "size of this note: " << curNote.getSize() << '\n';
			}
		}
	}


}

int Notebook::getNoteWidth(int index)
{
	short result = 10;//default; arbitrary

	for (int i = 0; i < arrNotes[index].getLineItemArray().size(); i++)
	{
		int curSize = arrNotes[index].getLineItem(i).toString().length();
		if (curSize > result)
		{
			//cout << curSize << endl;
			result = curSize + 5;
		}
	}

	return result;
}

long Notebook::getSize()
{
	long lTotal = sizeof(*this)+strName.size();

	for (Note &nn : arrNotes)
	{
		lTotal += nn.getSize();
	}

	return lTotal;
}


Notebook& Notebook::operator=(Notebook other)
{
	if (this == &other)
		return *this;

	// accomodate more notes
	arrNotes.resize(other.arrNotes.size());

	// accomodate more line items per note
	for (int i = 0; i < arrNotes.size(); i++)
	{
		arrNotes[i].getLineItemArray().resize(other.arrNotes[i].getLineItemArray().size());
	}

	// copy fields
	arrNotes = other.arrNotes;
	strName = other.strName;

	return *this;
}

Notebook::~Notebook(){}
