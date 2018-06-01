#ifndef QLABELHEADER_H
#define QLABELHEADER_H

#include <QLabel>

class QLabelHeader : public QLabel
{
	Q_OBJECT

public:
	QLabelHeader(QWidget *parent = 0);
	~QLabelHeader();

protected:
	void paintEvent(QPaintEvent *e);
};

#endif // QLABELHEADER_H
