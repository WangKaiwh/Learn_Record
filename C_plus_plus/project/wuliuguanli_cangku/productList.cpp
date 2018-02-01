#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "productList.h"

using namespace std;

ProductList* ProductList::s_pProductHead = nullptr;
ProductList* ProductList::s_pProductTail = nullptr;

void ProductList::DeleteProductList(ProductList*& p)
{
	auto pTmp = p, pList = p;
	auto& pHead = p;
	while (pTmp && pTmp->m_pProductNext)
	{
		pTmp = pTmp->m_pProductNext;
		if (pList == s_pProductHead)
			delete p->m_product;
		delete p;
		p = pTmp;
	}
	delete pTmp;
	pHead = nullptr;
}

const Product* ProductList::GetProduct(ProductList*& p)
{
	if (!p->m_product)
		return nullptr;

	const auto ptr = p->m_product;
	p = p->m_pProductNext;
	return ptr;
}

bool ProductList::IsSame(const Product* pro1, const Product& pro2)
{
	if (pro1->sSerial == pro2.sSerial
		&& pro1->sName == pro2.sName
		&& pro1->sBrand == pro2.sBrand)
		return true;

	return false;
}

ProductList::ProductList() :m_product(nullptr), m_pProductNext(nullptr)
{
	//s_pProducHead��s_pProductTail������̬���ݳ�Ա�ǲ�Ʒ��Ϣ�����ͷָ�롢βָ��
	//����մ���ʱ��ֻ����һ���ڵ㣬������Ч��ͷβָ���ָ��ýڵ�
	if (!(s_pProductHead || s_pProductTail))
	{
		s_pProductHead = this;
		s_pProductTail = this;
	}
}


ProductList::~ProductList()
{
	//cout << "productlist destructor!" << endl;
	//s_pProductTail = nullptr;
}

void ProductList::Swap(ProductList* ptr1, ProductList* ptr2)
{
	Product *tmp;
	tmp = ptr1->m_product;
	ptr1->m_product = ptr2->m_product;
	ptr2->m_product = tmp;
}

int ProductList::CompareByEType(EType t, const ProductList* ptr1, const ProductList* ptr2)
{
	switch (t)
	{
	case TYPE_SERIAL:
		COMPARE_BY(ptr1, ptr2, sSerial);
	case TYPE_NAME:
		COMPARE_BY(ptr1, ptr2, sName);
	case TYPE_BRAND:
		COMPARE_BY(ptr1, ptr2, sBrand);
	case TYPE_PRICE:
		COMPARE_BY(ptr1, ptr2, iPrice);
	case TYPE_COUNT:
		COMPARE_BY(ptr1, ptr2, iCount);
	}
	return 0;
}

ProductList* ProductList::IsSameProduct(const Product& pro) const
{
	auto p = s_pProductHead;

	while (p->m_product)
	{
		if (IsSame(p->m_product, pro))
			return p;
		p = p->m_pProductNext;
	}

	return nullptr;
}

ProductList* ProductList::GetFrontProduct(const ProductList* product)
{
	if (!product)
	{
		cout << "Invalid param: product == nullptr!\n";
		return nullptr;
	}

	auto pThis = s_pProductHead;
	while (pThis->m_pProductNext)
	{
		if (pThis->m_pProductNext->m_product == product->m_product)
			break;
		pThis = pThis->m_pProductNext;
	}

	if (!pThis->m_pProductNext)
		return nullptr;
	return pThis;
}

ProductList* ProductList::IsProductExist(const ProductList* product, int num)
{
	if (!product)
	{
		cout << "Invalid param: product == nullptr!\n";
		return nullptr;
	}

	if (num < 1)
	{
		cout << "Invalid count: num == " << num << ", num < 1\n";
		return nullptr;
	}

	auto pThis = s_pProductHead;
	while (pThis)
	{
		if (pThis->m_product == product->m_product)
			break;
		pThis = pThis->m_pProductNext;
	}

	return pThis;
}

