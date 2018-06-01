#include "qcefhandle.h"

#include <sstream>
#include <string>

#include "include/base/cef_bind.h"
#include "include/cef_app.h"
#include "include/wrapper/cef_closure_task.h"
#include "include/wrapper/cef_helpers.h"

#include <QDebug>

namespace 
{

	QCefHandle* g_instance = NULL;
}  // namespace

QCefHandle::QCefHandle(QObject *parent)
	: QObject(parent)
{
	//DCHECK(!g_instance);
	//g_instance = this;
	is_closing_ = false;

	m_bIsDrag = false;
}

QCefHandle::~QCefHandle()
{
	g_instance = NULL;
}

QCefHandle* QCefHandle::GetInstance() {
	return g_instance;
}

void QCefHandle::OnAfterCreated(CefRefPtr<CefBrowser> browser) 
{
	CEF_REQUIRE_UI_THREAD();

	// Add to the list of existing browsers.
	browser_list_.push_back(browser);
}

bool QCefHandle::DoClose(CefRefPtr<CefBrowser> browser)
{
	CEF_REQUIRE_UI_THREAD();

	// Closing the main window requires special handling. See the DoClose()
	// documentation in the CEF header for a detailed destription of this
	// process.
	if (browser_list_.size() == 1) {
		// Set a flag to indicate that the window close should be allowed.
		is_closing_ = true;
	}

	// Allow the close. For windowed browsers this will result in the OS close
	// event being sent.
	return false;
}

void QCefHandle::OnBeforeClose(CefRefPtr<CefBrowser> browser) 
{
	CEF_REQUIRE_UI_THREAD();

	// Remove from the list of existing browsers.
	BrowserList::iterator bit = browser_list_.begin();
	for (; bit != browser_list_.end(); ++bit) {
		if ((*bit)->IsSame(browser)) {
			browser_list_.erase(bit);
			break;
		}
	}

	if (browser_list_.empty()) {
		// All browser windows have closed. Quit the application message loop.
		//CefQuitMessageLoop();
	}
}

void QCefHandle::OnLoadError(CefRefPtr<CefBrowser> browser,
	CefRefPtr<CefFrame> frame,
	ErrorCode errorCode,
	const CefString& errorText,
	const CefString& failedUrl) {
	CEF_REQUIRE_UI_THREAD();

	// Don't display an error for downloaded files.
	if (errorCode == ERR_ABORTED)
		return;

	// Display a load error message.
	std::stringstream ss;
	ss << "<html><body bgcolor=\"white\">"
		"<h2>Failed to load URL " << std::string(failedUrl) <<
		" with error " << std::string(errorText) << " (" << errorCode <<
		").</h2></body></html>";
	frame->LoadString(ss.str(), failedUrl);
}

void QCefHandle::CloseAllBrowsers(bool force_close) {
	if (!CefCurrentlyOn(TID_UI)) {
		// Execute on the UI thread.
		CefPostTask(TID_UI,
			base::Bind(&QCefHandle::CloseAllBrowsers, this, force_close));
		return;
	}

	if (browser_list_.empty())
		return;

	BrowserList::const_iterator it = browser_list_.begin();
	for (; it != browser_list_.end(); ++it)
		(*it)->GetHost()->CloseBrowser(force_close);
}

void QCefHandle::OnTitleChange(CefRefPtr<CefBrowser> browser,
	const CefString& title) {
	CEF_REQUIRE_UI_THREAD();

	CefWindowHandle hwnd = browser->GetHost()->GetWindowHandle();
	SetWindowText(hwnd, std::wstring(title).c_str());
}

