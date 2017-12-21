
#include <iostream>

using namespace std;

int main()
{
	cout << "Please input two number." << endl;
	double a, b;
	
	cin >> a >> b;
	
	try {
		if (0 == b)
			throw 0;
		
		cout << a  << " / " << b << " = " << a / b << endl;
	}
	catch (int) {
		cout << "exception: div 0 !" << endl;
	}
	
	return 0;
}