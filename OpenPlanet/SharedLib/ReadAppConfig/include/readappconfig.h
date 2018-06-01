#ifndef READAPPCONFIG_H
#define READAPPCONFIG_H

/*��ȡ���������ļ�*/
#include "common.h"

class ReadAppConfig
{
public:
	ReadAppConfig();
	~ReadAppConfig();

	//************************************
	// Method:    ReadConfig
	// FullName:  ReadAppConfig::ReadConfig
	// Access:    public 
	// Returns:   ConfigApp
	// Qualifier: ��ȡ�����ļ���Ϣ������ConfigApp�ṹ��
	// Parameter: QString configPath
	//************************************
	AppConfig ReadConfig(QString configPath);

private:

};

#endif // READAPPCONFIG_H
