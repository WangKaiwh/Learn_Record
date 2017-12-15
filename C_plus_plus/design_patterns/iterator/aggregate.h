#ifndef __AGGREGATE_H__

//
// 定义聚合类接口
class aggInterface {
public:
	virtual ~aggInterface();
	virtual int get_size() = 0;
	virtual int get_item(int index) = 0;

protected:
	aggInterface(); 
};

//
// 定义聚合类实体
class agg {
public:
	agg();
	~agg();
	int get_size();
	int get_item(int index);
private:	
	enum {SIZE = 100};
	int m_item[SIZE];	
};

#endif