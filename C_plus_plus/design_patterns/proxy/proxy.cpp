#include <iostream>
#include "proxy.h"

using namespace std;

//
// 基本主体定义
subject::subject() {}
subject::~subject() {}

//
// 实体定义
concreteSubject::concreteSubject() {}
concreteSubject::~concreteSubject() {}

void concreteSubject::request()
{
    cout << "[concrete]I really request U" << endl;				
}

//
// 野中介来了
proxy::proxy() {}
proxy::~proxy() {}

proxy::proxy(subject *sub)
{
	if (NULL == sub) { // 不给钱，就想让中介做事？
		cout << "[proxy]Are you kiding?? sub == NULL" << endl;
		//return;
	}
	m_sub = sub;
}

void proxy::request()
{
	if (NULL != m_sub) {
		cout << "[proxy]Help my God to request." << endl;
		m_sub->request();
	} else { // 不给钱，中介不做事
		cout << "[proxy]no money no talk!" << endl;
	}
}

