
#include <iostream>
#include <vector> // vector的头文件

//
// std::vector
using namespace std;

int main()
{
	vector<int> v;
	
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	
	cout << "Size of vector : " << v.size() << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << " " << v[i];
	}
	cout << endl;
	
	v.pop_back();
	cout << endl << "Size of vector : " << v.size() << endl;
	
	for (int i = 0; i < v.size(); i++) {
		cout << " " << v[i];
	}
	cout << endl;	
	
	return 0;
}

