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
	dateSelector->setFont(QFont(QStringLiteral("微软雅黑"), 8));
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

	//增加对键盘事件的处理。
	ui.perList->installEventFilter(this);
	ui.groupList->installEventFilter(this);
	//隐藏搜索按钮。
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

//鼠标事件的处理。
void MessageLog::mousePressEvent(QMouseEvent *event)
{
	mouse = event->pos();   //设置移动的原始位置。
	dateSelector->hide();   //隐藏日期选择器。
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
	//首先通过做差值，获得鼠标位移的距离。
	int x = event->pos().x() - mouse.x();
	int y = event->pos().y() - mouse.y();
	//移动本窗体。
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
				if (row - 1 >= 0)   //最小移到0位的列表项，是合法的。
					row--;
			}
			if (keyEvent->key() == Qt::Key_Down)
			{
				if (row + 1 < ui.perList->count())   //最多移到列表末项，是合法的。
					row++;
			}
			if (row != currentRow)  //通过键盘选择了新的列表项。
			{
				//获得当前聊天对象在消息记录界面的列表项，进行点击处理。
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
				if (row - 1 >= 0)   //最小移到0位的列表项，是合法的。
					row--;
			}
			if (keyEvent->key() == Qt::Key_Down)
			{
				if (row + 1 < ui.groupList->count())   //最多移到列表末项，是合法的。
					row++;
			}
			if (row != currentRow)  //通过键盘选择了新的列表项。
			{
				//获得当前聊天对象在消息记录界面的列表项，进行点击处理。
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

	// 窗口被激活了，强制重绘  
	InvalidateRect((HWND)this->winId(), nullptr, FALSE);
}

void MessageLog::maxOrRstrWindow()
{
	if (this->isFullScreen())   //当前窗口已经最大化，进行还原。
	{
		this->showNormal();
		//将按钮图标变为最大化。
		ui.maxBtn->setStyleSheet("QPushButton#maxBtn{border-image:url(:/PerChat/Resources/person/maxsize04.png);}"
			"QPushButton#maxBtn:hover{border-image:url(:/PerChat/Resources/person/maxsize36.png);}");
	}
	else                        //当前尺寸为原始尺寸，因此执行最大化操作。                      
	{
		this->showFullScreen();
		//将按钮图标变为还原。
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
	this->show();             //显示窗口。
	int currentRow;    //存储当前聊天对象，在好友列表中的行数，之后会打开这个好友的聊天记录。

	//找到当前聊天对象。
	for (int i = 0; i < ui.perList->count(); i++)
	{
		QListWidgetItem *item = ui.perList->item(i);
		QWidget *widget = ui.perList->itemWidget(item);
		CFrientStyleWidget *buddy = (CFrientStyleWidget *)widget;
		if (buddy == NULL)
		{
			qDebug() << "MessageLog::loadPerLogByID空指针";
			return;
		}

		QString chatID = buddy->mNickName->objectName();
		if (chatID == id)
		{
			currentRow = i;
			break;
		}	
	}

	//获得当前聊天对象在消息记录界面的列表项，进行点击处理。
	QListWidgetItem *currentItem = ui.perList->item(currentRow);
	ui.perList->setCurrentItem(currentItem);
	doClickPerItem(currentItem);
}

void MessageLog::loadGroupLogByID(QString id)
{
	doClickGroup(true);
	this->show();             //显示窗口。
	int currentRow;    //存储当前聊天对象，在群组列表中的行数，之后会打开这个群组的聊天记录。

	//找到当前聊天对象。
	for (int i = 0; i < ui.groupList->count(); i++)
	{
		QListWidgetItem *item = ui.groupList->item(i);
		QWidget *widget = ui.groupList->itemWidget(item);
		CFrientStyleWidget *buddy = (CFrientStyleWidget *)widget;
		if (buddy == NULL)
		{
			qDebug() << "MessageLog::loadGroupLogByID空指针";
			return;
		}

		QString chatID = buddy->mNickName->objectName();
		if (chatID == id)
		{
			currentRow = i;
			break;
		}
			
	}
	//获得当前聊天对象在消息记录界面的列表项，进行点击处理。
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
		qDebug() << "MessageLog::doClickPerItem空指针";
		return;
	}
	int chatID = buddy->mNickName->objectName().toInt();
	if (keyString.isEmpty())
		pageAmount = gSocketMessage->DBGetMessageRecordPageNum(chatID);
	else
		pageAmount = gSocketMessage->DBGetSearchMessagePageNum(chatID, keyString);

	if (pageAmount == 0)    //消息为空。
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
		qDebug() << "MessageLog::doClickGroupItem空指针";
		return;
	}
	int chatID = buddy->mNickName->objectName().toInt();
	if (keyString.isEmpty())
		pageAmount = gSocketMessage->DBGetMessageRecordPageNum(chatID);
	else
		pageAmount = gSocketMessage->DBGetSearchMessagePageNum(chatID, keyString);

	if (pageAmount == 0)    //消息为空。
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

	QRegExp re_img_val("\\[[^\\[^\\]]*\\]");      // 从 strMessage 中过滤 [xxx] 形式的正则表达式

	QString str_result("");
	while (re_img_val.indexIn(str_src) != -1)
	{
		QString img_descrip = re_img_val.cap(0);
		int cur_idx = re_img_val.indexIn(str_src);
		str_result += str_src.left(cur_idx);
		str_src.remove(0, cur_idx + img_descrip.length());    // 删除已经遍历过的字符

		QString img_path = mExpressWidget->GetImagePathByDescription(img_descrip);
		if (!img_path.isEmpty())
			str_result += "<img src='." + img_path + "'/>";  // 格式化为 <img />标签形式
		else
			str_result += img_descrip;   // 如果没有找到则保持原字符串不变
	}
	str_result += str_src;
	return str_result;
}

