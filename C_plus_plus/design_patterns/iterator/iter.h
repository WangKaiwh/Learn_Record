#ifndef __ITER_H__

//
// 定义迭代器接口
class iterInterface {
public:
	virtual ~iterInterface();
	virtual int first() = 0;
	virtual void next() = 0;
	virtual bool end() = 0;
	virtual int current() = 0;
protected:
	iterInterface();
};

//
// 定义迭代器实体类
class iter : public iterInterface {
public:	
	iter(agg *obj, int index = 0);
	virtual ~iter();
	int first();
	void next();
	bool end();
	int current();
private:
	int m_index;
	agg *m_obj;
};

#endif