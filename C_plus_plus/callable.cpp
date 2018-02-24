// callable.cpp -- callable types and templates
#include <iostream>
#include <math.h>
using namespace std;

template <typename T, typename F>
T use_f(T v, F f)
{
    static int count = 0;
    count++;
    cout << "  use_f count = " << count << ", &count = " << &count << endl;
    return f(v);
}

class Fp
{
private:
    double z_;
public:
    Fp(double z = 1.0) : z_(z) { cout << "Fp constructor." << endl; }
    double operator()(double p) { return z_*p; }
};
 class Fq
{
private:
    double z_;
public:
    Fq(double z = 1.0) : z_(z) { cout << "Fq constructor." << endl; }
    double operator()(double q) { return z_+ q; }
};

double dub(double x) {return 2.0*x;}

// 用C11编译：std=c++11

// 代码环境判断的宏
// linux环境：__linux__
// windows环境：_WIN32 || _WIN64

int main()
{
    double y = 1.21;

    #ifdef __linux__
	system("clear");
    #elif defined(__WIN32 || __WIN64)
	system("cls");
    #endif
    
    cout << "Function pointer dub:\n";
    cout << "  " << use_f(y, dub) << endl;
    cout << "Function pointer sqrt:\n";
    cout << "  " << use_f(y, sqrt) << endl;
    cout << "Function object Fp:\n";
    cout << "  " << use_f(y, Fp(5.0)) << endl;
    cout << "Function object Fq:\n";
    cout << "  " << use_f(y, Fq(5.0)) << endl;
    cout << "Lambda expression 1:\n";
    cout << "  " << use_f(y, [](double u) {return u*u;}) << endl;
    cout << "Lambda expresson 2:\n";
    cout << "  " << use_f(y, [](double u) {return u+u/2.0;}) << endl;
  
    cin.get();
    return 0;
}
