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
	void doClickSearchPerson();  //搜索个人
	void doClickSearchGroup();  //搜索群组
	void doClickSearchAppNo(); //搜索应用号
	void doClickClose();
private:
	Ui::IMAddPerson ui;
	IMSearchPerson *mSearchPerson;   //搜索个人
	IMSearchGroup  *mSearchGroup;   //搜索群组
};

#endif // IMADDPERSON_H
