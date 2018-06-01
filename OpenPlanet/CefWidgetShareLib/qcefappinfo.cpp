#include "qcefappinfo.h"
#include <QMapIterator>
#include <QDebug>

QCefAppInfo::QCefAppInfo(QObject *parent)
	: QObject(parent)
{
	
}

QCefAppInfo::~QCefAppInfo()
{

}

void QCefAppInfo::OnContextCreated(CefRefPtr<CefBrowser> browser,
	CefRefPtr<CefFrame> frame,
	CefRefPtr<CefV8Context> context)
{
	CefRefPtr<CefV8Value> object = context->GetGlobal();
	QV8ExtensionHandler *handle = new QV8ExtensionHandler();

	//MessageLog
	CefRefPtr<CefV8Value> funcZoomImg = CefV8Value::CreateFunction("slotZoomImg", handle);
	CefRefPtr<CefV8Value> funcVideoPlay = CefV8Value::CreateFunction("slotVideoPlay", handle);
	CefRefPtr<CefV8Value> funcOpenFile = CefV8Value::CreateFunction("slotOpenFile", handle);
	CefRefPtr<CefV8Value> funcOpenDir = CefV8Value::CreateFunction("slotOpenDir", handle);
	
	object->SetValue("slotZoomImg", funcZoomImg, V8_PROPERTY_ATTRIBUTE_NONE);
	object->SetValue("slotVideoPlay", funcVideoPlay, V8_PROPERTY_ATTRIBUTE_NONE);
	object->SetValue("slotOpenFile", funcOpenFile, V8_PROPERTY_ATTRIBUTE_NONE);
	object->SetValue("slotOpenDir", funcOpenDir, V8_PROPERTY_ATTRIBUTE_NONE);

	//IMPerChat
	//已有slotOpenFile
	CefRefPtr<CefV8Value> funcOpenDocument = CefV8Value::CreateFunction("slotOpenDocument", handle);
	CefRefPtr<CefV8Value> funcCancleLoadorDownLoad = CefV8Value::CreateFunction("slotCancleLoadorDownLoad", handle);
	CefRefPtr<CefV8Value> funcSendFileByID = CefV8Value::CreateFunction("slotSendFileByID", handle);
	CefRefPtr<CefV8Value> funcGetFile = CefV8Value::CreateFunction("slotGetFile", handle);
	CefRefPtr<CefV8Value> funcSaveFile = CefV8Value::CreateFunction("slotSaveFile", handle);
	CefRefPtr<CefV8Value> funcOpenUrl = CefV8Value::CreateFunction("slotOpenUrl", handle);
	CefRefPtr<CefV8Value> funcDrag = CefV8Value::CreateFunction("slotDrag", handle);

	object->SetValue("slotOpenDocument", funcOpenDocument, V8_PROPERTY_ATTRIBUTE_NONE);
	object->SetValue("slotCancleLoadorDownLoad", funcCancleLoadorDownLoad, V8_PROPERTY_ATTRIBUTE_NONE);
	object->SetValue("slotSendFileByID", funcSendFileByID, V8_PROPERTY_ATTRIBUTE_NONE);
	object->SetValue("slotGetFile", funcGetFile, V8_PROPERTY_ATTRIBUTE_NONE);
	object->SetValue("slotSaveFile", funcSaveFile, V8_PROPERTY_ATTRIBUTE_NONE);
	object->SetValue("slotOpenUrl", funcOpenUrl, V8_PROPERTY_ATTRIBUTE_NONE);
	object->SetValue("slotDrag", funcDrag, V8_PROPERTY_ATTRIBUTE_NONE);

	//GroupChatWidget
	CefRefPtr<CefV8Value> funcOpenGroupFile = CefV8Value::CreateFunction("slotOpenGroupFile", handle);
	CefRefPtr<CefV8Value> funcSendFile = CefV8Value::CreateFunction("slotSendFile", handle);

	object->SetValue("slotOpenGroupFile", funcOpenGroupFile, V8_PROPERTY_ATTRIBUTE_NONE);
	object->SetValue("slotSendFile", funcSendFile, V8_PROPERTY_ATTRIBUTE_NONE);

	//恢复钱包。
	CefRefPtr<CefV8Value> funcRecoveryResult = CefV8Value::CreateFunction("slotRecoveryResult", handle);
	object->SetValue("slotRecoveryResult", funcRecoveryResult, V8_PROPERTY_ATTRIBUTE_NONE);

	//转账.
	CefRefPtr<CefV8Value> funcTransactionData = CefV8Value::CreateFunction("slotTransactionData", handle);
	object->SetValue("slotTransactionData", funcTransactionData, V8_PROPERTY_ATTRIBUTE_NONE);
	
}

void QCefAppInfo::OnWebKitInitialized()
{
	
}

void QCefAppInfo::addToJavaScriptWindowObject(CefRefPtr<CefBrowser> browser,QString className, QObject *obj)
{
	
}

void QCefAppInfo::OnBeforeCommandLineProcessing(const CefString& process_type, CefRefPtr<CefCommandLine> command_line)
{
	//command_line->AppendSwitchWithValue("--proxy-server", "proxy.xa.petrochina:8080");
}