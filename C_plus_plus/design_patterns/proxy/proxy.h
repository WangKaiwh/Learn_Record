#ifndef __PROXY_H__

//
// 基本主体
// 纯虚函数，仅仅作为接口使用
class subject {
public:
	virtual ~subject();
	virtual void request() = 0;
protected:
	subject();
};

//
// 真实实体
class concreteSubject : public subject {
public:
	concreteSubject();
	~concreteSubject();
	void request();
};

//
// 小中介 野中介？
class proxy : public subject {
public:
	proxy();
	proxy(subject *sub);
	~proxy();
	void request();
private:
	subject *m_sub;
};

#endif