//��������Ϊ������Ĳ�Ʒ�����ַ��ptrֵ�����֣�
//1������Ʒ��Ϣ��product.txt�ļ���ã���ptrΪ��nullptrֵ
//2������Ʒ��Ϣ��Ҫ�û����룬ptrֵΪnullptr
void ProductList::AddProduct(const Product* ptr)
{
	Product pro;
	if (!ptr){                              //ptrΪnullptrʱ����Ҫ�û������Ʒ��Ϣ
		cout << "�밴���¸�ʽ�����Ʒ��Ϣ��\n";
		OUTPUT_HEAD(cout);
		INPUT_PRODUCT(cin, pro);        //�Ӽ��̻�ȡ��Ʒ��Ϣ������pro��
	}
	else{
		pro = *ptr;                       //������ڵ����Ч���ݴ���pro��
	}
	//������ڵ�Ĳ�Ʒ�ͺš����ơ�Ʒ��ͬ�������нڵ���бȽ�
	//������������ͬ�Ľڵ㣬��p��¼����ڵ��ַ������pΪnullptr
	auto p = IsSameProduct(pro);
	if (p)
	{
		cout << "������Ĳ�Ʒ������ϵͳ���Ѵ��ڣ��ֽ���Ϣ���кϲ���" << endl;
		cout << "\nԭ����Ϣ���£�" << endl;
		OUTPUT_HEAD(cout);
		OUTPUT_PRODUCT(cout, p->m_product);
		//�������д��������ڵ���Ϣ��ͬ�ڵ㣬������ڵ�ļ۸���������������ڵ���Ӧ���ݺϲ�
		int total = p->m_product->iPrice * p->m_product->iCount + pro.iPrice * pro.iCount;
		p->m_product->iCount += pro.iCount;
		p->m_product->iPrice = total / p->m_product->iCount;

		cout << "�ϲ�����Ϣ���£�" << endl;
		OUTPUT_PRODUCT(cout, p->m_product);
		cout << endl;
		return;
	}
	
	//�������Ѵ��ڣ�������β�������½ڵ�
	if (s_pProductTail)
	{
		//��βָ���m_product�����²�Ʒ�����ַ
		s_pProductTail->m_product = new Product(pro);
		//�����µ�β�ڵ�
		s_pProductTail->m_pProductNext = new ProductList();
		//βָ��ָ���´�����β�ڵ�
		s_pProductTail = s_pProductTail->m_pProductNext;
	}
	else
	{
		std::cout << "����β��Ϊnullptr!\n";
	}
}


//��������product�ڵ�����num���½ڵ�
void ProductList::InsertProduct(const ProductList* product, int num)
{
	//��������Ѱ�Ҳ���λ�ã�����productΪ��Ʒ�ͺ�ֵ���ڡ�PRO001���Ľڵ�ָ��
	//�򱾺������ڸýڵ�����num���½ڵ㡣 pThisָ���¼����λ��
	ProductList* pThis = IsProductExist(product, num);
	if (!pThis)                             //������λ�ò����ڣ����������
		return;

	int i = 0;
	Product pro;
	//pThis�󽫲����½ڵ㣬pNext��¼��ǰpThis�ĺ�̽ڵ�
	auto pNext = pThis->m_pProductNext;
	while (i++ < num)                     //����num���½ڵ�
	{
		cout << "�����²�Ʒ���ݣ�" << endl;
		OUTPUT_HEAD(cout);
		INPUT_PRODUCT(cin, pro);
		//������Ĳ�Ʒ�ͺš����ơ�Ʒ����������ĳ�ڵ���ͬ������Ϊ��ͬһ����Ʒ��ֻ�޸Ĳ�Ʒ����
		auto p = IsSameProduct(pro);
		if (p)
		{
			p->m_product->iCount += pro.iCount;
			continue;
		}
		//��������²�Ʒ��Ϣ�������½ڵ㣬������ʵ�λ��
		pThis->m_pProductNext = new ProductList();
		pThis = pThis->m_pProductNext;
		pThis->m_product = new Product(pro);
		pThis->m_pProductNext = pNext;
	}
	return;
}



void ProductList::SellProduct(const ProductList* product, int num)
{
	//��������Ѱ�Ҵ������Ĳ�Ʒ�ڵ㣬���ҽ����¼��p��
	auto p = IsProductExist(product, ESelect::SELECT_FIRST);
	//��pΪ��nullptr�����ҵ�Ҫ�����Ĳ�Ʒ�ڵ�
	if (p)
	{
		//��ʾҪ�����Ĳ�Ʒ��Ϣ
		cout << "Ҫ�����Ĳ�Ʒ��Ϣ��" << endl;
		OUTPUT_HEAD(cout);
		OUTPUT_PRODUCT(cout, p->m_product);
		//���ݳ������������ٽڵ�����Ӧ�Ĳ�Ʒ����ֵ
		p->m_product->iCount -= num;
		//�����������ڵ��ڿ��������ɾ�������ж�Ӧ�ڵ�
		if (p->m_product->iCount <= 0){
			cout << "**********������Ϊ��" << p->m_product->iCount + num
				<< ", �û����ѳ��壡**********" << endl;
			DeleteProduct(p);
		}
	}
}


