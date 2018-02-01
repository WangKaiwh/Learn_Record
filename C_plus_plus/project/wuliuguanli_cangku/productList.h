#pragma once

#include "product.h"

// ��Ʒ�б�
class ProductList{
public:
	enum ESelect                        //����ö�����ͣ�˵����������ķ�ʽ
	{
		SELECT_ALL = -1,			 // ȫѡ����ʾ����������нڵ���в���
		SELECT_FIRST = 1,			 // ��ѡ�����������ĵ�һ���ڵ���в���
	};
	enum ECondition                    //����ϵͳ�еĲ�ѯҪ�󣬽�ʹ�ñ�ö������Ϊ��ѯ����
	{
		ON_NONE = 0,
		ON_EQUAL = 0x01,           //������ͬ����
		ON_LESS = 0x02,           //����С������ֵ������
		ON_GREATER = 0x03            //���Ҵ�������ֵ������
	};
private:
	Product* m_product;							// Productָ�룬ָ���Ʒ��Ϣ
	ProductList* m_pProductNext;				// ָ���̽ڵ�
private:
	static ProductList* s_pProductHead;			// ��̬���ݳ�Ա������ͷָ��
	static ProductList* s_pProductTail;			// ��̬���ݳ�Ա������βָ��
public:
	static void DeleteProductList(ProductList*& p);//ɾ������
	static const Product* GetProduct(ProductList*& p);//��ȡ��Ʒ��Ϣ
	static bool IsSame(const Product* pro1, const Product& pro2);//�Ƚ�������Ʒ
	static ProductList *GetListHead();//��ȡ����ͷָ��
public:
	ProductList();								// ���캯��
	~ProductList();								// ��������
private:
	// �ڲ��ӿ�
	void Swap(ProductList* ptr1, ProductList* ptr2); //�����ڵ��еĲ�Ʒ��Ϣ
	//��������ɲ�Ʒ��Ϣ�Ƚ�
	int CompareByEType(EType t, const ProductList* ptr1, const ProductList* ptr2);
	//�ж�ָ����Ʒ��Ϣ�Ƿ������������
	ProductList* IsSameProduct(const Product& pro) const;
	//��ȡ��ǰ�ڵ��ǰ��
	ProductList* GetFrontProduct(const ProductList* product);
	//�ж�ָ����Ʒ��Ϣ���������Ƿ����
	ProductList* IsProductExist(const ProductList* product, int num);
public:
	void AddProduct(const Product* ptr = nullptr);	// ��Ӳ�Ʒ
	// ��ָ����Ʒ������²�Ʒ��Ϣ
	void InsertProduct(const ProductList* product, int num = SELECT_FIRST);
	// ����
	void SellProduct(const ProductList* product, int num = SELECT_FIRST);
	// ɾ����Ʒ��Ϣԭʼ�б���ĳ��Ʒ��Ϣ
	void DeleteProduct(const ProductList* product, int num = SELECT_FIRST);
	// ��ѯ��Ʒ
	ProductList* SearchProduct(EType t, ECondition c, std::string str) const;
	void ShowAllProduct(ProductList *head = s_pProductHead) const;	// ��ʾ���в�Ʒ
	// ������ʾ
	void SortProductByEType(EType type);
	// �༭ָ����Ʒ����Ϣ
	void EditProduct(const ProductList* product, int num = SELECT_FIRST);
	// ��ʾָ����Ʒ����Ϣ
	void ShowProduct(const ProductList* product, int num = SELECT_FIRST);
};






#pragma region

#define COMPARE_BY(ptr1, ptr2, member) \
do \
{ \
if (ptr1->m_product->member < ptr2->m_product->member) \
	return -1; \
	else if (ptr1->m_product->member == ptr2->m_product->member) \
	return 0; \
	else \
	return 1; \
} \
while (0)

#define COMPARE_WITH(ptr, member, val, res) \
do \
{ \
if (ptr->m_product->member < val) \
	res = ECondition::ON_LESS; \
	else if (ptr->m_product->member == val) \
	res = ECondition::ON_EQUAL; \
	else \
	res = ECondition::ON_GREATER; \
} \
while (0)

#define OUTPUT_HEAD(out) \
do \
{ \
	out << "�ͺ�" << "\t\t" \
	<< "����" << "\t\t" \
	<< "Ʒ��" << "\t\t" \
	<< "����" << "\t\t" \
	<< "����" << endl; \
	out << "--------------------------------------------------------------------" << endl;\
} \
while (0)

#define INPUT_PRODUCT(in, pro) \
in >> pro.sSerial \
	>> pro.sName \
	>> pro.sBrand \
	>> pro.iPrice \
	>> pro.iCount

#define OUTPUT_PRODUCT(out, ptr) \
out << ptr->sSerial << "\t\t" \
	<< ptr->sName << "\t" \
	<< ptr->sBrand << "\t\t" \
	<< ptr->iPrice << "\t\t" \
	<< ptr->iCount << endl

#define COPY_PRODUCT(ptr, pro) \
do \
{ \
	ptr->sSerial = pro.sSerial; \
	ptr->sName = pro.sName; \
	ptr->sBrand = pro.sBrand; \
	ptr->iPrice = pro.iPrice; \
	ptr->iCount = pro.iCount; \
} while (0)

#pragma endregion
