#ifndef __FACTORY_H__

//
// 抽象工厂 
class aFactory {
public:
    virtual aProduct* get_product(int type) = 0;	
    virtual ~aFactory();

protected:
    aFactory(); // 抽象类是protected
};

//
// 具体工厂
class factory : public aFactory {
public:
    factory();
	virtual ~factory();
    aProduct* get_product(int type);
};

#endif
