#include "messagelog.h"
#include "stdafx.h"
#include "QJsonDocument"

MessageLog::MessageLog(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	shadow = new Shadow();
	setWindowFlags(Qt::FramelessWindowHint);

	ui.dateLabel->setText(QDate::currentDate().toString("yyyy-MM-dd"));
	dateSelector = new QCalendarWidget(this);
	dateSelector->hide();
	dateSelector->setFont(QFont(QStringLiteral("΢���ź�"), 8));
	dateSelector->setHorizontalHeaderFormat(QCalendarWidget::ShortDayNames);
	dateSelector->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
	dateSelector->resize(240, 170);

	mExpressWidget = new ExpressWidget();

	ui.webView->InitCefUrl("file:///./html/messageLog.html");
	connect(ui.webView, SIGNAL(sigZoomImg(QString)), this, SLOT(slotZoomImg(QString)));
	connect(ui.webView, SIGNAL(sigVideoPlay(QString)), this, SLOT(slotVideoPlay(QString)));
	connect(ui.webView, SIGNAL(sigOpenFile(QString)), this, SLOT(slotOpenFile(QString)));
	connect(ui.webView, SIGNAL(sigOpenDir(QString)), this, SLOT(slotOpenDir(QString)));

	QFile style(":/qssWidget/Resources/qssWidget/messagelog.qss");
	style.open(QFile::ReadOnly);
	QString sheet = QLatin1String(style.readAll());
	setStyleSheet(sheet);
	style.close();

	QFile scroolbar_style_qss(":/ScrollBar/Resources/QSS/scrollbarStyle.qss");
	scroolbar_style_qss.open(QFile::ReadOnly);
	ui.perList->verticalScrollBar()->setStyleSheet(scroolbar_style_qss.readAll());
	ui.groupList->verticalScrollBar()->setStyleSheet(scroolbar_style_qss.readAll());
	scroolbar_style_qss.close();

	//���ӶԼ����¼��Ĵ���
	ui.perList->installEventFilter(this);
	ui.groupList->installEventFilter(this);
	//����������ť��
	ui.clearBtn->hide();

	connect(ui.minBtn, SIGNAL(clicked()), this, SLOT(showMinimized()));
	connect(ui.maxBtn, SIGNAL(clicked()), this, SLOT(maxOrRstrWindow()));
	connect(ui.closeBtn, SIGNAL(clicked()), this, SLOT(close()));
	connect(ui.closeBtn, SIGNAL(clicked()), shadow, SLOT(hide()));
	connect(ui.contactsBtn, SIGNAL(toggled(bool)), this, SLOT(doClickContacts(bool)));
	connect(ui.groupBtn, SIGNAL(toggled(bool)), this, SLOT(doClickGroup(bool)));

	connect(ui.perList, SIGNAL(itemClicked(QListWidgetItem *)), this, SLOT(doClickPerItem(QListWidgetItem *)));
	connect(ui.groupList, SIGNAL(itemClicked(QListWidgetItem *)), this, SLOT(doClickGroupItem(QListWidgetItem *)));

	connect(ui.firstPageBtn, SIGNAL(clicked()), this, SLOT(toFirstPage()));
	connect(ui.endPageBtn, SIGNAL(clicked()), this, SLOT(toEndPage()));
	connect(ui.nextPageBtn, SIGNAL(clicked()), this, SLOT(toNextPage()));
	connect(ui.lastPageBtn, SIGNAL(clicked()), this, SLOT(toLastPage()));

	connect(ui.dateBtn, SIGNAL(clicked()), this, SLOT(doShowDateSelector()));
	connect(dateSelector, SIGNAL(clicked(QDate)), this, SLOT(toDateLogPage(QDate)));

	connect(ui.searchBtn, SIGNAL(clicked()), this, SLOT(doSearch()));
	connect(ui.clearBtn, SIGNAL(clicked()), this, SLOT(doClearSearch()));

	ui.perList->hide();
	ui.groupList->hide();
}

MessageLog::~MessageLog()
{
	if (dateSelector)
		delete dateSelector;

	if (mExpressWidget)
		delete mExpressWidget;

	if (shadow)
		delete shadow;
}

