
#include <iostream>
#include <stdexcept>

using namespace std;

double div(double a, double b)
{
	if (0 == b)
		throw invalid_argument("div b == zero");
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
	catch (exception &exp) { // 异常的类型
		cout << "exception: " << exp.what() << endl;
	}
	
	return 0;
}
