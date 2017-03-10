#include"note.h"

#ifndef NOTEBOOK_H
#define NOTEBOOK_H

class Notebook
{
public:
	//Notebook();
	Notebook(const string& name = NAME_NEW_NOTEBOOK);
	~Notebook();

	Notebook *getObject(){ return this; }
	long getSize();

	Note &getNote(int index){ return arrNotes[index]; }
	vector<Note> &getNoteArray(){ return arrNotes; }

	bool getNote(Note &out, string name);
	string getName(){ return strName; }
	int getNoteWidth(int index);
	void resizeNoteArray(int newSize){ arrNotes.resize(newSize); }

	void createNote(const string &name);
	void updateNote(Note&, string);
	void displayNotes(string strName = "all");

	Notebook& operator=(Notebook);

private:
	vector<Note> arrNotes;
	//string strTimestamp;
	string strName;
};

#endif