void MessageLog::changeEvent(QEvent * event)
{
	if (event->type() == QEvent::WindowStateChange)
	{
		if (this->windowState() == Qt::WindowMaximized)
			shadow->hide();
		if (this->windowState() == Qt::WindowMinimized)
			shadow->hide();

		if (this->windowState() == Qt::WindowNoState)
			shadow->show();
	}

	QWidget::changeEvent(event);
}


void MessageLog::moveEvent(QMoveEvent *event)
{
	shadow->move(event->pos().x() - 10, event->pos().y() - 10);
}

void MessageLog::resizeEvent(QResizeEvent* event)
{
	shadow->resize(event->size().width() + 20, event->size().height() + 20);
}

//����¼��Ĵ���
void MessageLog::mousePressEvent(QMouseEvent *event)
{
	mouse = event->pos();   //�����ƶ���ԭʼλ�á�
	dateSelector->hide();   //��������ѡ������
	return QWidget::mousePressEvent(event);
}
void MessageLog::mouseReleaseEvent(QMouseEvent *event)
{
	mouse.setX(-1);
	return QWidget::mouseReleaseEvent(event);
}
void MessageLog::mouseMoveEvent(QMouseEvent *event)
{
	if (mouse.x() < 0)
		return;
	//����ͨ������ֵ��������λ�Ƶľ��롣
	int x = event->pos().x() - mouse.x();
	int y = event->pos().y() - mouse.y();
	//�ƶ������塣
	this->move(this->x() + x, this->y() + y);
	return QWidget::mouseMoveEvent(event);
}

bool MessageLog::eventFilter(QObject *obj, QEvent *e)
{
	if (e->type() == QEvent::KeyPress)
	{
		if (obj == ui.perList)
		{
			int currentRow = ui.perList->currentRow();
			int row = currentRow;
			QKeyEvent *keyEvent = (QKeyEvent *)e;
			if (keyEvent->key() == Qt::Key_Up)
			{
				if (row - 1 >= 0)   //��С�Ƶ�0λ���б���ǺϷ��ġ�
					row--;
			}
			if (keyEvent->key() == Qt::Key_Down)
			{
				if (row + 1 < ui.perList->count())   //����Ƶ��б�ĩ��ǺϷ��ġ�
					row++;
			}
			if (row != currentRow)  //ͨ������ѡ�����µ��б��
			{
				//��õ�ǰ�����������Ϣ��¼������б�����е������
				QListWidgetItem *currentItem = ui.perList->item(row);
				ui.perList->setCurrentItem(currentItem);
				doClickPerItem(currentItem);

				return true;
			}
		}
		if (obj == ui.groupList)
		{
			int currentRow = ui.groupList->currentRow();
			int row = currentRow;
			QKeyEvent *keyEvent = (QKeyEvent *)e;
			if (keyEvent->key() == Qt::Key_Up)
			{
				if (row - 1 >= 0)   //��С�Ƶ�0λ���б���ǺϷ��ġ�
					row--;
			}
			if (keyEvent->key() == Qt::Key_Down)
			{
				if (row + 1 < ui.groupList->count())   //����Ƶ��б�ĩ��ǺϷ��ġ�
					row++;
			}
			if (row != currentRow)  //ͨ������ѡ�����µ��б��
			{
				//��õ�ǰ�����������Ϣ��¼������б�����е������
				QListWidgetItem *currentItem = ui.groupList->item(row);
				ui.groupList->setCurrentItem(currentItem);
				doClickGroupItem(currentItem);

				return true;
			}
		}
	}
	return QWidget::eventFilter(obj, e);
}

void MessageLog::show()
{
	QWidget::show();
	shadow->resize(width() + 20, height() + 20);
	shadow->move(x() - 10, y() - 10);
	shadow->show();

	// ���ڱ������ˣ�ǿ���ػ�  
	InvalidateRect((HWND)this->winId(), nullptr, FALSE);
}

