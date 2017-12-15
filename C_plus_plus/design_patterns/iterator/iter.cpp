#include <iostream>
#include "aggregate.h"
#include "iter.h"

using namespace std;

//
// 迭代器接口构造析构函数
iterInterface::iterInterface() {}
iterInterface::~iterInterface() {}

// 
// 迭代器实体实现
iter::iter(agg *obj, int index) 
{
	m_obj = obj;
	m_index = index;
}

iter::~iter() {}

int iter::first() 
{
	m_index = 0;
}

void iter::next()
{
	m_index++;
}

bool iter::end()
{
	if (NULL != m_obj)
		return m_index == m_obj->get_size();
	else { // 异常则直接认定end状态为true
		cout << "m_obj null" << endl; 
		return true;
	}
}

int iter::current()
{
	if (NULL != m_obj)
		return m_obj->get_item(m_index);
	else {
		cout << "m_obj null" << endl;
		return -1;
	}
}


