#include "menu.h"
#include "control.h"
#include <iostream>

using namespace std;
#if 1
#define OUTPUT_INFO(out, content, isNum) \
do \
{ \
	out << "��ֱ����룺\nһ��" << content << "�Ĺؼ���������\n"; \
if (content != "����������")\
	out << "(0.��Ʒ�ͺ�; 1.��Ʒ����; 2.��ƷƷ��; 3.��Ʒ�۸�; 4.��Ʒ����)\n"; \
	else\
	out << "(0.��Ʒ�ͺ�; 1.��Ʒ����)\n"; \
if (isNum) \
	out << "����" << content << "����Ŀ��\n"; \
	else \
	out << "����" << "�Ƚ�������" \
	<< "(1.���; 2.С��; 3.����)\n"; \
	out << "����" << content << "�Ķ���\n"; \
} \
while (0)
#endif

#define OUTPUT_ATTRIBUTE_CHOICE(out, content) \
do \
{ \
	out << "�����룺\n" << content << "�Ĺؼ���������\n" \
	<< "(0.��Ʒ�ͺ�; 1.��Ʒ����; 2.��ƷƷ��; 3.��Ʒ�۸�; 4.��Ʒ����)\n"; \
} \
while (0)

#define OUTPUT_CONDITION_INFO(out, content, isStrAttribute, isNum) \
do \
{ \
if (isNum) \
	out << content << "����Ŀ��\n"; \
	else if (isStrAttribute > 2){\
	out << "������Ƚ�����" \
	<< "(1.���; 2.С��; 3.����)��"; \
	cin >> iExtra; \
}else\
	iExtra = 1;\
	out << "������" << content << "�Ķ���"; \
} \
while (0)

Control::Control() :m_manager("product.txt") //��ʼ��m_manager����
{
	Menu::MainMenu();                           //��ʾϵͳ������
	cout << "��ѡ��";
	cin >> m_strChoice;                        //��ȡ�û�����
	if (m_strChoice == "2")                   //���û�ѡ��2�������˳�ϵͳ
		exit(EXIT_SUCCESS);
	else if (m_strChoice == "1")             //��ѡ��1���������ϵͳִ����Ӧ����
	{
		system("pause");
		system("cls");
		//�����Ʒ��Ϣ�ļ���product.txt������������ṹ��ÿ����¼��һ���ڵ�
		m_manager.ReadRecord();
		//ִ��MainControl()�����������û����룬ִ����Ӧ����
		MainControl();
	}
}


Control::~Control()
{

}



void Control::MainControl()
{
	int iExtra = 0;
	int iKeyword = -1;
	std::string sExtra;
	while (true)
	{
		Menu::SubMenu();                            //��ʾ����ѡ�����
		cout << "��ѡ��";
		cin >> m_strChoice;                        //���빦��ѡ��
		if (m_strChoice == "2")                   //ѡ��2����������Ϣ��ѯ
		{
			//�����ʾ��Ϣ�����û�ѡ�����Ա�ţ���ָ�����Խ��в�ѯ
			//���Ա����ö������EType����
			OUTPUT_ATTRIBUTE_CHOICE(cout, "��������ѯ");
			cin >> iKeyword;                      //��ȡ���Ա��
			//�����ʾ�����û�Ҫ�󰴼۸��������ѯ��Ϣ������Ҫ��iExtra�����ѯ����
			OUTPUT_CONDITION_INFO(cout, "��������ѯ", iKeyword, false);
			cin >> sExtra;                        //��ȡ��������
			//�����û�����Ĳ�ѯ����Ϊ����Ʒ�۸����10
			//��iKeywordΪ����Ʒ�۸񡱣�iExtraΪ�����ڡ�, sExtraΪ10
		}
		else if (m_strChoice == "3")              //ѡ��3�������в�Ʒ����
		{
			cout << "��ֱ����밴��������Ĺؼ���������\n";
			cout << "(0.��Ʒ���; 1.��Ʒ����; 2.��Ʒ����; 3.��Ʒ�۸�; 4.��Ʒ����)\n";
			cin >> iKeyword;
		}
		else if (m_strChoice == "4")             //ѡ��4����ʵ�ֲ�Ʒ���
		{
			cout << "���������Ʒ�֣�";             //�������Ʒ��
			cin >> iExtra;
		}
		else if (m_strChoice == "5")             //ѡ��5����ʵ�ֲ�Ʒ����
		{
			OUTPUT_INFO(cout, "����������", true);
			cin >> iKeyword >> iExtra >> sExtra;
		}
		else if (m_strChoice == "6")             //ѡ��6����ʵ�ֲ�Ʒ��Ϣ�޸�
		{
			OUTPUT_INFO(cout, "�������޸�", false);
			cin >> iKeyword >> iExtra >> sExtra;
		}
		else if (m_strChoice == "7")             //ѡ��7������ָ��λ�ò�������Ϣ
		{
			OUTPUT_INFO(cout, "����������", true);
			cin >> iKeyword >> iExtra >> sExtra;
		}
		//ͨ��Manager���Ա����InventoryManager()ʵ���û�ָ������
		//�����ĺ���ֱ�Ϊ��
		//1��m_strChoice���û��Ĺ���ѡ��
		//2��iKeyword��ִ���ӹ���ʱ���ĸ���Ʒ���Խ��в�����
		//              ��iKeywordΪ0��������Ʒ�ͺš�����
		//3��iExtra��ִ���ӹ���ʱ��iKeyword��Ӧ�����԰����ַ������в���
		//4��sExtra������iKeyword������������������
		//���磺iKeywordΪ0������Ʒ�ͺš����� iExtraΪ2��С�ڣ��� sExtraΪ��PRO001��ʱ
		//��ʾ�Բ�Ʒ�ͺ�ֵС�ڡ�PRO001���Ĳ�Ʒִ����Ӧ����
		m_manager.InventoryManager(m_strChoice, iExtra, iKeyword, sExtra);
		if (m_strChoice == "9")
			return;
		system("pause");
		system("cls");
	}
}