void MessageLog::maxOrRstrWindow()
{
	if (this->isFullScreen())   //��ǰ�����Ѿ���󻯣����л�ԭ��
	{
		this->showNormal();
		//����ťͼ���Ϊ��󻯡�
		ui.maxBtn->setStyleSheet("QPushButton#maxBtn{border-image:url(:/PerChat/Resources/person/maxsize04.png);}"
			"QPushButton#maxBtn:hover{border-image:url(:/PerChat/Resources/person/maxsize36.png);}");
	}
	else                        //��ǰ�ߴ�Ϊԭʼ�ߴ磬���ִ����󻯲�����                      
	{
		this->showFullScreen();
		//����ťͼ���Ϊ��ԭ��
		ui.maxBtn->setStyleSheet("QPushButton#maxBtn{border-image:url(:/PerChat/Resources/person/rstrsize04.png);}"
			"QPushButton#maxBtn:hover{border-image:url(:/PerChat/Resources/person/rstrsize36.png);}");
	}
}

void MessageLog::doClickContacts(bool checked)
{
	if (checked)
	{
		ui.groupList->hide();
		ui.perList->show();

		if (ui.perList->count() == 0)
		{
			QList<BuddyInfo> listBuddyInfo = gDataBaseOpera->DBGetBuddyInfo();
			for (int i = 0; i < listBuddyInfo.size(); i++)
			{
				if (listBuddyInfo[i].BuddyType == 0)
				{
					continue;
				}
				QString strAvatar = (listBuddyInfo[i]).strLocalAvatar;
				QString strNickName = (listBuddyInfo[i]).strNickName;
				QString strBuddyID = QString("%1").arg((listBuddyInfo[i]).nUserId);
				ui.perList->OnInsertLogUserList(strBuddyID, strAvatar, strNickName, 0);
			}
		}
	}
}

void MessageLog::doClickGroup(bool checked)
{
	if (checked)
	{
		ui.perList->hide();
		ui.groupList->show();

		if (ui.groupList->count() == 0)
		{
			QList<GroupInfo> groupInfo = gDataBaseOpera->DBGetAllGroupInfo();
			for (int i = 0; i < groupInfo.size(); i++)
			{
				ui.groupList->OnInsertLogUserList(groupInfo[i].groupId,
					groupInfo[i].groupLoacalHeadImage,
					groupInfo[i].groupName, 1);
			}
		}
	}
}

void MessageLog::loadPerLogByID(QString id)
{
	doClickContacts(true);
	this->show();             //��ʾ���ڡ�
	int currentRow;    //�洢��ǰ��������ں����б��е�������֮����������ѵ������¼��

	//�ҵ���ǰ�������
	for (int i = 0; i < ui.perList->count(); i++)
	{
		QListWidgetItem *item = ui.perList->item(i);
		QWidget *widget = ui.perList->itemWidget(item);
		CFrientStyleWidget *buddy = (CFrientStyleWidget *)widget;
		if (buddy == NULL)
		{
			qDebug() << "MessageLog::loadPerLogByID��ָ��";
			return;
		}

		QString chatID = buddy->mNickName->objectName();
		if (chatID == id)
		{
			currentRow = i;
			break;
		}	
	}

	//��õ�ǰ�����������Ϣ��¼������б�����е������
	QListWidgetItem *currentItem = ui.perList->item(currentRow);
	ui.perList->setCurrentItem(currentItem);
	doClickPerItem(currentItem);
}

void MessageLog::loadGroupLogByID(QString id)
{
	doClickGroup(true);
	this->show();             //��ʾ���ڡ�
	int currentRow;    //�洢��ǰ���������Ⱥ���б��е�������֮�������Ⱥ��������¼��

	//�ҵ���ǰ�������
	for (int i = 0; i < ui.groupList->count(); i++)
	{
		QListWidgetItem *item = ui.groupList->item(i);
		QWidget *widget = ui.groupList->itemWidget(item);
		CFrientStyleWidget *buddy = (CFrientStyleWidget *)widget;
		if (buddy == NULL)
		{
			qDebug() << "MessageLog::loadGroupLogByID��ָ��";
			return;
		}

		QString chatID = buddy->mNickName->objectName();
		if (chatID == id)
		{
			currentRow = i;
			break;
		}
			
	}
	//��õ�ǰ�����������Ϣ��¼������б�����е������
	QListWidgetItem *currentItem = ui.groupList->item(currentRow);
	ui.groupList->setCurrentItem(currentItem);
	doClickGroupItem(currentItem);
}

