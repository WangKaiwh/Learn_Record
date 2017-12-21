
#include <iostream>

using namespace std;

double div(double a, double b)
{
	if (0 == b)
		throw 5;
	return a / b;
}

int main()
{
	cout << "Please input two number." << endl;
	double a, b;
	
	cin >> a >> b;
	
	try {
		cout << "try to div two numbers." << endl;
		cout << a  << " / " << b << " = " << div(a, b) << endl;
	}
	catch (int excep) { // 异常的类型
		cout << "exception: div 0 ! exception catch: " << excep << endl;
	}
	
	return 0;
}
