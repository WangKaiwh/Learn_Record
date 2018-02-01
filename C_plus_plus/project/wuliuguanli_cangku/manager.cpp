#include "manager.h"
#include "productList.h"
#include <iostream>

using namespace std;

Manager::Manager(std::string fileName, std::string logFile)
: m_strRecordFile(fileName)//��ʼ��Ϊ��Ų�Ʒ��Ϣ���ļ�����product.txt
, m_strLogFileName(logFile)//��ʼ��Ϊ��־�ļ�����info.log
, m_productHead(new ProductList())//��ʼ��ΪProductList�����ַ
{
	// ����־�ļ�
	m_foutLogFile.open(m_strLogFileName, ios_base::out | ios_base::app);
	m_foutLogFile.clear();
	m_foutLogFile.seekp(0, ios_base::beg);
	Logout("�ɹ�����־�ļ�����ʼӪҵ");               //����־�ļ�������Ӧ������Ϣ
	system("pause");
	system("cls");
}


Manager::~Manager()
{
	m_foutLogFile.close();
	cout << "manager destructor!" << endl;
	
	ProductList::DeleteProductList(m_productHead);
	system("pause");
}


void Manager::ReadRecord()
{
	// �򿪲������Ʒ��Ϣ��¼�ļ���product.txt��
	m_finRecord.open(m_strRecordFile, ios_base::in);
	m_finRecord.clear();
	m_finRecord.seekg(0, ios_base::beg);

	//����־�ļ��м�¼�û�ִ�еĲ���
	OUTPUT_HEAD(m_foutLogFile);
	Product pro;
	//��ȡ��Ʒ��Ϣ�ļ�����ÿ����¼��Ϊ�ڵ㣬��������
	while (INPUT_PRODUCT(m_finRecord, pro))
		m_productHead->AddProduct(&pro);         //�������в����½ڵ�
	m_finRecord.close();                            //�رղ�Ʒ��Ϣ�ļ�
}


void Manager::UpdateRecord()
{
	auto str = m_strRecordFile + ".bak";//����һ������Ϊ��product.txt.bak�����ַ���
	BackupRecord(str);                      //����Ϊ��product.txt.bak�����ļ�����������Ϣ
	remove(m_strRecordFile.c_str());     //ɾ��ԭ�е�product.txt�ļ�
	//��product.txt.bak����Ϊproduct.txt
	rename(str.c_str(), m_strRecordFile.c_str());
}


//��������ָ���ļ�����
void Manager::BackupRecord(std::string file)
{
	Logout("���ڴ�������");              //����־�ļ��м�¼�û�����
	ofstream fout(file);
	auto p = m_productHead;           //p��������ͷָ��
	auto ptr = ProductList::GetProduct(p);//��ȡ�����׽ڵ�
	while (ptr)
	{
		OUTPUT_PRODUCT(fout, ptr);//���ڵ��Ӧ�Ĳ�Ʒ��Ϣ�����ļ�
		ptr = ProductList::GetProduct(p);//��ȡ��һ���ڵ�
	}
	fout.close();                      //�ر��ļ�
	Logout("���������ɹ�");
	system("pause");
}


void Manager::LogoutInfo()
{
	cout << __DATE__ << ", " << __TIME__ << ": ";
	m_foutLogFile << __DATE__ << ", " << __TIME__ << ": ";
}

void Manager::Logout(std::string content, bool bHasInfo)
{
	if (bHasInfo)
		LogoutInfo();

	cout << content << endl;
	m_foutLogFile << content << endl;
}

