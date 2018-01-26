// lambda1.cpp -- use captured variables
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>

const long Size = 390000L;

template <class _f>
	void callf(_f func)
	{
	func();
	}

int main()
{
    using std::cout;
    std::vector<int> numbers(Size);

    std::srand(std::time(0));
    std::generate(numbers.begin(), numbers.end(), std::rand);
	cout << "Sample size = " << Size << '\n';

// using lambdas
    int count3 = std::count_if(numbers.begin(), numbers.end(), 
		      [](int x){return x % 3 == 0;});
    cout << "Count of numbers divisible by 3: " << count3 << '\n';
    int count13 = 0;
    std::for_each(numbers.begin(), numbers.end(),
         [&count13](int x){count13 += x % 13 == 0;});
    cout << "Count of numbers divisible by 13: " << count13 << '\n';

// using a single lambda
    count3 = count13 = 0;
    std::for_each(numbers.begin(), numbers.end(),
         [&](int x){count3 += x % 3 == 0; count13 += x % 13 == 0;});
    cout << "Count of numbers divisible by 3: " << count3 << '\n';
    cout << "Count of numbers divisible by 13: " << count13 << '\n';

	callf( [](){ cout << "lamda called!\n" << '\n'; } );


// Kevin添加lamda改变函数外的方法。
	int what = 0;
	callf([&what](){ what = 100;  });
	cout << "after callf, what: " << what << '\n';

	int when = 0;
	what = 0;
// lamda函数，改变两个或以上函数外的值，用[&]。
	callf([&](){ what = when = 200;  });
	cout << "after callf, what: " << what << ", when: " 
			<< when << '\n';

    // std::cin.get();
    return 0;
}