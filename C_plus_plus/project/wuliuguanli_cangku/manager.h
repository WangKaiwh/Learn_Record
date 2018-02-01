#pragma once

#include <fstream>
#include "productList.h"

// ����
class Manager{
private:
	std::ifstream m_finRecord;			// ��������ļ��Ķ���
	std::ofstream m_foutLogFile;		// ������־�ļ��Ķ���
	std::string m_strRecordFile;		// ����ļ���
	std::string m_strLogFileName;		// ��־�ļ���
	ProductList* m_productHead;			// ��Ʒ����ͷ
public:
	//����������Ĭ��ֵ�Ĺ��캯������־�ļ���Ĭ��Ϊ��info.log��
	Manager(std::string fileName, std::string logFile = "info.log");
	~Manager();
public:
	void ReadRecord();                   //ʵ�ֲ�Ʒ��Ϣ�ļ���ȡ��ÿ����¼��Ӧһ������ڵ�
	void UpdateRecord();                 //�ļ����ݸ���
	void BackupRecord(std::string file);//ʵ�֡����̡�����
	void LogoutInfo();                   //����־�ļ�д����Ϣ
	void Logout(std::string content, bool bHasInfo = true);
	//ϵͳ������ں���
	void InventoryManager(std::string sChoice, int iExtra = ProductList::ECondition::ON_NONE, int iKeyword = -1, std::string sExtra = nullptr);
};
