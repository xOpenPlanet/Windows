#ifndef IMADDPERSON_H
#define IMADDPERSON_H

#include <QWidget>
#include "ui_imaddperson.h"
#include "basewindow.h"
#include "imsearchperson.h"
#include "imsearchgroup.h"
#include "httpnetworksharelib.h"

class IMAddPerson : public BaseWindow
{
	Q_OBJECT

public:
	IMAddPerson(QWidget *parent = 0);
	~IMAddPerson();

private:
	void initTitleBar();

private slots:
	void doClickSearchPerson();  //��������
	void doClickSearchGroup();  //����Ⱥ��
	void doClickSearchAppNo(); //����Ӧ�ú�
	void doClickClose();
private:
	Ui::IMAddPerson ui;
	IMSearchPerson *mSearchPerson;   //��������
	IMSearchGroup  *mSearchGroup;   //����Ⱥ��
};

#endif // IMADDPERSON_H
