#pragma once

#include "manager.h"

class Control{
private:
	Manager m_manager;                              //Manager��������ʵ��ϵͳ����
	std::string m_strChoice;                       //����ѡ��ֵ
public:
	Control();
	~Control();
	void MainControl();                             //ϵͳ������ں���
};

