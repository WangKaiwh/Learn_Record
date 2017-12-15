#include <iostream>
#include "aggregate.h"

using namespace std;

//
// 接口构造析构函数实现
aggInterface::aggInterface() {}
aggInterface::~aggInterface() {}

//
// 实际聚合类实现
agg::agg() 
{
	for (int i=0; i<SIZE; i++)
		m_item[i] = i * 2;
}

agg::~agg() {}

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

