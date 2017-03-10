/*
	Author: Brian Gosalvez
	Program: take notes in multiple notebooks
	Desc: manage notebooks, each with many notes, each with many lines/items.
	Caveat: works if omit file i/o.
*/
#include<iostream>
#include<iomanip>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
#include<sys/stat.h>

#include"notebook.h"
#include"commands.h"

using namespace std;
using std::cout;

void printHelp();
void testObjects(Notebook *);
bool fileExists(const string&);
bool getNotebookByName(vector<Notebook> &in, Notebook &out, string search);
bool updateNotebookVector(vector<Notebook> &object, Notebook &in, string name);
bool writeNotebooksToFile(ofstream &out, vector<Notebook> data);

bool dbg = true;

// only working with one file here so this is ok
const string filename = "Debug/local_notebook.dat";
long arrSize = 0;

int main()
{
	// simple types
	bool isRunning = true;
	string strInput;
	
	// objects
	Notebook curNB(NAME_NEW_NOTEBOOK);
	vector<Notebook> arrNotebooks;
	Notebook *arrNB = new Notebook(NAME_NEW_NOTEBOOK);
	Notebook *cnb = new Notebook(NAME_NEW_NOTEBOOK);
//	vector<Notebook> testNB;

	// streams
	stringstream ss;
	ofstream fsOut;
	ifstream fsIn;


	// structure/enum for user commands
	struct COMMANDS
	{
		string USE = "use";
		string OPEN = "open";
		string CLOSE = "close";
		string CREATE = "create";
		string DELETE = "delete";
		string EDIT = "edit";
		string VIEW = "view";
		string LIST = "list";
		string QUIT = "quit";
	}sCommands;


	// attempt to open file; read contents into arrNotebooks
	fsIn.open(filename, ios::binary);

	if(fileExists(filename))
	{

		// get file size 
		fsIn.seekg(0, ifstream::end);
		long fileSize = fsIn.tellg();
		fsIn.seekg(0, ifstream::beg);
		// translate that to vector->size()
		arrSize = fileSize / sizeof(Notebook);
		
		/*
		Notebook placeholder("placeholder");
		// read until end-of-file
		while (!(fsIn.peek() == ifstream::traits_type::eof()))
		{
			// read
			//arrNotebooks.resize(arrSize);
			fsIn.read((char *)&placeholder, sizeof(Notebook));
			arrNotebooks.push_back(placeholder);
		}
*/
		if (!(fsIn.peek() == ifstream::traits_type::eof()))
		{
			// read
			//arrNotebooks.resize(arrSize);
			arrNB = new Notebook[arrSize];
			fsIn.read((char *)&arrNB[0], fileSize);
		}
		
		// close file
		fsIn.close();
		
		
		if (dbg)
		{
			cout << "current notebooks:\n";
			if (arrNotebooks.size() > 0)
			{
				for (Notebook nn : arrNotebooks)
					cout << '\t' << nn.getName() << "\n";
			}
			if (sizeof(arrNB)>0)
			{
				for (int i = 0; i < arrSize; i++)
					cout << '\t' << arrNB[i].getName() << "\n";
			}

		}
	
	}

	// prompt
	cout << "Example:\n\tcreate notebook MyNotebook\n";

	//
	// main loop
	//
	while (isRunning)
	{
		if (dbg)
		{
			cout << "\n<< [ debug ] >>\n";

			cout << "arrNotebooks.size()*sizeof(Notebook): " << arrNotebooks.size()*sizeof(Notebook) << "\n";
			cout << "curNB: " << curNB.getName() << '\n';
			cout << "curNB size: " << curNB.getSize() << '\n';
		}


		string command, target, custom;

		// reset stringstream
		ss.clear();
		ss.str("");

		// put user input into stringstream
		getline(cin, strInput);
		ss << strInput;

		if (ss >> command)
		{
			if (command == sCommands.QUIT)
			{
				isRunning = 0;
				exit(0);
				break;
			}

			if (command == sCommands.LIST)
			{
				if (!(ss >> target))
				{
					printHelp();
				}
				else
				{
					if (target == "notebooks")
					{
						cout << "current notebooks:\n";

						// loop through vector<Notebook> and disp names
						// (make sure arrNotebooks exists and != null)
						for (Notebook nn : arrNotebooks)
							cout << '\t' << nn.getName() << "\n";
					}
				}
			}

			if (command == sCommands.OPEN)
			{
				if (!(ss >> target))
				{
					printHelp();
				}
				else
				{
					/*/if (getNotebookByName(arrNotebooks, curNB, target))
					{
						cout << "opened notebook \"" << curNB.getName() << "\"\n";
						//testObjects(&curNB);
						//updateNotebookVector(arrNotebooks, curNB, curNB.getName());
					}
					else
					{
						cout << "notebook not found.\n";
					}
					*/
					for (int i = 0; i < arrSize; i++)
					{
						if (arrNB[i].getName() == target)
							cnb = &arrNB[i];
					}
					cout << "opened notebook \"" << cnb->getName() << "\"\n";

				}
			}

			if (command == sCommands.CREATE)
			{
				if (!(ss >> target))
				{
					printHelp();
				}
				else
				{
					if (!(ss >> custom))
					{
						cout << "needs a name.\n\n";
						printHelp();
					}
					else
					{
						if (target == "notebook")
						{
							// MUST ALLOCATE new OBJECT ON HEAP
							// otherwise it creates SOMETHING ELSE
							// which was VERY ANNOYING
							Notebook *newNB = new Notebook(custom);
							long oldSize = arrSize;
							arrSize++;
							Notebook *oldNB = arrNB;
							arrNB = new Notebook[arrSize];
							for (int i = 0; i < oldSize; i++)
								arrNB[i] = oldNB[i];
							arrNB[oldSize] = *newNB; // arrSize - 1
							

							// (is newNB mutable from within a vector?)
							cout << "created notebook \"" << newNB->getName() << "\".\n";

							// write newest Notebook to file
							fsOut.open(filename, ios::app|ios::binary);
							fsOut.write((char *)newNB, sizeof(Notebook));

							// close file
							fsOut.close();

							/*
							// write entire arrNotebooks to file
							fsOut.open(filename, ios::binary);
							fsOut.write((char *)&arrNotebooks[0], arrNotebooks.size()*sizeof(Notebook));
							*/
							if (dbg)
							{
								cout << "sizeof(Notebook): " << sizeof(Notebook) << '\n';
								cout << "arrNotebooks.size(): " << arrNotebooks.size() << '\n';
							}

						}
						else if (target == "note")
						{
							if (cnb->getName() == NAME_NEW_NOTEBOOK)
							{
								cout << "open a notebook to add notes.\n";
							}
							else
							{
								//curNB.createNote(custom);
								cnb->createNote(custom);
								
								// confirm
								cout << "Note created. Type \"edit " + custom + "\" to edit this note.\n";

								// update the vector
								//if (!updateNotebookVector(arrNotebooks, curNB, curNB.getName()))
									//cout << "error updating notebooks.\n";

								// write to file
								fsOut.open(filename, ios::binary);
								fsOut.write((char *)&arrNotebooks[0], arrNotebooks.size()*sizeof(Notebook));
								fsOut.close();
								cout << "file written.\n\n";

								if (dbg)
								{
									cout << "sizeof(arrNotebooks): " << arrNotebooks.size()*sizeof(Notebook) << "\n";
								}
							}
						}
					}
				}
			}

			if (command == sCommands.VIEW)
			{
				if (!(ss >> target))
				{
					printHelp();
				}
				else
				{
					if (target == "notes"|| target == "note")
					{
						if (curNB.getName() == NAME_NEW_NOTEBOOK)
						{
							cout << "open a notebook to view its notes.\n\n";
						}
						else
						{
							if (ss.peek() != stringstream::traits_type::eof())
							{					
								string name = ss.str().substr((command.length() + target.length())+2, string::npos);
								curNB.displayNotes(name);
							}
							else
								curNB.displayNotes();
						}
					}
				}
			}

			if (command == sCommands.EDIT)
			{
				if (!(ss >> target))
				{
					printHelp();
				}
				else // name given
				{
					Note thisNote;
					if (!curNB.getNote(&thisNote, target))
					{
						cout << "note not found in current notebook.\n";
					}
					else
					{
						// prompt
						cout << "type what you want, then type a \"*\" by itself to stop.\n";

						string item;
						while (getline(cin, item))
						{
							if (item == "*")
								break;
							else
							{
								if (dbg)
								{
									cout << "\tadded: " << item << endl;
								}

								// add it
								thisNote.addLineItem(item);

								// update notebook & contents in vector
								curNB.updateNote(&thisNote, thisNote.getTitle());
								updateNotebookVector(arrNotebooks, curNB, curNB.getName());

							}
						}

						if (!writeNotebooksToFile(fsOut, arrNotebooks))
							cout << "error writing notebook after editing note.\n\n";
						else
							cout << "file written.\n\n";
					}

				}
			}
		}
	}


	// close file
	if (fsOut.is_open())
		fsOut.close();

	// delete objects


	//testObjects(NULL);

	//pause
	int tempWait;
	while (cin >> tempWait);

	// clean exit
	return 0;
}

