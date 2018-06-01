#ifndef QCEFHANDLE_H
#define QCEFHANDLE_H

#include <QObject>
#include "include/cef_client.h"
#include <list>

class QCefHandle : public QObject,
	public CefClient,
	public CefDisplayHandler,
	public CefLifeSpanHandler,
	public CefLoadHandler,
	public CefContextMenuHandler,
	public CefDragHandler,
	public CefRequestHandler
{
	Q_OBJECT

public:
	QCefHandle(QObject *parent = 0);
	~QCefHandle();

	static QCefHandle* GetInstance();

	CefRefPtr<CefBrowser> GetBrowser();

	virtual CefRefPtr<CefDisplayHandler> GetDisplayHandler() OVERRIDE
	{
		return this;
	}

	virtual CefRefPtr<CefLifeSpanHandler> GetLifeSpanHandler() OVERRIDE
	{
		return this;
	}

	virtual CefRefPtr<CefLoadHandler> GetLoadHandler() OVERRIDE
	{
		return this;
	}
	virtual CefRefPtr<CefContextMenuHandler> GetContextMenuHandler()
	{
		return this;
	}
	virtual CefRefPtr<CefDragHandler> GetDragHandler()  {
		return this;
	}
	virtual CefRefPtr<CefRequestHandler> GetRequestHandler() OVERRIDE{
		return this;
	}

	virtual void OnTitleChange(CefRefPtr<CefBrowser> browser,
		const CefString& title) OVERRIDE;

	virtual void OnAfterCreated(CefRefPtr<CefBrowser> browser) OVERRIDE;
	virtual bool DoClose(CefRefPtr<CefBrowser> browser) OVERRIDE;
	virtual void OnBeforeClose(CefRefPtr<CefBrowser> browser) OVERRIDE;

	virtual void OnLoadError(CefRefPtr<CefBrowser> browser,CefRefPtr<CefFrame> frame,ErrorCode errorCode,const CefString& errorText,const CefString& failedUrl) OVERRIDE;

	void CloseAllBrowsers(bool force_close);

	bool IsClosing() const { return is_closing_; }

	bool OnProcessMessageReceived(CefRefPtr<CefBrowser> browser,
		CefProcessId source_process,
		CefRefPtr<CefProcessMessage> message) OVERRIDE;

	void OnBeforeContextMenu(CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefFrame> frame,
		CefRefPtr<CefContextMenuParams> params,
		CefRefPtr<CefMenuModel> model) OVERRIDE;

	bool OnDragEnter(CefRefPtr<CefBrowser>browser, CefRefPtr<CefDragData> dragData, CefDragHandler::DragOperationsMask mask) OVERRIDE;
	virtual bool OnBeforeBrowse(CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefFrame> frame,
		CefRefPtr<CefRequest> request,
		bool is_redirect) OVERRIDE;

private:
	typedef std::list<CefRefPtr<CefBrowser> > BrowserList;
	BrowserList browser_list_;

	bool is_closing_;

	bool m_bIsDrag;
	QStringList fileList;

	IMPLEMENT_REFCOUNTING(QCefHandle);

signals:
	//MessageLog
	void sigZoomImg(QString);
	void sigVideoPlay(QString);
	void sigOpenFile(QString);
	void sigOpenDir(QString);

	//IMPerChat
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
};

#endif // QCEFHANDLE_H
