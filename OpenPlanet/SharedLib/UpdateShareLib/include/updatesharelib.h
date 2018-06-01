#ifndef UPDATESHARELIB_H
#define UPDATESHARELIB_H

#include "httpnetworksharelib.h"
#include "stdafx.h"
#include "zlib\zip_util.h"
#include "logindatabaseoperasharelib.h"
#include <QDebug>
#include <QJsonDocument>
#include <Windows.h>
#include <shlwapi.h>
#include <QMessageBox>
#include <QApplication>

class UpdateShareLib : public QObject
{
	Q_OBJECT
public:
	UpdateShareLib();
	~UpdateShareLib();

	void onUpdate();  //Éý¼¶·½·¨¡£

	private slots:
	void slotUpdateApp(bool, QString);
	void slotDownloadUpdate(bool);
	void slotUpdateMain(bool, QString);

signals:
	void sigAlreadyLatest();
	
private:
	int VersionCompare(std::string v1, std::string v2);
};

#endif // UPDATESHARELIB_H
