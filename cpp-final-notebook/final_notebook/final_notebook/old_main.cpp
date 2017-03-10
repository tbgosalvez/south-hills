/*
	Author: Brian Gosalvez
	Program: take notes in multiple notebooks
	Version: 3i
	Desc: manage notebooks, each with many notes, each with many lines/items.
	Caveat: works if omit file i/o.
			uncomment 'fsIn.open()' in beginning of main() to test.
	Comment: I have  tried at least three different ways of writing/reading the data.
			There will be many a commented-out line.
			The main problem: the nested vector data gets muddled in the process of writing/
			reading, i.e. you can see the Notebooks correctly in the arrNotebooks vector, BUT
			either the LineItems in each Note get muddled (earlier version) or all the Notes and 
			LineItems get garbled.
	Usage:
		Example:
			create notebook myNotebook
			open myNotebook
			create note ideas
			edit ideas
			pour chocolate syrup into a strawberry latte
			make shoes that sing
			*
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
void testObjects(Notebook &);
bool fileExists(const string&);
bool getNotebookByName(vector<Notebook> &in, Notebook &out, string search);
bool updateNotebookVector(vector<Notebook> &object, Notebook &in, string name);
bool writeNotebooksToFile(ofstream &out, vector<Notebook> &data, long size);
void writeNotebooksToFile(ofstream &out, vector<Notebook> &data);

//bool dbg = true;

const string strMainFile = "Debug/local_notebook.dat";
const string strSizeFile = "Debug/local_sizes.dat";
long lTotal = 0;

int main()
{
	// simple types
	bool isRunning = true;
	string strInput;
	
	// objects
	Notebook curNB(NAME_NEW_NOTEBOOK);
	vector<Notebook> arrNotebooks;
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
	//fsIn.open(strMainFile, ios::binary);

	if(fileExists(strSizeFile))
	{
		int nResizeNB = 0, nResizeN = 0, nResizeLI = 0;
		long lDataSize = 0;
		//char *tempMem = 0;
		//Notebook placeholder("placeholder");
		//Notebook *placeholder = new Notebook();
		//vector<Notebook> *tempVec;

		// get file size 
		fsIn.seekg(0, ifstream::end);
		long fileSize = fsIn.tellg();
		fsIn.seekg(0, ifstream::beg);
		
		fsIn.open(strSizeFile, ios::binary);
		while (!(fsIn.peek() == ifstream::traits_type::eof()))
		{
			// read in sizes; resize every vector
			fsIn.read((char*)&nResizeNB, sizeof(int));
			arrNotebooks.resize(nResizeNB);

			for (int i = 0; i < nResizeNB; i++)
			{
				fsIn.read((char*)&nResizeN, sizeof(int));
				arrNotebooks[i].getNoteArray().resize(nResizeN);

				for (int a = 0; a < nResizeN; a++)
				{
					fsIn.read((char*)&nResizeLI, sizeof(int));
					arrNotebooks[i].getNote(a).getLineItemArray().resize(nResizeLI);
				}
			}
		}
		// close it
		fsIn.close();

		
		fsIn.open(strMainFile, ios::binary);
		// read until end-of-file
		while (!(fsIn.peek() == ifstream::traits_type::eof()))
		{
			/*//read entire array/vector

			fsIn.read((char*)&nResize, sizeof(int));
			arrNotebooks.resize(nResize);

			fsIn.read((char*)&lTotal, sizeof(long));

			tempMem = new char[lTotal];
			fsIn.read(tempMem, lTotal);
			tempVec = (vector<Notebook>*)tempMem;
			arrNotebooks = *tempVec;

			// read individual Notebooks
			fsIn.read((char*)&lTotal, sizeof(long));
			tempMem = new char[lTotal];

			fsIn.read(tempMem, lTotal);
			placeholder = (Notebook*)tempMem;

			arrNotebooks.push_back(*placeholder);
			*/
			 //read entire array/vector
			fsIn.read((char*)&lDataSize, sizeof(long));
			fsIn.read((char *)&arrNotebooks[0], lDataSize);

		}
		//close it
		fsIn.close();
		
		
		if (dbg)
		{
			cout << "current notebooks:\n";
			if (arrNotebooks.size() > 0)
			{
				for (Notebook &nn : arrNotebooks)
					cout << '\t' << nn.getName() << "\n";
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
		// re-calc total every cycle for writing
		lTotal = sizeof(arrNotebooks);
		//for (Notebook &nn : arrNotebooks)
			//lTotal += nn.getSize();	
		
		// info
		if (dbg)
		{
			cout << "\n<< [ debug ] >>\n";

			cout << "sizeof(arrNotebooks): " << sizeof(arrNotebooks) << '\n';
			cout << "total bytes arrNotebooks: " << lTotal << "\n";
			cout << "curNB: " << curNB.getName() << '\n';
			cout << curNB.getName() + " size: " << curNB.getSize() << '\n';
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
						for (Notebook &nn : arrNotebooks)
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
					if (getNotebookByName(arrNotebooks, curNB, target))
					{
						cout << "opened notebook \"" << curNB.getName() << "\"\n";
						//testObjects(curNB);
						//updateNotebookVector(arrNotebooks, curNB, curNB.getName());
					}
					else
					{
						cout << "notebook not found.\n";
					}
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

							arrNotebooks.push_back(*newNB);
							cout << "created notebook \"" << newNB->getName() << "\".\n";
							/*
							//write
							writeNotebooksToFile(fsOut, arrNotebooks);


							// write newest Notebook to file
							fsOut.open(strMainFile, ios::app|ios::binary);
							fsOut.write((char *)newNB, sizeof(Notebook));
							*/								
							// write entire arrNotebooks to file
							lTotal += sizeof(Notebook);
							if (!writeNotebooksToFile(fsOut, arrNotebooks, lTotal))
								cout << "error writing new notebook to file.\n";
							else
								cout << "file written.\n";

							if (dbg)
							{
								cout << "sizeof(Notebook): " << sizeof(Notebook) << '\n';
								cout << "arrNotebooks.size(): " << arrNotebooks.size() << '\n';
							}

						}
						else if (target == "note")
						{
							if (curNB.getName() == NAME_NEW_NOTEBOOK)
							{
								cout << "open a notebook to add notes.\n";
							}
							else
							{
								curNB.createNote(custom);
								
								// confirm
								cout << "Note created. Type \"edit " + custom + "\" to edit this note.\n";

								// update the vector
								if (!updateNotebookVector(arrNotebooks, curNB, curNB.getName()))
									cout << "error updating notebooks.\n";

								
								/*
								// write to file
								writeNotebooksToFile(fsOut, arrNotebooks);
								*/

								lTotal += sizeof(Note);
								if (!writeNotebooksToFile(fsOut, arrNotebooks, lTotal))
									cout << "error writing new note to file.\n";
								else
									cout << "file written.\n";
								if (dbg)
								{
									Note thisNote;
									curNB.getNote(thisNote, custom);
									cout << thisNote.getTitle() + " size:" << thisNote.getSize() << "\n";
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
					if (!curNB.getNote(thisNote, target))
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

								// update note in current (opened) notebook
								curNB.updateNote(thisNote, thisNote.getTitle());

								// update vector with current (opened) notebook
								updateNotebookVector(arrNotebooks, curNB, curNB.getName());

							}
						}

						/*
						// write
						writeNotebooksToFile(fsOut, arrNotebooks);
						*/


						// reset total bytes to write
							lTotal = 0;	
							for (Notebook &nn : arrNotebooks)
								lTotal += nn.getSize();
							if (!writeNotebooksToFile(fsOut, arrNotebooks, lTotal))
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

void testObjects(Notebook &myNB)
{
	cout << "[\t" << myNB.getName() << "\t]\n";

	myNB.createNote("todo list");

	myNB.getNote(0).addLineItem("buy baking soda");
	myNB.getNote(0).addLineItem("clean car");
	myNB.getNote(0).addLineItem("sell amplifier");

	myNB.createNote("groceries");
	myNB.getNote(1).addLineItem("bread");
	myNB.getNote(1).addLineItem("eggs");
	myNB.getNote(1).addLineItem("milk");

	myNB.displayNotes();
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

bool updateNotebookVector(vector<Notebook> &object, Notebook &from, string name)
{
	for (int a = 0; a < object.size(); a++)
	{
		if (object[a].getName() == name)
		{
			// reassign & leave
			object[a] = from;
			return 1;
		}
		else
		{
			// "name" is not element "a", but keep going
		}
	}


	return 0;
}


bool writeNotebooksToFile(ofstream &out, vector<Notebook> &data, long size)
{
	// write entire arrNotebooks to file
	// so we don't have to figure out how
	// to seek to the correct position in file

	/* read sequence
		(read vector.size
		resize vector) x 3

		read size of vector contents
		read contents into vector starting at element [0]
	*/
	int numNotebooks = data.size();
	int numNotes = 0;
	int numItems = 0;

	// write array sizes
	out.open(strSizeFile, ios::binary);
	out.write((char*)&numNotebooks, sizeof(int));

	for (Notebook &nb : data)
	{
		numNotes = nb.getNoteArray().size();
		out.write((char*)&numNotes, sizeof(int));

		for (short i = 0; i < nb.getNoteArray().size();i++)
		{
			numItems = nb.getNote(i).getLineItemArray().size();
			out.write((char*)&numItems, sizeof(int));
		}
	}
	out.close();

	// write vector data
	out.open(strMainFile, ios::binary);
	out.write((char *)&size, sizeof(size));
	out.write((char *)&data[0], size);
	out.close();

	return (out.fail()) ? false : true;
}

void writeNotebooksToFile(ofstream &out, vector<Notebook> &arrNotebooks)
{
	long size=0;
	// write individual notebook to file

	/* read sequence
		read in size
		read in Notebook for size bytes
		push Notebook into vector
	*/

	out.open(strMainFile, ios::binary);
	for (Notebook &nn : arrNotebooks)
	{
		size = nn.getSize();
		out.write((char *)&size, sizeof(size));
		out.write((char *)&nn, size);

		if (out.fail())
			cout << "error writing notebook after editing note.\n\n";
		else
			cout << '\n' + nn.getName() + " written.\n\n";
	}
	out.close();
}