void MessageLog::showCurrentPageLog(bool isPer)
{
	//获得要显示的消息对象的buddy，其中包含chatID跟nickName。
	CFrientStyleWidget *buddy;
	if (isPer)
		buddy = (CFrientStyleWidget *)ui.perList->itemWidget(ui.perList->currentItem());
	else
		buddy = (CFrientStyleWidget *)ui.groupList->itemWidget(ui.groupList->currentItem());
	//获取当前用户的信息，其中包含用户的nickName。
	UserInfo userInfo = gDataManager->getUserInfo();

	//根据用户跟群组的不同，写入标题。用户写“与”XXX的聊天记录，群组是“在”XXX的聊天记录。
	ui.webView->ExecuteJavaScript("clear()");
	if (isPer)
		ui.webView->ExecuteJavaScript(QString("setPerTitle(\"%1\")").arg(buddy->GetNikeName()));
	else
		ui.webView->ExecuteJavaScript(QString("setGroupTitle(\"%1\")").arg(buddy->GetNikeName()));

	//获取chatID以后，就可以获得当前页的全部消息记录。
	if (buddy == NULL)
	{
		qDebug() << "MessageLog::showCurrentPageLog空指针";
		return;
	}
	int chatID = buddy->mNickName->objectName().toInt();
	QList<MessageInfo> info;
	if (keyString.isEmpty())
		info = gSocketMessage->DBGetMessageRecordByPage(chatID, currentPage - 1);
	else
		info = gSocketMessage->DBGetSearchMessageRecordByPage(chatID, currentPage - 1);
	QDate currentDate;   //设置一个日期变量用于暂存日期，当消息日期与它不符的时候，就插入一条时间线。
	for (int i = 0; i < info.count(); i++)
	{
		MessageInfo message = info.at(i);   //获取当前要显示的信息。
		QString string;  //先定义第三个参数，内容。
		QString name;    //获取到第一个参数，发送方的昵称。
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
		QString time = date.toString("hh:mm:ss");  //获取到第二个参数，发送时间。
		//在这个地方插入时间线。
		if (i == 0)    //一开始加载消息记录前，先加载时间线。
		{
			currentDate = date.date();
			QString strDate = currentDate.toString("yyyy-MM-dd");
			ui.webView->ExecuteJavaScript(QString("addDate(\"%1\")").arg(strDate));
		}
		else
		{
			//当前消息日期与暂存日期不符，插入一条时间线。
			if (currentDate != date.date())
			{
				currentDate = date.date();
				QString strDate = currentDate.toString("yyyy-MM-dd");
				ui.webView->ExecuteJavaScript(QString("addDate(\"%1\")").arg(strDate));
			}
		}
		QString error;
		if (message.MessageChildType == 0)  //文字
		{
			message.strMsg = formatExpressToImgPath(message.strMsg);
			string += QString("Text(\"%1\",\"%2\",\"%3\")").arg(name).arg(time).arg(message.strMsg);
		}
		if (message.MessageChildType == 1)  //图片
		{
			string += QString("Img(\"%1\",\"%2\",\"%3\")").arg(name).arg(time).arg(message.strMsg);
		}
		if (message.MessageChildType == 3)  //视频
			string += QString("Video(\"%1\",\"%2\",\"%3\")").arg(name).arg(time).arg(message.strMsg);
		if (message.MessageChildType == 5)  //文件
		{
			QString fileName = gDataBaseOpera->DBGetFileInfoLocalPath(message.msgID);
			if (fileName.isEmpty())
				error = "查看消息记录时，文件消息" + message.msgID + "查找不到文件路径";
			else
			{
				QJsonDocument document = QJsonDocument::fromJson(message.strMsg.toLocal8Bit().data());
				QJsonValue value = document.object().take("FileSize");
				QString fileSize = value.toString();
				QString fileIcon = "./FileType/007.png";  //默认赋值一个未知图标。
				//根据不同的文件类型赋值不同的文件图标路径。
				//先获取扩展名。
				QFileInfo fileInfo(fileName);
				QString suffix = fileInfo.suffix().toLower();
				//罗列所有的文件类型。
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
		//在webview中执行显示方法。
		if (error.isEmpty())
			ui.webView->ExecuteJavaScript(string);
			
		else
			qDebug() << error;
	}

	//显示完毕后对四个翻页按钮的状态进行设置。
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
	//获得要显示的消息对象的buddy。
	CFrientStyleWidget *buddy;	
	if (ui.perList->isVisible())
		buddy = (CFrientStyleWidget *)ui.perList->itemWidget(ui.perList->currentItem());
	else
		buddy = (CFrientStyleWidget *)ui.groupList->itemWidget(ui.groupList->currentItem());
	if (buddy == NULL)
	{
		qDebug() << "MessageLog::toDateLogPage空指针";
		return;
	}
	int chatID = buddy->mNickName->objectName().toInt();
	int page = -1;    //定义一个变量保存符合条件的页码，如果没有，负数可用于判空。
	//遍历所有的消息记录。
	for (int i = 0; i < pageAmount; i++)
	{
		QList<MessageInfo> info = gSocketMessage->DBGetMessageRecordByPage(chatID, i);
		for (int j = 0; j < info.count(); j++)
		{
			MessageInfo message = info.at(j);
			QDateTime time = QDateTime::fromTime_t(message.ClientTime / 1000);
			
			if (date == time.date())  //当前页符合条件。
			{
				page = i;
				break;
			}
		}
		if (page >= 0)
			break;
	}
	
	if (page >= 0)    //如果找到了符合条件的页码。
	{
		ui.dateLabel->setText(date.toString("yyyy-MM-dd"));
		//不是当前页再进行加载。
		if (currentPage != page + 1)   //currentpage存储的是1为开头的页码，所以需要加1。
		{
			currentPage = page + 1;
			showCurrentPageLog(ui.perList->isVisible());
		}
		//滚动至目标区域。
		ui.webView->ExecuteJavaScript(QString("scrollDate(\"%1\")").arg(date.toString("yyyy-MM-dd")));
		//隐藏时间选择器。
		dateSelector->hide();
	}
	else
	{
		//提示没有符合条件的页码。
		QMessageBox::information(this, "抱歉", "没有符合条件的消息记录");
	}
}

void MessageLog::doSearch()
{
	if (ui.lineEdit->text().isEmpty())
		QMessageBox::information(this, "注意", "搜索内容不能为空");
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