void MessageLog::doClickPerItem(QListWidgetItem *item)
{
	QWidget *widget = ui.perList->itemWidget(item);
	CFrientStyleWidget *buddy = (CFrientStyleWidget *)widget;
	if (buddy == NULL)
	{
		qDebug() << "MessageLog::doClickPerItem��ָ��";
		return;
	}
	int chatID = buddy->mNickName->objectName().toInt();
	if (keyString.isEmpty())
		pageAmount = gSocketMessage->DBGetMessageRecordPageNum(chatID);
	else
		pageAmount = gSocketMessage->DBGetSearchMessagePageNum(chatID, keyString);

	if (pageAmount == 0)    //��ϢΪ�ա�
	{
		ui.webView->ExecuteJavaScript("clear()");
		ui.webView->ExecuteJavaScript(QString("setPerTitle(\"%1\")").arg(buddy->GetNikeName()));
		ui.webView->ExecuteJavaScript("space()");

		ui.firstPageBtn->setEnabled(false);
		ui.endPageBtn->setEnabled(false);
		ui.lastPageBtn->setEnabled(false);
		ui.nextPageBtn->setEnabled(false);
	}
	else
	{
		currentPage = 1;
		this->showCurrentPageLog(true);
	}
}

void MessageLog::doClickGroupItem(QListWidgetItem *item)
{
	QWidget *widget = ui.groupList->itemWidget(item);
	CFrientStyleWidget *buddy = (CFrientStyleWidget *)widget;
	if (buddy == NULL)
	{
		qDebug() << "MessageLog::doClickGroupItem��ָ��";
		return;
	}
	int chatID = buddy->mNickName->objectName().toInt();
	if (keyString.isEmpty())
		pageAmount = gSocketMessage->DBGetMessageRecordPageNum(chatID);
	else
		pageAmount = gSocketMessage->DBGetSearchMessagePageNum(chatID, keyString);

	if (pageAmount == 0)    //��ϢΪ�ա�
	{
		ui.firstPageBtn->setEnabled(false);
		ui.endPageBtn->setEnabled(false);
		ui.lastPageBtn->setEnabled(false);
		ui.nextPageBtn->setEnabled(false);

		ui.webView->ExecuteJavaScript("clear()");
		ui.webView->ExecuteJavaScript(QString("setGroupTitle(\"%1\")").arg(buddy->GetNikeName()));
		ui.webView->ExecuteJavaScript("space()");
	}
	else
	{
		currentPage = 1;
		this->showCurrentPageLog(false);
	}
}

QString MessageLog::formatExpressToImgPath(const QString& strMessage)
{
	if (strMessage.isEmpty())
		return strMessage;

	QString str_src(strMessage);
	str_src = str_src.replace("/ >", "/>");

	QRegExp re_img_val("\\[[^\\[^\\]]*\\]");      // �� strMessage �й��� [xxx] ��ʽ��������ʽ

	QString str_result("");
	while (re_img_val.indexIn(str_src) != -1)
	{
		QString img_descrip = re_img_val.cap(0);
		int cur_idx = re_img_val.indexIn(str_src);
		str_result += str_src.left(cur_idx);
		str_src.remove(0, cur_idx + img_descrip.length());    // ɾ���Ѿ����������ַ�

		QString img_path = mExpressWidget->GetImagePathByDescription(img_descrip);
		if (!img_path.isEmpty())
			str_result += "<img src='." + img_path + "'/>";  // ��ʽ��Ϊ <img />��ǩ��ʽ
		else
			str_result += img_descrip;   // ���û���ҵ��򱣳�ԭ�ַ�������
	}
	str_result += str_src;
	return str_result;
}

