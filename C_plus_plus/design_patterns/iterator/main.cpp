#include <iostream>
#include "aggregate.h"
#include "iter.h"

using namespace std;

int main()
{
	agg *obj = new agg();
	iter *it = new iter(obj);
	
	for (it->first(); !it->end(); it->next())
		cout << "current: #" << it->current() << endl;
	
	delete obj, obj = NULL;
	delete it, it = NULL;

	return 0;
}