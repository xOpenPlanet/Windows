#ifndef GETDEVICEINFO_H
#define GETDEVICEINFO_H

#include <QObject>

class GetDeviceInfo : public QObject
{
	Q_OBJECT

public:
	GetDeviceInfo(QObject *parent = 0);
	~GetDeviceInfo();

	QString GetDeviceType();          //��ȡ�豸����

	QString GetDeviceVersion();       //��ȡ�豸�汾

	QString GetDeviceManufacturer();   //��ȡ�豸����

	QString GetDeviceModel();          //��ȡ�豸�ͺ�

	QString GetAppVersion();            //��ȡӦ�ð汾��

	QString GetDeviceID();             //��ȡ�豸ID

private:
	
};

#endif // GETDEVICEINFO_H