void MessageLog::showCurrentPageLog(bool isPer)
{
	//���Ҫ��ʾ����Ϣ�����buddy�����а���chatID��nickName��
	CFrientStyleWidget *buddy;
	if (isPer)
		buddy = (CFrientStyleWidget *)ui.perList->itemWidget(ui.perList->currentItem());
	else
		buddy = (CFrientStyleWidget *)ui.groupList->itemWidget(ui.groupList->currentItem());
	//��ȡ��ǰ�û�����Ϣ�����а����û���nickName��
	UserInfo userInfo = gDataManager->getUserInfo();

	//�����û���Ⱥ��Ĳ�ͬ��д����⡣�û�д���롱XXX�������¼��Ⱥ���ǡ��ڡ�XXX�������¼��
	ui.webView->ExecuteJavaScript("clear()");
	if (isPer)
		ui.webView->ExecuteJavaScript(QString("setPerTitle(\"%1\")").arg(buddy->GetNikeName()));
	else
		ui.webView->ExecuteJavaScript(QString("setGroupTitle(\"%1\")").arg(buddy->GetNikeName()));

	//��ȡchatID�Ժ󣬾Ϳ��Ի�õ�ǰҳ��ȫ����Ϣ��¼��
	if (buddy == NULL)
	{
		qDebug() << "MessageLog::showCurrentPageLog��ָ��";
		return;
	}
	int chatID = buddy->mNickName->objectName().toInt();
	QList<MessageInfo> info;
	if (keyString.isEmpty())
		info = gSocketMessage->DBGetMessageRecordByPage(chatID, currentPage - 1);
	else
		info = gSocketMessage->DBGetSearchMessageRecordByPage(chatID, currentPage - 1);
	QDate currentDate;   //����һ�����ڱ��������ݴ����ڣ�����Ϣ��������������ʱ�򣬾Ͳ���һ��ʱ���ߡ�
	for (int i = 0; i < info.count(); i++)
	{
		MessageInfo message = info.at(i);   //��ȡ��ǰҪ��ʾ����Ϣ��
		QString string;  //�ȶ�����������������ݡ�
		QString name;    //��ȡ����һ�����������ͷ����ǳơ�
		if (userInfo.nUserID == message.nFromUserID)
		{
			string = "send";
			name = userInfo.strUserNickName;
		}
		else
		{
			string = "recv";
			if (isPer)
				name = buddy->GetNikeName();
			else
			{
				QList<BuddyInfo> buddyInfo = gDataBaseOpera->DBGetGroupBuddyInfoFromID(QString::number(chatID));
				for (int j = 0; j < buddyInfo.count(); j++)
				{
					if (buddyInfo.at(j).nUserId == message.nFromUserID)
					{
						name = buddyInfo.at(j).strNickName;
						break;
					}
				}
			}
		}
		QDateTime date = QDateTime::fromTime_t(message.ClientTime / 1000);
		QString time = date.toString("hh:mm:ss");  //��ȡ���ڶ�������������ʱ�䡣
		//������ط�����ʱ���ߡ�
		if (i == 0)    //һ��ʼ������Ϣ��¼ǰ���ȼ���ʱ���ߡ�
		{
			currentDate = date.date();
			QString strDate = currentDate.toString("yyyy-MM-dd");
			ui.webView->ExecuteJavaScript(QString("addDate(\"%1\")").arg(strDate));
		}
		else
		{
			//��ǰ��Ϣ�������ݴ����ڲ���������һ��ʱ���ߡ�
			if (currentDate != date.date())
			{
				currentDate = date.date();
				QString strDate = currentDate.toString("yyyy-MM-dd");
				ui.webView->ExecuteJavaScript(QString("addDate(\"%1\")").arg(strDate));
			}
		}
		QString error;
		if (message.MessageChildType == 0)  //����
		{
			message.strMsg = formatExpressToImgPath(message.strMsg);
			string += QString("Text(\"%1\",\"%2\",\"%3\")").arg(name).arg(time).arg(message.strMsg);
		}
		if (message.MessageChildType == 1)  //ͼƬ
		{
			string += QString("Img(\"%1\",\"%2\",\"%3\")").arg(name).arg(time).arg(message.strMsg);
		}
		if (message.MessageChildType == 3)  //��Ƶ
			string += QString("Video(\"%1\",\"%2\",\"%3\")").arg(name).arg(time).arg(message.strMsg);
		if (message.MessageChildType == 5)  //�ļ�
		{
			QString fileName = gDataBaseOpera->DBGetFileInfoLocalPath(message.msgID);
			if (fileName.isEmpty())
				error = "�鿴��Ϣ��¼ʱ���ļ���Ϣ" + message.msgID + "���Ҳ����ļ�·��";
			else
			{
				QJsonDocument document = QJsonDocument::fromJson(message.strMsg.toLocal8Bit().data());
				QJsonValue value = document.object().take("FileSize");
				QString fileSize = value.toString();
				QString fileIcon = "./FileType/007.png";  //Ĭ�ϸ�ֵһ��δ֪ͼ�ꡣ
				//���ݲ�ͬ���ļ����͸�ֵ��ͬ���ļ�ͼ��·����
				//�Ȼ�ȡ��չ����
				QFileInfo fileInfo(fileName);
				QString suffix = fileInfo.suffix().toLower();
				//�������е��ļ����͡�
				QStringList program, zip, text, image, audio, video;
				QStringList word, excel, ppt;
				program << "exe" << "bat" << "msi";
				zip << "rar" << "zip" << "7z";
				text << "txt" << "pdf" << "htm" << "html" << "xml";
				image << "png" << "ico" << "jpg" << "jpeg" << "bmp" << "gif";
				audio << "wav" << "mp3" << "wma" << "aac" << "flac";
				video << "avi" << "wmv" << "3gp" << "mp4" << "rmvb" << "mov" << "mkv";
				video << "rm" << "mpg" << "mpeg" << "ogg";
				word << "doc" << "docx";
				excel << "xls" << "xlsx";
				ppt << "ppt" << "pptx";
				if (program.contains(suffix))
					fileIcon = "./FileType/012.png";
				if (zip.contains(suffix))
					fileIcon = "./FileType/008.png";
				if (text.contains(suffix))
					fileIcon = "./FileType/010.png";
				if (image.contains(suffix))
					fileIcon = "./FileType/005.png";
				if (audio.contains(suffix))
					fileIcon = "./FileType/013.png";
				if (video.contains(suffix))
					fileIcon = "./FileType/004.png";
				if (word.contains(suffix))
					fileIcon = "./FileType/002.png";
				if (excel.contains(suffix))
					fileIcon = "./FileType/003.png";
				if (ppt.contains(suffix))
					fileIcon = "./FileType/001.png";

				string += QString("File(\"%1\",\"%2\",\"%3\",\"%4\",\"%5\")").arg(name).arg(time).arg(fileIcon).arg(fileName).arg(fileSize);
			}	
		}
		//��webview��ִ����ʾ������
		if (error.isEmpty())
			ui.webView->ExecuteJavaScript(string);
			
		else
			qDebug() << error;
	}

	//��ʾ��Ϻ���ĸ���ҳ��ť��״̬�������á�
	ui.firstPageBtn->setEnabled(false);
	ui.endPageBtn->setEnabled(false);
	ui.lastPageBtn->setEnabled(false);
	ui.nextPageBtn->setEnabled(false);

	if (currentPage > 1)
	{
		ui.firstPageBtn->setEnabled(true);
		ui.lastPageBtn->setEnabled(true);
	}
	if (currentPage < pageAmount)
	{
		ui.nextPageBtn->setEnabled(true);
		ui.endPageBtn->setEnabled(true);
	}
}