CefRefPtr<CefBrowser> QCefHandle::GetBrowser()
{
	BrowserList::iterator bit = browser_list_.begin();
	CefRefPtr<CefBrowser> browser;
	for (; bit != browser_list_.end(); ++bit) 
	{
		browser = *bit;
		break;
	}
	return browser;
}
bool QCefHandle::OnProcessMessageReceived(CefRefPtr<CefBrowser> browser,
	CefProcessId source_process,
	CefRefPtr<CefProcessMessage> message)
{
	const std::string& messageName = message->GetName();
	//MessageLog
	if (messageName == "slotZoomImg")
	{
		CefRefPtr<CefListValue> args = message->GetArgumentList();
		CefString string = args->GetString(0);

		emit sigZoomImg(QString::fromStdString(string.ToString()));
		return true;
	}
	if (messageName == "slotVideoPlay")
	{
		CefRefPtr<CefListValue> args = message->GetArgumentList();
		CefString string = args->GetString(0);

		emit sigVideoPlay(QString::fromStdString(string.ToString()));
		return true;
	}
	if (messageName == "slotOpenFile")
	{
		CefRefPtr<CefListValue> args = message->GetArgumentList();
		CefString string = args->GetString(0);

		emit sigOpenFile(QString::fromStdString(string.ToString()));
		return true;
	}
	if (messageName == "slotOpenDir")
	{
		CefRefPtr<CefListValue> args = message->GetArgumentList();
		CefString string = args->GetString(0);

		emit sigOpenDir(QString::fromStdString(string.ToString()));
		return true;
	}

	//IMPerChat
	//ÒÑÓÐslotOpenFile
	if (messageName == "slotOpenDocument")
	{
		CefRefPtr<CefListValue> args = message->GetArgumentList();
		CefString string = args->GetString(0);

		emit sigOpenDocument(QString::fromStdString(string.ToString()));
		return true;
	}
	if (messageName == "slotCancleLoadorDownLoad")
	{
		emit sigCancleLoadorDownLoad();
		return true;
	}
	if (messageName == "slotSendFileByID")
	{
		CefRefPtr<CefListValue> args = message->GetArgumentList();
		CefString string = args->GetString(0);

		emit sigSendFileByID(QString::fromStdString(string.ToString()));
		return true;
	}
	if (messageName == "slotGetFile")
	{
		CefRefPtr<CefListValue> args = message->GetArgumentList();
		CefString string = args->GetString(0);

		emit sigGetFile(QString::fromStdString(string.ToString()));
		return true;
	}
	if (messageName == "slotSaveFile")
	{
		CefRefPtr<CefListValue> args = message->GetArgumentList();
		CefString string = args->GetString(0);

		emit sigSaveFile(QString::fromStdString(string.ToString()));
		return true;
	}
	if (messageName == "slotOpenUrl")
	{
		CefRefPtr<CefListValue> args = message->GetArgumentList();
		CefString string = args->GetString(0);

		emit sigOpenUrl(QString::fromStdString(string.ToString()));
		return true;
	}
	if (messageName == "slotDrag")
	{
		emit sigDrag(fileList);
		return true;
	}

	//GroupChatWidget
	if (messageName == "slotOpenGroupFile")
	{
		CefRefPtr<CefListValue> args = message->GetArgumentList();
		CefString string = args->GetString(0);

		emit sigOpenGroupFile(QString::fromStdString(string.ToString()));
		return true;
	}
	if (messageName == "slotSendFile")
	{
		CefRefPtr<CefListValue> args = message->GetArgumentList();
		CefString string = args->GetString(0);

		emit sigSendFile(QString::fromStdString(string.ToString()));
		return true;
	}

	if (messageName == "slotRecoveryResult")
	{
		CefRefPtr<CefListValue> args = message->GetArgumentList();
		CefString string = args->GetString(0);

		emit sigRecoveryResult(QString::fromStdString(string.ToString()));
		return true;
	}

	if (messageName == "slotTransactionData")
	{
		CefRefPtr<CefListValue> args = message->GetArgumentList();
		CefString string = args->GetString(0);

		emit sigTransactionData(QString::fromStdString(string.ToString()));
		return true;
	}

	return false;
}

void QCefHandle::OnBeforeContextMenu(CefRefPtr<CefBrowser> browser,
	CefRefPtr<CefFrame> frame,
	CefRefPtr<CefContextMenuParams> params,
	CefRefPtr<CefMenuModel> model)
{
	if ((params->GetTypeFlags() & (CM_TYPEFLAG_PAGE | CM_TYPEFLAG_FRAME)) != 0) {
		// Add a separator if the menu already has items.
		if (model->GetCount() > 0)
		{
			model->Clear();
			//model->AddSeparator();
		}
	}
}

bool QCefHandle::OnDragEnter(CefRefPtr<CefBrowser>browser, CefRefPtr<CefDragData> dragData, CefDragHandler::DragOperationsMask mask)
{
	std::vector<CefString> str;
	dragData->GetFileNames(str);

	fileList.clear();
	for (auto string : str)
		fileList << QString::fromStdString(string.ToString());

	m_bIsDrag = true;
	
	return false;
}

bool QCefHandle::OnBeforeBrowse(CefRefPtr<CefBrowser> browser,
	CefRefPtr<CefFrame> frame,
	CefRefPtr<CefRequest> request,
	bool is_redirect)
{
	if (m_bIsDrag)
	{
		m_bIsDrag = false;
		return true;
	}
	return false;
}