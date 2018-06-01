#ifndef READAPPCONFIG_H
#define READAPPCONFIG_H

/*读取联信配置文件*/
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
	// Qualifier: 读取配置文件信息，返回ConfigApp结构体
	// Parameter: QString configPath
	//************************************
	AppConfig ReadConfig(QString configPath);

private:

};

#endif // READAPPCONFIG_H
