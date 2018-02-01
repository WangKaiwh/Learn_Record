#pragma once

#include <string>

#define OFFSET_OF(__TYPE__, __MEMBER__) \
(size_t)(&((static_cast<__TYPE__*>(0))->__MEMBER__))

enum EType
{
	TYPE_SERIAL,              //��Ʒ�ͺ�
	TYPE_NAME,                //��Ʒ����
	TYPE_BRAND,               //��ƷƷ��
	TYPE_PRICE,               //��Ʒ�۸�
	TYPE_COUNT                //��Ʒ����
};


// ��Ʒ
struct Product
{
	std::string sSerial;	// ��Ʒ�ͺ�
	std::string sName;		// ��Ʒ����
	std::string sBrand;		// ��ƷƷ��
	int iPrice;				// ��Ʒ�۸�
	int iCount;				// ��Ʒ����
};

