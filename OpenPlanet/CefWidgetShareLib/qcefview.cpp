#include "qcefview.h"
#include "include/cef_browser.h"
#include "include/cef_command_line.h"
#include "include/wrapper/cef_helpers.h"
#include <string>
#include <QFile>
#include <QResizeEvent>
#include <QDebug>

QCefView::QCefView(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	cefHandle = NULL;
}

QCefView::~QCefView()
{
}

void QCefView::InitCefUrl(QString strURL)
{
	RECT rect;
	rect.left = 0;
	rect.top = 0;
	rect.right = this->width();
	rect.bottom = this->height();
	CefWindowInfo info;
	CefBrowserSettings b_settings;
	cefHandle = new QCefHandle;

	//connect
	//MessageLog
	connect(cefHandle, SIGNAL(sigZoomImg(QString)), this, SIGNAL(sigZoomImg(QString)));
	connect(cefHandle, SIGNAL(sigVideoPlay(QString)), this, SIGNAL(sigVideoPlay(QString)));
	connect(cefHandle, SIGNAL(sigOpenDir(QString)), this, SIGNAL(sigOpenDir(QString)));
	connect(cefHandle, SIGNAL(sigOpenFile(QString)), this, SIGNAL(sigOpenFile(QString)));

	//IMPerChat
	//ÒÑÓÐsigOpenFile(QString)
	connect(cefHandle, SIGNAL(sigOpenDocument(QString)), this, SIGNAL(sigOpenDocument(QString)));
	connect(cefHandle, SIGNAL(sigCancleLoadorDownLoad()), this, SIGNAL(sigCancleLoadorDownLoad()));
	connect(cefHandle, SIGNAL(sigSendFileByID(QString)), this, SIGNAL(sigSendFileByID(QString)));
	connect(cefHandle, SIGNAL(sigGetFile(QString)), this, SIGNAL(sigGetFile(QString)));
	connect(cefHandle, SIGNAL(sigSaveFile(QString)), this, SIGNAL(sigSaveFile(QString)));
	connect(cefHandle, SIGNAL(sigOpenUrl(QString)), this, SIGNAL(sigOpenUrl(QString)));
	connect(cefHandle, SIGNAL(sigDrag(QStringList)), this, SIGNAL(sigDrag(QStringList)));

	//GroupChatWidget
	connect(cefHandle, SIGNAL(sigOpenGroupFile(QString)), this, SIGNAL(sigOpenGroupFile(QString)));
	connect(cefHandle, SIGNAL(sigSendFile(QString)), this, SIGNAL(sigSendFile(QString)));

	//recoveryWallet
	connect(cefHandle, SIGNAL(sigRecoveryResult(QString)), this, SIGNAL(sigRecoveryResult(QString)));

	//transferManager
	connect(cefHandle, SIGNAL(sigTransactionData(QString)), this, SIGNAL(sigTransactionData(QString)));

	info.SetAsChild((HWND)this->winId(), rect);
	
	CefBrowserHost::CreateBrowser(info, cefHandle.get(), strURL.toStdString(), b_settings, NULL);
	QTimer::singleShot(100, this, SLOT(slotStyle()));
}

void QCefView::ExecuteJavaScript(QString strJS)
{
	qDebug() << strJS;
	if (cefHandle.get())
	{
		CefRefPtr<CefBrowser> browser = cefHandle->GetBrowser();
		if (browser.get())
		{
			CefRefPtr<CefFrame> frame = browser->GetMainFrame();
			if (frame.get())
			{
				frame->ExecuteJavaScript(strJS.toStdString(), frame->GetURL(), 0);
			}
		}
	}
}

void QCefView::resizeEvent(QResizeEvent *event)
{
	if (cefHandle.get())
	{
		CefRefPtr<CefBrowser> browser = cefHandle->GetBrowser();
		if (browser.get())
		{
			CefWindowHandle hwnd = browser->GetHost()->GetWindowHandle();
			HWND child = GetWindow(hwnd, GW_CHILD);
			HWND widget = GetWindow(child, GW_CHILD);
			::MoveWindow(hwnd, 0, 0, event->size().width(), event->size().height(), TRUE);
		}
	}
}

void QCefView::slotStyle()
{
	if (cefHandle.get())
	{
		CefRefPtr<CefBrowser> browser = cefHandle->GetBrowser();
		if (browser.get())
		{
			CefWindowHandle hwnd = browser->GetHost()->GetWindowHandle();
			HWND child = GetWindow(hwnd, GW_CHILD);
			if (child)
			{
				::SetWindowLong(child, GWL_STYLE, GetWindowLong(child, GWL_STYLE)& ~WS_CAPTION & ~WS_THICKFRAME);
			}
		}
	}

	if (cefHandle.get())
	{
		CefRefPtr<CefBrowser> browser = cefHandle->GetBrowser();
		if (browser.get())
		{
			CefWindowHandle hwnd = browser->GetHost()->GetWindowHandle();
			HWND child = GetWindow(hwnd, GW_CHILD);
			HWND widget = GetWindow(child, GW_CHILD);
			::MoveWindow(hwnd, 0, 0, this->width()+1, this->height()+1, TRUE);
			::MoveWindow(hwnd, 0, 0, this->width(), this->height(), TRUE);
		}
	}
	
}