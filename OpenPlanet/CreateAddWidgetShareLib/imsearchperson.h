#ifndef IMSEARCHPERSON_H
#define IMSEARCHPERSON_H

#include <QWidget>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include "ui_imsearchperson.h"
#include "cfrientstylewidget.h"
#include "imbuddy.h"
#include "common.h"
#include "stdafx.h"
#include "httpnetworksharelib.h"

class IMSearchPerson : public QWidget
{
	Q_OBJECT

public:
	IMSearchPerson(QWidget *parent = 0);
	~IMSearchPerson();

	void ClearList();
private:
	void OnSearchPerson(QString strData);
	void OnInsertTabList(QString strBuddyID, QWidget *widget);
	void ParseSearchPersonResult(QString strResult);
private slots:
	void doClickSearch();
	void doHttpSearchPersonResultInfo(bool bState, QString strResult);
	void doAddPerson(QString strBuddyID);
	void doHttpAddPersonResultInfo(bool bResult, QString strResult);
private:
	Ui::IMSearchPerson ui;
	QString mStrSaveSearchContent;   //±£´æËÑË÷ÐÅÏ¢
};

#endif // IMSEARCHPERSON_H
