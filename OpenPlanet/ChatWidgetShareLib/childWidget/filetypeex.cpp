#include "filetypeex.h"
#include <QDebug>

FileTypeEx::FileTypeEx(QObject *parent)
	: QObject(parent)
{
	OnInit();
}

FileTypeEx::~FileTypeEx()
{

}

void FileTypeEx::OnInit()
{
	/*插入Txt*/
	QList<QString> txtListType;
	txtListType.append("txt");
	txtListType.append("TXT");
	mMapFileType.insert("./FileType/010.png", txtListType);

	/*插入PDF*/
	QList<QString> pdfListType;
	pdfListType.append("pdf");
	pdfListType.append("PDF");
	pdfListType.append("pps");
	pdfListType.append("pot");
	mMapFileType.insert("./FileType/006.png", pdfListType);

	/*插入压缩文件格式*/
	QList<QString> rarListType;
	rarListType.append("rar");
	rarListType.append("zip");
	rarListType.append("gz");
	rarListType.append("arj");
	rarListType.append("cab");
	rarListType.append("iso");
	mMapFileType.insert("./FileType/008.png", rarListType);

	QList<QString> xmlListType;
	xmlListType.append("xml");
	mMapFileType.insert("./FileType/009.png", xmlListType);

	/*插入html css*/
	QList<QString> cssListType;
	cssListType.append("html");
	cssListType.append("css");
	cssListType.append("htm");
	mMapFileType.insert("./FileType/011.png", cssListType);

	/*插入ppt*/
	QList<QString> pptListType;
	pptListType.append("ppt");
	pptListType.append("pptx");
	pptListType.append("pot");
	pptListType.append("pps");
	pptListType.append("ppa");
	mMapFileType.insert("./FileType/001.png", pptListType);

	/*插入word*/
	QList<QString> wordListType;
	wordListType.append("doc");
	wordListType.append("docx");
	mMapFileType.insert("./FileType/002.png", wordListType);

	/*插入Excel*/
	QList<QString> excelListType;
	excelListType.append("xls");
	excelListType.append("xlsx");
	excelListType.append("xlsb");
	excelListType.append("xlsm");
	excelListType.append("xlst");
	mMapFileType.insert("./FileType/003.png", excelListType);

	/*插入图片*/
	QList<QString> picListType;
	picListType.append("jpeg");
	picListType.append("png");
	picListType.append("ico");
	picListType.append("tiff");
	picListType.append("jpg");
	picListType.append("bmp");
	picListType.append("gif");
	picListType.append("raw");
	mMapFileType.insert("./FileType/005.png", picListType);

	/*插入音视频*/
	QList<QString> vedioListType;
	vedioListType.append("mp4");
	vedioListType.append("avi");
	vedioListType.append("asf");
	vedioListType.append("wmv");
	vedioListType.append("avs");
	vedioListType.append("flv");
	vedioListType.append("mkv");
	vedioListType.append("mov");
	vedioListType.append("3gp");
	vedioListType.append("mpeg");
	vedioListType.append("dat");
	vedioListType.append("ogm");
	vedioListType.append("vob");
	vedioListType.append("rm");
	vedioListType.append("rmvb");
	vedioListType.append("ts");
	vedioListType.append("tp");
	vedioListType.append("ifo");
	vedioListType.append("nsv");
	vedioListType.append("m2ts");
	mMapFileType.insert("./FileType/004.png", vedioListType);

	/*插入音频*/
	QList<QString> audioListType;
	audioListType.append("wav");
	audioListType.append("mp3");
	audioListType.append("wma");
	audioListType.append("ogg");
	audioListType.append("ape");
	audioListType.append("flac");
	audioListType.append("ra");
	mMapFileType.insert("./FileType/013.png", audioListType);

	QList<QString> exeListType;
	exeListType.append("exe");
	mMapFileType.insert("./FileType/012.png", exeListType);
}

QString FileTypeEx::GetFileType(QString strFilePath)
{
	QFile file(strFilePath);
	QString strFileName = file.fileName();
	int nIndex = strFileName.lastIndexOf(".");
	QString strFileType = strFileName.mid(nIndex+1, strFileName.length());
	return strFileType;
}

int FileTypeEx::GetFileSize(QString strFilePath)
{
	QFile file(strFilePath);
	return file.size();
}

QString FileTypeEx::GetFilePic(QString strFilePath)
{
	QString strPic = "";
	QString strFileType = GetFileType(strFilePath);
	QMap<QString, QList<QString> >::iterator itor = mMapFileType.begin();
	for (itor; itor != mMapFileType.end(); ++itor)
	{
		for (int i = 0; i < itor.value().size();i++)
		{
			if (itor.value()[i] == strFileType.toLower())
			{
				strPic = itor.key();
				break;
			}
		}
	}
	if (strPic.isEmpty())
	{
		strPic = "./FileType/007.png";
	}
	return strPic;
}

