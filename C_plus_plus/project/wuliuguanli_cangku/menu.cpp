#include "menu.h"
#include <iostream>

using namespace std;

static const int MAX_LEN = 80;

#define OUTPUT_CONTENT(content) \
do \
{ \
	int len = strlen(content); \
	if (len > 0) \
			{ \
		len = (MAX_LEN - len) / 2; \
		cout << "#"; \
		for (auto i = 1; i < len; i++) \
			cout << " "; \
		cout << content; \
		for (auto i = 1; i < len; i++) \
			cout << " "; \
		cout << "#"; \
	} \
	else \
	{ \
		for (auto i = 0; i < 80; i++) \
			cout << "#"; \
	} \
} \
while (0)

void Menu::MainMenu()
{
	OUTPUT_CONTENT("");
	OUTPUT_CONTENT("��ӭʹ����������ϵͳ");
	OUTPUT_CONTENT("1.��ʼӪҵ");
	OUTPUT_CONTENT("2.��    ��");
	OUTPUT_CONTENT("");
}

void Menu::SubMenu()
{
	OUTPUT_CONTENT("");
	OUTPUT_CONTENT("***��������ϵͳ***");
	OUTPUT_CONTENT("1.��ʾ��Ʒ�б�");
	OUTPUT_CONTENT("2.��������ѯ");
	OUTPUT_CONTENT("3.����������");
	OUTPUT_CONTENT("4.��      ��");
	OUTPUT_CONTENT("5.��      ��");
	OUTPUT_CONTENT("6.��      ��");
	OUTPUT_CONTENT("7.��      ��");
	OUTPUT_CONTENT("8.��      ��");
	OUTPUT_CONTENT("9.��      ��");
	OUTPUT_CONTENT("");
}