//����productָ����ɾ�ڵ�
//nummĬ��ֵΪSELECT_FIRST��1������ʾɾ��������ƥ��ĵ�һ���ڵ㣬����ǰ�ڵ�
void ProductList::DeleteProduct(const ProductList* product, int num)
{
	int i = 0;
	auto p = product;
	ProductList* pThis;
	ProductList* pNext;
	ProductList* pFront;
	//����ɾ�ڵ���������׽ڵ㣬�������׽ڵ㣬���޸�s_pProductHead
	if (product == s_pProductHead){
		delete product->m_product;
		s_pProductHead = s_pProductHead->m_pProductNext;
		delete product;
		return;
	}
	while (i++ < num)
	{
		if (!p->m_product)
		{
			cout << "Warning: param product == nullptr!\n";
			return;
		}
		//Ѱ�Ҵ�ɾ�ڵ��ǰ��
		pFront = GetFrontProduct(p);
		//ȷ����ɾ�ڵ�
		pThis = IsProductExist(p, num);
		if (!pThis)
		{
			cout << "Warning: param pThis == nullptr!\n";
			return;
		}
		//����ɾ�ڵ��ǰ���ͺ��������ɾ��ָ���ڵ�
		p = p->m_pProductNext;
		pNext = pThis->m_pProductNext;
		delete pThis->m_product;
		delete pThis;
		if (pFront)
			pFront->m_pProductNext = pThis = pNext;
	}
	return;
}


//����˵����
//EType t:��ʾ��Ʒ���Ա�ţ����磬���밴�ղ�Ʒ�ͺŽ��в�ѯ����tΪ0�������Ʋ飬tΪ1
//ECondition c:��ʾ��ѯ���������磬����ѯ����Ϊ����ȡ�����cΪ1
//std::string str����ʾ����Ĳ�Ʒ����ֵ
//��tΪ0�� cΪ1�� strΪPRO001ʱ����ʾ��ѯ��Ʒ�ͺŵ��ڡ�PRO001���Ľڵ���Ϣ
ProductList* ProductList::SearchProduct(EType t, ECondition c, std::string str) const
{
	int val;
	ECondition res;
	const char* s = str.c_str();
	auto p = s_pProductHead;            //��p��¼����ѯ������ͷָ��
	//pListΪ��ѯ��������ͷ�ڵ��ַ
	//���Ӳ�Ʒ��Ϣ�����в��ҵ����������Ľڵ㣬�����β���pListָ���������
	auto pList = new ProductList();
	auto pHead = pList;
	sscanf(s, "%d", &val);
	//���Ҳ�Ʒ��Ϣ����
	while (p->m_product)
	{
		//ȷ����������
		switch (t)
		{
		case TYPE_SERIAL:
			//����Ʒ�ͺŽ��в�ѯ����res�м�¼��ѯ�Ƚ�����
			//����ǰ�ڵ��еĲ�Ʒ�ͺ�ֵС��strָ���Ĳ�ѯֵ���ѯ����res���趨ΪON_LESS
			//�������res���趨ΪON_EQUAL����������res������ΪON_GREATER
			COMPARE_WITH(p, sSerial, str, res);
			break;
		case TYPE_NAME:
			COMPARE_WITH(p, sName, str, res);
			break;
		case TYPE_BRAND:
			COMPARE_WITH(p, sBrand, str, res);
			break;
		case TYPE_PRICE:
			COMPARE_WITH(p, iPrice, val, res);
			break;
		case TYPE_COUNT:
			COMPARE_WITH(p, iCount, val, res);
			break;
		}
		//�Ƚϲ�ѯ�����뱾�ڵ��Ʒ����ֵ�Ĺ�ϵ����ƥ��˵����ѯ�ɹ�
		//����ѯ���Ĳ�Ʒ��Ϣ����pListָ���������
		if (c == res)
		{
			pList->m_product = p->m_product;
			pList->m_pProductNext = new ProductList();
			pList = pList->m_pProductNext;
		}
		p = p->m_pProductNext;
	}
	//�����ҵ���Ч��Ϣ�򷵻ز�ѯ�������ͷָ�룬���򷵻�nullptr
	return pHead->m_product ? pHead : nullptr;
}



