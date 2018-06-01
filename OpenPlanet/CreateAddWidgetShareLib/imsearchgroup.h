#ifndef IMSEARCHGROUP_H
#define IMSEARCHGROUP_H

#include <QWidget>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include "imbuddy.h"
#include "stdafx.h"
#include "ui_imsearchgroup.h"
#include "httpnetworksharelib.h"

class IMSearchGroup : public QWidget
{
	Q_OBJECT

public:
	IMSearchGroup(QWidget *parent = 0);
	~IMSearchGroup();

	void OnSearchGroup(QString strData);
private:
	void ParseSearchGroupResult(QString strResult);
private slots:
	void doClickSearchGroup();
	void doHttpSearchGroupResultInfo(bool bState, QString strResult);
	void doAddGroup(QString strGroupID);
	void doHttpAddGroupResultInfo(bool bResult, QString strResult);
private:
	Ui::IMSearchGroup ui;
	QString mStrSaveSearchContent;
};

#endif // IMSEARCHGROUP_H
