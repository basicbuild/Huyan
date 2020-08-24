#include "UIToolButton.h"
#include <QAction>

UIToolButton::UIToolButton(QWidget *parent)
	: QToolButton(parent)
{
	 
}

UIToolButton::UIToolButton(QString _text, QString _icon, QWidget* parent)
	: QToolButton(parent)
{
	QAction* pAction = new QAction(this);
	pAction->setText(_text);
	pAction->setIcon(QIcon(_icon));
	this->setIconSize(QSize(48, 48));
	pAction->setToolTip(QString::fromLocal8Bit("三生三世"));
	this->setDefaultAction(pAction);
	this->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
}

UIToolButton::~UIToolButton()
{
}
 