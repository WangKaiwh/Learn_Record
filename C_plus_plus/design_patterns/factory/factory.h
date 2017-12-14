#ifndef __FACTORY_H__

class aFactory {
public:
    aFactory();
    virtual ~aFactory();

protected:
    virtual aProduct* get_product(int type) = 0;
};

class factory : public aFactory {
public:
    factory();
	virtual ~factory();
    aProduct* get_product(int type);
};

#endif
