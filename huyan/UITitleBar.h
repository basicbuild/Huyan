/************************************
*
*
*
************************************/
#pragma once
#include <QWidget>

class UITitleBar : public QWidget
{
	Q_OBJECT

public:
	UITitleBar(QWidget *parent = Q_NULLPTR);
	~UITitleBar();

private:
	void initUI();
};
