#include <iostream>

using namespace std;

//
// class definition
class Singleton {
public:
    static Singleton* get_instance();
    int get_val();
    void set_val(int n);

private:
    Singleton();
    ~Singleton();
    static Singleton *instance;
    int val;
};


// 
// class implement
Singleton *Singleton::instance = NULL;

Singleton * Singleton::get_instance()
{
    if (instance == NULL) {
        instance = new Singleton();
    }

    return instance;
}

int Singleton::get_val()
{
    return val;
}

void Singleton::set_val(int n)
{
    val = n;
}

Singleton::Singleton()
{
    val = 100;
    cout << "constructor called" << endl;
}

Singleton::~Singleton()
{
    delete instance;
}

//
// Main entrance
int main()
{
    Singleton *p = Singleton::get_instance();
    cout << "get_instance" << endl;
    cout << p->get_val()<< endl;

    p->set_val(120);
    cout << p->get_val() << endl;

    return 0;
}






