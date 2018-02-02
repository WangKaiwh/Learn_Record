// cinexcp.cpp -- having cin throw an exception
#include <iostream>
#include <exception>

int main()
{
    using namespace std;

    // have failbit cause an exception to be thrown
    cin.exceptions(ios_base::failbit);

    cout << "Enter numbers: ";
    int sum = 0;
    int input;

	/*
	   cin >> val，
	   val是什么类型，则输入的就是什么类型
	*/
	try {
		while (cin >> input) { // ctrl+c会触发
			cout << "input: " << input << endl;
			sum += input;
		}
	}
	catch (ios_base::failure &fail) {
		cout << fail.what() << endl;
		cout << "oops!" << endl;
	}

	cout << "Last value entered = " << input << endl;
	cout << "Sum = " << sum << endl;

    return 0;
}
