
#include <iostream>
#include <vector> // vector的头文件

//
// std::vector
using namespace std;

int main()
{
	vector<int> v;

	v.insert(v.begin(), 'a');
	v.insert(v.begin(), 'b');
	v.insert(v.begin(), 'c');

	v.insert(v.begin() + 1, 5, 't');

	for (int i=0; i<v.size(); i++) {
		cout << " " << v[i];
	}

	cout << endl;

	v.erase(v.begin() + 1, v.begin() + 5);
	for (int i=0; i<v.size(); i++) {
		cout << " " << v[i];
	}

	cout << endl;

	return 0;
}

