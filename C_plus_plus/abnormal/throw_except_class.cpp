
#include <iostream>

using namespace std;

//
// 定义异常类
class ZeroException {
public:
	ZeroException() : m_msg("div 0.") {};
	string getmsg()
	{
		return m_msg;
	}
private:
	string m_msg;
};

//
// 带异常处理的除法函数
double div(double a, double b)
{
	if (0 == b)
		throw ZeroException();
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
	catch (ZeroException ex) { // 异常的类型
		cout << ex.getmsg() << endl;
	}
	
	return 0;
}
