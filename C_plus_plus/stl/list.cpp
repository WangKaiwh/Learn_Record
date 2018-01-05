#include <iostream>
#include <list>

using namespace std;

#if 0
template <typename T>
void print(list<T> alist)
{
	list<T>::iterator it;
	
	for (it=alist.begin(); it!=alist.end(); it++)
		cout << *it << " ";
	
	cout << endl;
}
#endif

int main()
{
	list<int> aList(10);
	
	for (int i=0; i<10; i++)
		aList.push_back(i);

	list<int>::iterator it;
	for (it=aList.begin(); it!=aList.end(); it++)
		cout << *it << " ";
	cout << endl;
	
	/*remove一个已知值的成员*/
	aList.remove(0);
	for (it=aList.begin(); it!=aList.end(); it++)
		cout << *it << " ";
	cout << endl;	
	
	/* list反向遍历 */
	list<int>::reverse_iterator rit;
	for (rit=aList.rbegin(); rit!=aList.rend(); ++rit)
	{
		cout << *rit << " ";
	}
	cout << endl;
	
	return 0;
}

/*
wangkai@fiberserver:~/workspace/github/C_plus_plus/stl$ ./a.out 
0 0 0 0 0 0 0 0 0 0 0 1 2 3 4 5 6 7 8 9 
1 2 3 4 5 6 7 8 9 
9 8 7 6 5 4 3 2 1
*/








