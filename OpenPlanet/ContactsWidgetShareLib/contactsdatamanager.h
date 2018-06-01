#ifndef CONTACTSDATAMANAGER_H
#define CONTACTSDATAMANAGER_H

#include <QObject>
#include <QJsonDocument>
#include "contactswidget.h"
#include "contactslist.h"
#include "grouplist.h"
#include "imtranstype.h"
#include "opcommon.h"
#include "opdatamanager.h"
#include "opdatebasesharelib.h"
#include "oprequestsharelib.h"

//************************************
// 1.
// FullName:  ContactsDataManager::recvContactsData
//************************************

class ContactsDataManager : public QObject
{
	Q_OBJECT

public:
	ContactsDataManager(QObject *parent=NULL);
	~ContactsDataManager();

	ContactsWidget *getContactsWidget();

	//************************************
	// Method:    updateBuddyImage
	// FullName:  ContactsDataManager::updateBuddyImage
	// Access:    public 
	// Returns:   void
	// Qualifier: 更新好友头像
	// Parameter: int nBuddyID
	// Parameter: QPixmap pix
	//************************************
	void updateImage(int type,int nIMuserID, QPixmap pix);

	//************************************
	// Method:    recvBuddyData
	// FullName:  ContactsDataManager::recvBuddyData
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: int type
	// Parameter: QVariant data
	//************************************
	void recvBuddyData(int type, QVariant data);

	//************************************
	// Method:    recvGroupData
	// FullName:  ContactsDataManager::recvGroupData
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: int type
	// Parameter: QVariant data
	//************************************
	void recvGroupData(int type, QVariant data);

private slots:
    void slotAddressInfo(QString);
    void slotPerProfile(QString);
    void slotGroupProfile(QString);

signals:
	void sigAddCreateGroup();
	void sigAddPerson();

signals:
	void sigOpenChat(int, QVariant);

private:
	ContactsWidget *widget;
	ContactsList *contactsList;
	GroupList *groupList;
	perProfileWidget *perWidget;
	GroupProfileWidget *groupWidget;
};

#endif // CONTACTSDATAMANAGER_H