void MessageLog::toFirstPage()
{
	currentPage = 1;
	showCurrentPageLog(ui.perList->isVisible());
}
void MessageLog::toEndPage()
{
	currentPage = pageAmount;
	showCurrentPageLog(ui.perList->isVisible());
}
void MessageLog::toLastPage()
{
	currentPage--;
	showCurrentPageLog(ui.perList->isVisible());
}
void MessageLog::toNextPage()
{
	currentPage++;
	showCurrentPageLog(ui.perList->isVisible());
}

void MessageLog::slotZoomImg(QString strfileName)
{
	QString fileName = strfileName.mid(strfileName.indexOf("file:///") + 8);

	ZoomImg* zoom = new ZoomImg();
	zoom->OpenImg(fileName);
}

void MessageLog::slotVideoPlay(QString mediaPath)
{
	QString path = mediaPath;
	/*VlcWidget *video = new VlcWidget();
	video->videoPlay(path);*/
}

void MessageLog::slotOpenFile(QString fileName)
{
	QDesktopServices bs;
	bs.openUrl(QUrl::fromLocalFile(fileName));
}

void MessageLog::slotOpenDir(QString fileDir)
{
	QDesktopServices bs;
	bs.openUrl(QUrl::fromLocalFile(fileDir));
}

void MessageLog::doShowDateSelector()
{
	if (dateSelector->isVisible())
		dateSelector->hide();
	else
	{
		QPoint toolPos = ui.toolWidget->pos();
		int x = toolPos.x();
		int y = toolPos.y() - dateSelector->height();
		dateSelector->move(x, y);
		dateSelector->show();
	}
}

