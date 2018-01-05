#include <iostream>
#include <deque>

using namespace std;

int main()
{
	/* 定义一个有10int数据的deque */
	deque<int> d(10);
	
	for (int i=0; i<d.size(); i++)
		d[i] = i;
	
	for (int i=0; i<d.size(); i++)
		cout << d.at(i) << " ";
	cout << endl;
	
	d.push_back(88);
	d.push_front(11);
	
	for (int i=0; i<d.size(); i++)
		cout << d.at(i) << " ";	
	cout << endl;
	
	d.pop_back();
	d.pop_front();
	
	for (int i=0; i<d.size(); i++)
		cout << d.at(i) << " ";	
	cout << endl;
	
	return 0;
}