//����˵����
//1��sChoice���û�����Ĺ���ѡ��
//2��iExtra����������
//3��iKeyword������ѡ��
//4��sExtra����iKeywordƥ�������ֵ
//�����ĸ�����Ϊ��2, 3��iExtra����ʾ��ѯ������ 3��ʾ�����ڡ���, 
//3��iKeyword����ʾ���Ա�ţ� 3��ʾ����Ʒ�۸񡱣�, 20��sExtra�������ʾ�û�Ҫִ�в�ѯ������
//��ִ�еĲ���Ϊ����ѯ�۸����20Ԫ�Ĳ�Ʒ
void Manager::InventoryManager(std::string sChoice, int iExtra, int iKeyword, std::string sExtra)
{
	//��ȡ��Ʒ��Ϣ����ͷָ��
	m_productHead = ProductList::GetListHead();
	if (sChoice == "1")             //����1����Ʒ��Ϣ��ʾ
	{
		Logout("��ʾ��Ʒ�б�");
		//��Ʒ��Ϣ�ѱ����������У���ʾ����ڵ���Ϣ
		m_productHead->ShowAllProduct();
		Logout("��ʾ���");
	}
	else if (sChoice == "2")       //����2����Ʒ��Ϣ��ѯ
	{
		Logout("��������ѯ");        //����־�ļ��м�¼�û�����
		//�������������Ľڵ���Ϣ��������Щ�ڵ㹹��һ����ѯ�������
		auto p = m_productHead->SearchProduct(static_cast<EType>(iKeyword), static_cast<ProductList::ECondition>(iExtra), sExtra);
		//��pΪnullptr����ʾδ���ҵ����������ļ�¼
		if (!p){
			cout << "************����ѯ����Ϣ��ϵͳ�в�����*************" << endl;
			return;
		}
		//�����ҵ���Ӧ��¼����ʾ��ѯ���
		p->ShowAllProduct(p);
		Logout("��ѯ���");
		ProductList::DeleteProductList(p);//ɾ����ѯ�������
	}
	else if (sChoice == "3")        //����3����Ʒ��Ϣ����
	{
		Logout("����������");         //����־�ļ��м�¼�û�����
		//ͨ��SortProductByEType()������ָ�����������������
		m_productHead->SortProductByEType(static_cast<EType>(iKeyword));
		//��ʾ������
		m_productHead->ShowAllProduct();
		Logout("�������");
	}
	else if (sChoice == "4")        //����4������
	{
		Logout("����");
		//������Ʒ�֣���ɽ�������������������������½ڵ�
		for (auto i = 0; i < iExtra; i++){
			cout << "�������" << i + 1 << "��Ʒ����Ϣ(��" << iExtra << "������" << endl;
			m_productHead->AddProduct();
		}
		Logout("�������");
	}
	else if (sChoice == "5")       //����5������
	{
		Logout("����������");
		//Ѱ�Ҵ������Ľڵ���Ϣ����p��¼
		auto p = m_productHead->SearchProduct(static_cast<EType>(iKeyword), ProductList::ECondition::ON_EQUAL, sExtra);
		//��û�ҵ��������Ĳ�Ʒ�ڵ㣬������û���ʾ
		if (!p){
			cout << "�û��ﲻ���ڣ�" << endl;
			return;
		}
		//����SellProduct()������ɳ�������
		m_productHead->SellProduct(p, iExtra);
		Logout("�������");
		//����pָ��Ŀռ�
		ProductList::DeleteProductList(p);
	}
	else if (sChoice == "6")           //����6���޸Ĳ�Ʒ��Ϣ
	{
		Logout("�޸�");
		//Ѱ�Ҵ��޸ĵĽڵ���Ϣ�������޸Ķ����Ʒ��Ϣ�������޸ĵĶ����Ʒ��Ϣ����������pָ��
		auto p = m_productHead->SearchProduct(static_cast<EType>(iKeyword), static_cast<ProductList::ECondition>(iExtra), sExtra);
		if (!p){
			cout << "************Ҫ�޸ĵ���Ϣ������*************" << endl;
			return;
		}
		//ͨ��EditProduct()���������Ϣ�޸�
		m_productHead->EditProduct(p, ProductList::ESelect::SELECT_FIRST);
		Logout("�޸����");
		//����pָ�������
		ProductList::DeleteProductList(p);
	}
	else if (sChoice == "7")           //����7����ָ��λ�ò�������Ϣ
	{
		Logout("����������");
		//Ѱ�Ҳ���λ��
		auto p = m_productHead->SearchProduct(static_cast<EType>(iKeyword), ProductList::ECondition::ON_EQUAL, sExtra);
		if (!p){
			cout << "û���ҵ�����λ�ã�" << endl;
			return;
		}

		//��ָ��λ�ú�����½ڵ�
		m_productHead->InsertProduct(p, iExtra);
		Logout("�������");

		// �ͷŶ�
		ProductList::DeleteProductList(p);
	}
	else if (sChoice == "8")         //����8����Ϣ����
	{
		Logout("����");
		UpdateRecord();
		Logout("�������");
	}
	else if (sChoice == "9")         //����9���˳�ϵͳ
	{
		Logout("ллʹ��!");
		system("pause");
		return;
	}
}



