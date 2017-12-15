#include <iostream>
#include "aggregate.h"

using namespace std;

//
// 接口构造析构函数实现
aggInterface::aggInterface() {cout << "aggInterface 构造" << endl;}
aggInterface::~aggInterface() {cout << "aggInterface 析构" << endl;}

//
// 实际聚合类实现
agg::agg() 
{
	for (int i=0; i<SIZE; i++)
		m_item[i] = i * 2;
	
	cout << "agg 构造" << endl;
}

agg::~agg() {cout << "agg 析构" << endl;}

int agg::get_size()
{
	return SIZE;
}

int agg::get_item(int index)
{
	if (index >= 0 && index <SIZE)
		return m_item[index];
	else {
		cout << "index out of range!" << endl;
		return -1;
	}
}

