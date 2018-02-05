// append.cpp -- appending information to a file
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>      // (or stdlib.h) for exit()

const char * file = "guests.txt";
int main()
{
    using namespace std;
    char ch;

// show initial contents
    ifstream fin;
    fin.open(file);

    if (fin.is_open())
    {
        cout << "Here are the current contents of the "
             << file << " file:\n";
        while (fin.get(ch))
            cout << ch;
        fin.close();
    }

// add new names
    ofstream fout(file, ios::out | ios::app);
    if (!fout.is_open())
    {
        cerr << "Can't open " << file << " file for output.\n";
        exit(EXIT_FAILURE);
    }

    cout << "Enter guest names (enter a blank line to quit):\n";
    string name;
// 从命令行上获取一行数据，以回车结束
    while (getline(cin,name) && name.size() > 0)
    {
		cout << "what u input is:" << name << endl;
        fout << name << endl;
    }
    fout.close();

// show revised file
    fin.clear();    // not necessary for some compilers
    fin.open(file);
    if (fin.is_open())
    {
        cout << "Here are the new contents of the "
             << file << " file:\n";
        while (fin.get(ch))
            cout << ch;
        fin.close();
   }
    cout << "Done.\n";

// Kevin add test codes
	std::string test = "123456789\nThis is test string.\nWrite into the file test.txt\n";
	std::string filename = "test.txt";

	ofstream ofstr;
	ofstr.open(filename, ios::out | ios::app);
	
	/*
		以上代码可以简化为：
		ofstream ofstr(filename, ios::out | ios::app);
	 */
	
	ofstr << test;
	ofstr.close();

	ifstream ifst;
	ifst.open(filename);
	
	if (ifst.is_open())
	{
		char ch = 0;
		while (ifst.get(ch))
		{
			cout << ch;
		}
		ifst.close();
	}

    return 0; 
}
