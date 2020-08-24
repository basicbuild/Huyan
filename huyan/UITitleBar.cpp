#include "stdafx.h"
#include "UITitleBar.h"
#include <QHBoxLayout>
#include <QGraphicsDropShadowEffect>
#include <qpushbutton.h>

UITitleBar::UITitleBar(QWidget *parent)
	: QWidget(parent)
{
	this->setAutoFillBackground(true); // 自动刷新背景
	QPalette palette(this->palette());
	palette.setColor(QPalette::Background, RGB(248, 196, 75));
	this->setPalette(palette);
	initUI();
}

UITitleBar::~UITitleBar()
{
}

void UITitleBar::initUI()
{
	setFixedHeight(35);

	QHBoxLayout* _vlayoutMain = new QHBoxLayout(this);

	// logo
	QLabel* lbeLogo = new QLabel(this);
	lbeLogo->setObjectName("logoLabel");
	lbeLogo->setFixedSize(30, 30);

	// 名称
	QLabel* lbeName = new QLabel(tr("Huyan"), this);
	lbeName->setObjectName("nameLabel");


	_vlayoutMain->addWidget(lbeLogo);
	_vlayoutMain->addWidget(lbeName);
	_vlayoutMain->addStretch();
	_vlayoutMain->setContentsMargins(10, 0, 10, 0);
	setLayout(_vlayoutMain);

}