void testObjects(Notebook *myNB=NULL)
{
	if(!myNB) 
		myNB = new Notebook("myNB");

	cout << "[\t" << myNB->getName() << "\t]\n";

	myNB->createNote("todo list");

	myNB->getNote(0)->addLineItem("buy baking soda");
	myNB->getNote(0)->addLineItem("clean car");
	myNB->getNote(0)->addLineItem("sell amplifier");

	myNB->createNote("groceries");
	myNB->getNote(1)->addLineItem("bread");
	myNB->getNote(1)->addLineItem("eggs");
	myNB->getNote(1)->addLineItem("milk");

	myNB->displayNotes();
}

bool getNotebookByName(vector<Notebook> &object, Notebook &out, string name)
{

	for (int a = 0; a < object.size(); a++)
	{
		if (object.at(a).getName() == name)
		{
			// reassign & leave
			out = object[a];
			return 1;
		}
		else
		{
			// "name" is not element "a", but keep going
		}
	}
	

	return 0;
}

void printHelp()
{
	cout << "[(open|create|delete)|view|list] [(notebook|note|item)|notes|notebooks] [name/content]\n\n";
}

bool fileExists(const string &name)
{
	struct stat buf;
	if (stat(name.c_str(), &buf) != -1)
		return true;
	else
		return false;
}

bool updateNotebookVector(vector<Notebook> &object, Notebook &in, string name)
{
	for (int a = 0; a < object.size(); a++)
	{
		if (object[a].getName() == name)
		{
			// reassign & leave
			/*/ doesn't work:
				object.swap(vec)
			*/
			object.at(a).resizeNoteArray(in.getNoteArray()->size());
			object[a] = in;
			return 1;
		}
		else
		{
			// "name" is not element "a", but keep going
		}
	}


	return 0;
}


bool writeNotebooksToFile(ofstream &out, vector<Notebook> data)
{
	// write entire arrNotebooks to file
	// so we don't have to figure out how
	// to seek to the correct position in file
	out.open(filename, ios::binary);
	out.write((char *)&data[0], data.size()*sizeof(Notebook));
	out.close();

	return (out.fail()) ? false : true;
}