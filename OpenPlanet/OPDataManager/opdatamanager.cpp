#include "opdatamanager.h"

OPDataManager::OPDataManager()
{

}

OPDataManager::~OPDataManager()
{

}

void OPDataManager::encryption(QString text, QString key, QString path /*= "key"*/)
{
	//加密。
	TAesClass *aes = new TAesClass;
	aes->initKey(key);

	QByteArray byte = text.toLatin1();
	char *mingwen = byte.data();
	DWORD size = strlen(mingwen);
	char miwen[AesLength];
	aes->OnAesEncrypt((LPVOID)mingwen, size, (LPVOID)miwen); //进行加密

	QFile file(path);
	if (file.open(QIODevice::WriteOnly))
	{
		file.write(miwen, AesLength);
		file.close();
	}
}

QString OPDataManager::Decryption(QString key, QString path /*= "key"*/)
{
	//解密。
	QString plainText;

	QFile file(path);
	if (file.open(QIODevice::ReadOnly))
	{
		char miwen[AesLength];
		file.read(miwen, AesLength);
		file.close();

		TAesClass *aes = new TAesClass;
		aes->initKey(key);
		plainText = aes->OnAesUncrypt((LPVOID)miwen, (DWORD)sizeof(miwen)); //进行解密
	}

	return plainText;
}
