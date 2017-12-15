#include <iostream>
#include "proxy.h"

int main()
{
	concreteSubject *Mr_s = new concreteSubject();
	
	proxy *Mr_W = new proxy(Mr_s);
	Mr_W->request();
	
	delete Mr_W;
	// 故意找茬的..
	Mr_W = new proxy(NULL);
	Mr_W->request();
	
	delete Mr_s;
	Mr_s = NULL;	
	delete Mr_W;
	Mr_W = NULL;
	
	return 0;
}