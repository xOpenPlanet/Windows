#ifndef QCEFVIEW_H
#define QCEFVIEW_H

#include <QtWidgets/QWidget>
#include <qtimer.h>
#include <QEvent>
#include <QMimeData>
#include "ui_qcefview.h"
#include "qcefhandle.h"
#include "qcefappinfo.h"
#include <qdebug.h>

class QCefView : public QWidget
{
	Q_OBJECT

public:
	QCefView(QWidget *parent = 0);
	~QCefView();

	void InitCefUrl(QString strURL);

	void ExecuteJavaScript(QString strJS);

	virtual void resizeEvent(QResizeEvent *);

private slots:
	void slotStyle();

signals:
	//MessageLog
	void sigZoomImg(QString);
	void sigVideoPlay(QString);
	void sigOpenFile(QString);
	void sigOpenDir(QString);

	//IMPerChat
	//ÒÑÓÐsigOpenFile(QString)
	void sigOpenDocument(QString);
	void sigCancleLoadorDownLoad();
	void sigSendFileByID(QString);
	void sigGetFile(QString);
	void sigSaveFile(QString);
	void sigOpenUrl(QString);
	void sigDrag(QStringList);

	//GroupChatWidget
	void sigOpenGroupFile(QString);
	void sigSendFile(QString);

	//recoveryWallet
	void sigRecoveryResult(QString);

	//transferManager
	void sigTransactionData(QString);

private:
	Ui::QCefViewClass ui;
	CefRefPtr<QCefHandle> cefHandle;
};

#endif // QCEFVIEW_H
