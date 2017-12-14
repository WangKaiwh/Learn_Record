#ifndef __PRODUCT__H__

class aProduct {
public:
     aProduct();
     virtual ~aProduct();
//protected:
     virtual void operation() = 0;	
};

class product1 : public aProduct {
public:
     void operation();
};

class product2 : public aProduct {
public:
     void operation();
};

#endif
