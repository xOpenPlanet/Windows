#include "qv8extensionhandler.h"
#include <QDebug>

QV8ExtensionHandler::QV8ExtensionHandler(QObject *parent)
	: QObject(parent)
{

}

QV8ExtensionHandler::~QV8ExtensionHandler()
{

}

bool QV8ExtensionHandler::Execute(const CefString &name, CefRefPtr<CefV8Value> object, const CefV8ValueList &arguments, CefRefPtr<CefV8Value> &retval, CefString &exception)
{
	//MessageLog
	if (name == "slotZoomImg")
	{
		CefString string = arguments.at(0)->GetStringValue();
		CefRefPtr<CefProcessMessage> msg = CefProcessMessage::Create("slotZoomImg");
		CefRefPtr<CefListValue> args = msg->GetArgumentList();
		args->SetSize(1);
		args->SetString(0, string);
		CefV8Context::GetCurrentContext()->GetBrowser()->SendProcessMessage(PID_BROWSER, msg);
	}
	if (name == "slotVideoPlay")
	{
		CefString string = arguments.at(0)->GetStringValue();
		CefRefPtr<CefProcessMessage> msg = CefProcessMessage::Create("slotVideoPlay");
		CefRefPtr<CefListValue> args = msg->GetArgumentList();
		args->SetSize(1);
		args->SetString(0, string);
		CefV8Context::GetCurrentContext()->GetBrowser()->SendProcessMessage(PID_BROWSER, msg);
	}
	if (name == "slotOpenFile")
	{
		CefString string = arguments.at(0)->GetStringValue();
		CefRefPtr<CefProcessMessage> msg = CefProcessMessage::Create("slotOpenFile");
		CefRefPtr<CefListValue> args = msg->GetArgumentList();
		args->SetSize(1);
		args->SetString(0, string);
		CefV8Context::GetCurrentContext()->GetBrowser()->SendProcessMessage(PID_BROWSER, msg);
	}
	if (name == "slotOpenDir")
	{
		CefString string = arguments.at(0)->GetStringValue();
		CefRefPtr<CefProcessMessage> msg = CefProcessMessage::Create("slotOpenDir");
		CefRefPtr<CefListValue> args = msg->GetArgumentList();
		args->SetSize(1);
		args->SetString(0, string);
		CefV8Context::GetCurrentContext()->GetBrowser()->SendProcessMessage(PID_BROWSER, msg);
	}

	//IMPerChat
	//ÒÑÓÐslotOpenFile
	if (name == "slotOpenDocument")
	{
		CefString string = arguments.at(0)->GetStringValue();
		CefRefPtr<CefProcessMessage> msg = CefProcessMessage::Create("slotOpenDocument");
		CefRefPtr<CefListValue> args = msg->GetArgumentList();
		args->SetSize(1);
		args->SetString(0, string);
		CefV8Context::GetCurrentContext()->GetBrowser()->SendProcessMessage(PID_BROWSER, msg);
	}
	if (name == "slotCancleLoadorDownLoad")
	{
		CefRefPtr<CefProcessMessage> msg = CefProcessMessage::Create("slotCancleLoadorDownLoad");
		CefV8Context::GetCurrentContext()->GetBrowser()->SendProcessMessage(PID_BROWSER, msg);
	}
	if (name == "slotSendFileByID")
	{
		CefString string = arguments.at(0)->GetStringValue();
		CefRefPtr<CefProcessMessage> msg = CefProcessMessage::Create("slotSendFileByID");
		CefRefPtr<CefListValue> args = msg->GetArgumentList();
		args->SetSize(1);
		args->SetString(0, string);
		CefV8Context::GetCurrentContext()->GetBrowser()->SendProcessMessage(PID_BROWSER, msg);
	}
	if (name == "slotGetFile")
	{
		CefString string = arguments.at(0)->GetStringValue();
		CefRefPtr<CefProcessMessage> msg = CefProcessMessage::Create("slotGetFile");
		CefRefPtr<CefListValue> args = msg->GetArgumentList();
		args->SetSize(1);
		args->SetString(0, string);
		CefV8Context::GetCurrentContext()->GetBrowser()->SendProcessMessage(PID_BROWSER, msg);
	}
	if (name == "slotSaveFile")
	{
		CefString string = arguments.at(0)->GetStringValue();
		CefRefPtr<CefProcessMessage> msg = CefProcessMessage::Create("slotSaveFile");
		CefRefPtr<CefListValue> args = msg->GetArgumentList();
		args->SetSize(1);
		args->SetString(0, string);
		CefV8Context::GetCurrentContext()->GetBrowser()->SendProcessMessage(PID_BROWSER, msg);
	}
	if (name == "slotOpenUrl")
	{
		CefString string = arguments.at(0)->GetStringValue();
		CefRefPtr<CefProcessMessage> msg = CefProcessMessage::Create("slotOpenUrl");
		CefRefPtr<CefListValue> args = msg->GetArgumentList();
		args->SetSize(1);
		args->SetString(0, string);
		CefV8Context::GetCurrentContext()->GetBrowser()->SendProcessMessage(PID_BROWSER, msg);
	}
	if (name == "slotDrag")
	{
		CefRefPtr<CefProcessMessage> msg = CefProcessMessage::Create("slotDrag");
		CefV8Context::GetCurrentContext()->GetBrowser()->SendProcessMessage(PID_BROWSER, msg);
	}

	//GroupChatWidget
	if (name == "slotOpenGroupFile")
	{
		CefString string = arguments.at(0)->GetStringValue();
		CefRefPtr<CefProcessMessage> msg = CefProcessMessage::Create("slotOpenGroupFile");
		CefRefPtr<CefListValue> args = msg->GetArgumentList();
		args->SetSize(1);
		args->SetString(0, string);
		CefV8Context::GetCurrentContext()->GetBrowser()->SendProcessMessage(PID_BROWSER, msg);
	}
	if (name == "slotSendFile")
	{
		CefString string = arguments.at(0)->GetStringValue();
		CefRefPtr<CefProcessMessage> msg = CefProcessMessage::Create("slotSendFile");
		CefRefPtr<CefListValue> args = msg->GetArgumentList();
		args->SetSize(1);
		args->SetString(0, string);
		CefV8Context::GetCurrentContext()->GetBrowser()->SendProcessMessage(PID_BROWSER, msg);
	}

	//recoveryWallet
	if (name == "slotRecoveryResult")
	{
		CefString string = arguments.at(0)->GetStringValue();
		CefRefPtr<CefProcessMessage> msg = CefProcessMessage::Create("slotRecoveryResult");
		CefRefPtr<CefListValue> args = msg->GetArgumentList();
		args->SetSize(1);
		args->SetString(0, string);
		CefV8Context::GetCurrentContext()->GetBrowser()->SendProcessMessage(PID_BROWSER, msg);
	}

	//transferManager
	if (name == "slotTransactionData")
	{
		CefString string = arguments.at(0)->GetStringValue();
		CefRefPtr<CefProcessMessage> msg = CefProcessMessage::Create("slotTransactionData");
		CefRefPtr<CefListValue> args = msg->GetArgumentList();
		args->SetSize(1);
		args->SetString(0, string);
		CefV8Context::GetCurrentContext()->GetBrowser()->SendProcessMessage(PID_BROWSER, msg);
	}

	return false;
}