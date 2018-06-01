#ifndef QV8EXTENSIONHANDLER_H
#define QV8EXTENSIONHANDLER_H

#include <QObject>
#include "include/cef_app.h"
#include <QMap>

class QV8ExtensionHandler : public QObject, public CefV8Handler
{
	Q_OBJECT

	bool Execute(const CefString &name, CefRefPtr<CefV8Value> object, const CefV8ValueList &arguments, CefRefPtr<CefV8Value> &retval, CefString &exception) OVERRIDE;
	
public:
	QV8ExtensionHandler(QObject *parent=0);
	~QV8ExtensionHandler();
	
private:
	
	IMPLEMENT_REFCOUNTING(QV8ExtensionHandler);
};

#endif // QV8EXTENSIONHANDLER_H