void MessageLog::toDateLogPage(QDate date)
{
	//���Ҫ��ʾ����Ϣ�����buddy��
	CFrientStyleWidget *buddy;	
	if (ui.perList->isVisible())
		buddy = (CFrientStyleWidget *)ui.perList->itemWidget(ui.perList->currentItem());
	else
		buddy = (CFrientStyleWidget *)ui.groupList->itemWidget(ui.groupList->currentItem());
	if (buddy == NULL)
	{
		qDebug() << "MessageLog::toDateLogPage��ָ��";
		return;
	}
	int chatID = buddy->mNickName->objectName().toInt();
	int page = -1;    //����һ�������������������ҳ�룬���û�У������������пա�
	//�������е���Ϣ��¼��
	for (int i = 0; i < pageAmount; i++)
	{
		QList<MessageInfo> info = gSocketMessage->DBGetMessageRecordByPage(chatID, i);
		for (int j = 0; j < info.count(); j++)
		{
			MessageInfo message = info.at(j);
			QDateTime time = QDateTime::fromTime_t(message.ClientTime / 1000);
			
			if (date == time.date())  //��ǰҳ����������
			{
				page = i;
				break;
			}
		}
		if (page >= 0)
			break;
	}
	
	if (page >= 0)    //����ҵ��˷���������ҳ�롣
	{
		ui.dateLabel->setText(date.toString("yyyy-MM-dd"));
		//���ǵ�ǰҳ�ٽ��м��ء�
		if (currentPage != page + 1)   //currentpage�洢����1Ϊ��ͷ��ҳ�룬������Ҫ��1��
		{
			currentPage = page + 1;
			showCurrentPageLog(ui.perList->isVisible());
		}
		//������Ŀ������
		ui.webView->ExecuteJavaScript(QString("scrollDate(\"%1\")").arg(date.toString("yyyy-MM-dd")));
		//����ʱ��ѡ������
		dateSelector->hide();
	}
	else
	{
		//��ʾû�з���������ҳ�롣
		QMessageBox::information(this, "��Ǹ", "û�з�����������Ϣ��¼");
	}
}

void MessageLog::doSearch()
{
	if (ui.lineEdit->text().isEmpty())
		QMessageBox::information(this, "ע��", "�������ݲ���Ϊ��");
	else
	{
		this->keyString = ui.lineEdit->text();
		if (ui.perList->isVisible())
		{
			QListWidgetItem *item = ui.perList->currentItem();
			doClickPerItem(item);
		}
		else
		{
			QListWidgetItem *item = ui.groupList->currentItem();
			doClickGroupItem(item);
		}

		this->keyString = "";
	}
}

void MessageLog::doClearSearch()
{
	ui.lineEdit->clear();
	this->keyString = "";
	if (ui.perList->isVisible())
		doClickPerItem(ui.perList->currentItem());
	else
		doClickGroupItem(ui.groupList->currentItem());
}