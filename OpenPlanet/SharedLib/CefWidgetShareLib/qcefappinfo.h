#ifndef QCEFAPPINFO_H
#define QCEFAPPINFO_H

#include <QObject>

#include "include/cef_app.h"  
#include "include/cef_client.h" 
#include "qv8extensionhandler.h" 

struct CefJSClassName
{
	QString strClassName;
	QObject *obj;
};

class QCefAppInfo : public QObject, public CefApp, public CefRenderProcessHandler 
{
	Q_OBJECT

public:
	QCefAppInfo(QObject *parent = 0);
	~QCefAppInfo();

	virtual void OnContextCreated(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, CefRefPtr<CefV8Context> context);

	CefRefPtr<CefRenderProcessHandler> GetRenderProcessHandler() OVERRIDE
	{
		return this;
	}
	
	void OnWebKitInitialized() OVERRIDE;

	virtual void OnBeforeCommandLineProcessing(
		const CefString& process_type,
		CefRefPtr<CefCommandLine> command_line)OVERRIDE;

	void addToJavaScriptWindowObject(CefRefPtr<CefBrowser> browser,QString className, QObject *obj);

private:
	QMap<CefRefPtr<CefBrowser>, QList<CefJSClassName>> mMapJSClassName;
	IMPLEMENT_REFCOUNTING(QCefAppInfo);
};

#endif // QCEFAPPINFO_H
