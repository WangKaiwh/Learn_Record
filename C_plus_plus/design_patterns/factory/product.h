#ifndef __PRODUCT__H__

//
// 抽象产品
class aProduct {
public:
     virtual void operation() = 0;		 
     virtual ~aProduct();
protected:
     aProduct(); // 抽象类是protected
};

//
// 具体产品1
class product1 : public aProduct {
public:
	product1();
	~product1();
    void operation();
};

//
// 具体产品2
class product2 : public aProduct {
public:
	product2();
    ~product2();
	void operation();
};

#endif
