#ifndef ALPHABETICALSORTSHAREDLIB_H
#define ALPHABETICALSORTSHAREDLIB_H

//汉字拼音首字母列表 本列表,包含了20902个汉字的拼音的第一个字母
//本表收录的汉字字符的Unicode编码范围为19968至40869

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