void ProductList::ShowAllProduct(ProductList *head) const
{
	OUTPUT_HEAD(cout);                                //��ʾ��Ʒ��������
	auto p = head;
	//ѭ����������ڵ㣬�����Ϣ��ʾ
	while (p->m_product)
	{
		OUTPUT_PRODUCT(cout, p->m_product);
		p = p->m_pProductNext;
	}
}



//��ָ���������������������
void ProductList::SortProductByEType(EType type)
{
	auto p = s_pProductHead;                   //��p��¼ͷ�ڵ��ַ
	//������ֻ��һ���ڵ㣬ֱ����ʾ�ýڵ���Ϣ,��������
	if (!p->m_pProductNext)
	{
		ShowAllProduct();
		return;
	}

	ProductList* pTmp;
	//����ѡ������˼�룬������ڵ������������
	for (auto i = p; i->m_pProductNext->m_product;)
	{
		//i�ڵ�λ��Ϊ��������ǰλ�ã���ǰλ��Ӧ�ô������ֵ��С�Ľڵ���Ϣ
		pTmp = i;
		//��i�ڵ�֮��Ľڵ���Ѱ������ֵ��С�Ľڵ㣬�����ڵ��ַ��¼��pTmpָ����
		auto j = i->m_pProductNext;
		while (j->m_product)
		{
			if (CompareByEType(type, pTmp, j) > 0)
				pTmp = j;
			j = j->m_pProductNext;
		}

		//������ֵ��С�Ľڵ㣨��pTmpָ��û�г�����������ǰλ��i�ϣ��򽻻���Ʒ��Ϣ
		if (pTmp != i)
			Swap(i, pTmp);
		
		i = i->m_pProductNext;
	}
}

//����Ϊһ������ͷָ�룬���������������޸����������в�Ʒ�� numʼ��Ϊ�棬��ʾ�޸ĸýڵ���Ϣ
void ProductList::EditProduct(const ProductList* product, int num)
{
	Product pro;
	auto p = product;
	ProductList *pSame;
	ProductList* pThis;
	//ͨ��ѭ��������ÿ����Ҫ�����޸ĵĽڵ�
	while (p->m_product)
	{
		//�жϲ�Ʒ��Ϣ�������Ƿ���ڴ��޸ĵĽڵ���Ϣ��������������޸�
		pThis = IsProductExist(p, ProductList::ESelect::SELECT_FIRST);
		if (pThis)
		{
			//�޸�ǰ����ʾĿǰ��Ϣ
			cout << "����Ʒԭ����Ϣ���£�\n";
			OUTPUT_PRODUCT(cout, pThis->m_product);
			//��������Ϣ
			cout << "�������޸ĺ����Ϣ��\n";
			INPUT_PRODUCT(cin, pro);
			//�����в�Ʒ��Ϣ�����в������������Ϣ�Ƿ����
			pSame = IsSameProduct(pro);
			//�޸ı��ڵ㣬���������������Ϣ���Ʒ��Ϣ������������Ϣ������ͬ��
			//������Ϣ���Ƶ����޸Ľڵ��С�
			if (!pSame || pSame->m_product == p->m_product){
				COPY_PRODUCT(pThis->m_product, pro);
			}
			//�����������Ϣ�������г����ڵ����ĳ���ڵ���ͬ����ɾ�����ڵ㣬
			//��������Ϣ��ԭ����Ϣ�ϲ�
			else
			{
				DeleteProduct(pThis);
				pSame->m_product->iCount += pro.iCount;
			}
			cout << "�޸ĳɹ����밴�س��������޸ġ�\n";
			cin.get();
			cin.get();
		}
		else
			break;
		p = p->m_pProductNext;
	}
	cout << "�޸���ϣ�\n";
}


void ProductList::ShowProduct(const ProductList* product, int num)
{
	OUTPUT_HEAD(cout);

	int i = 0;
	auto p = product;
	auto pThis = s_pProductHead;
	while (i++ < num)
	{
		pThis = IsProductExist(p, num);
		if (pThis)
			OUTPUT_PRODUCT(cout, pThis->m_product);
		p = p->m_pProductNext;
	}
}
ProductList *ProductList::GetListHead()
{
	return s_pProductHead;
}