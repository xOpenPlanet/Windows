#ifndef ALPHABETICALSORTSHAREDLIB_H
#define ALPHABETICALSORTSHAREDLIB_H

//����ƴ������ĸ�б� ���б�,������20902�����ֵ�ƴ���ĵ�һ����ĸ
//������¼�ĺ����ַ���Unicode���뷶ΧΪ19968��40869

#include <QString>

class AlphabeticalSortSharedLib
{
public:
	AlphabeticalSortSharedLib();
	~AlphabeticalSortSharedLib();

	QString GetChineseSpell(QString& src);

private:
	QString strChineseFirstPY;
};

#endif // ALPHABETICALSORTSHAREDLIB_H
