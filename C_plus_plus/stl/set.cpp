#include <iostream>
#include <set>

using namespace std;

// 标准set的用法
// set<Key, Compare, Alloc>

int main()
{
	// 定义set s, -std=c++11 可以编译 <, <>>
	set<int, greater<int>> s; // 此set中的值降序排列
	
	cout << "s能够容纳的最大元素为: " << s.max_size() << endl;
	
	pair<set<int>::iterator, bool> p;
	
	p = s.insert(8);	
	if (true == p.second) /* pair p second在植入成功后，自动设置为true */
	{
		cout << "insert successfully." << endl;
		cout << "p.second: " << p.second << endl;
	}
	
	s.insert(11);
	s.insert(3);
	s.insert(11); // 插入值无效，set中只保存一个值。multiset可以允许有相同的值。
	
	set<int>::iterator its;
	cout << "开始遍历set s中的值" << endl;
	for (its = s.begin(); its != s.end(); ++its)
	{
		cout << *its << " ";
	}
	cout << endl;
	
	set<char> schar; // 此set中的值升序排列
	schar.insert('z');
	schar.insert('a');
	schar.insert('t');
	schar.insert('w');
	
	set<char>::iterator itsc;
	for (itsc  = schar.begin();
		 itsc != schar.end();
		 itsc++)
	{
		cout << *itsc << " ";
	}
	cout << endl;
	
	return 0;
}