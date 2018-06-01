#include "opdatamanager.h"

OPDataManager::OPDataManager()
{

}

OPDataManager::~OPDataManager()
{

}

void OPDataManager::encryption(QString text, QString key, QString path /*= "key"*/)
{
	//���ܡ�
	TAesClass *aes = new TAesClass;
	aes->initKey(key);

	QByteArray byte = text.toLatin1();
	char *mingwen = byte.data();
	DWORD size = strlen(mingwen);
	char miwen[AesLength];
	aes->OnAesEncrypt((LPVOID)mingwen, size, (LPVOID)miwen); //���м���

	QFile file(path);
	if (file.open(QIODevice::WriteOnly))
	{
		file.write(miwen, AesLength);
		file.close();
	}
}

QString OPDataManager::Decryption(QString key, QString path /*= "key"*/)
{
	//���ܡ�
	QString plainText;

	QFile file(path);
	if (file.open(QIODevice::ReadOnly))
	{
		char miwen[AesLength];
		file.read(miwen, AesLength);
		file.close();

		TAesClass *aes = new TAesClass;
		aes->initKey(key);
		plainText = aes->OnAesUncrypt((LPVOID)miwen, (DWORD)sizeof(miwen)); //���н���
	}

	return plainText;
}
