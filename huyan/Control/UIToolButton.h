#pragma once

#include <QToolButton>


class UIToolButton : public QToolButton
{
	Q_OBJECT

public:
	UIToolButton(QWidget *parent = Q_NULLPTR);
	UIToolButton(QString _text, QString _icon, QWidget* parent = Q_NULLPTR);
	~UIToolButton();

private:
	
};
