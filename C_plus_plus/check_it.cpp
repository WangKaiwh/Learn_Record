// check_it.cpp -- checking for valid input
#include <iostream>

int main()
{
    using namespace std;

	int cnt = 0;
	cout << "enter the length:\n";
	cin >> cnt;

    cout << "Enter numbers: ";
    int sum = 0;
    int input;
	int times = 0;
    while (cin >> input /*&& input != '\n' && input != '\r'*/)
    {
		sum += input;
		if (++times >= cnt)
		{
			break;
		}
    }

    cout << "Last value entered = " << input << endl;
    cout << "Sum = " << sum << endl;

    return 0;
}
