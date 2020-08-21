#include "stdafx.h"
#include "UITitleBar.h"
#include <QHBoxLayout>
#include <QGraphicsDropShadowEffect>
#include <qpushbutton.h>

UITitleBar::UITitleBar(QWidget *parent)
	: QWidget(parent)
{
	this->setAutoFillBackground(true); // ×Ô¶¯Ë¢ÐÂ±³¾°
	initUI();
}

UITitleBar::~UITitleBar()
{
}

void UITitleBar::initUI()
{
	setFixedHeight(35);

	QHBoxLayout* _vlayoutMain = new QHBoxLayout(this);

	QPushButton* _widget = new QPushButton(this);
	QPushButton* _widget1 = new QPushButton(this);
	_widget1->setFixedWidth(100);
	_widget1->setObjectName("button");
	_widget->setObjectName("button");

	_vlayoutMain->addWidget(_widget);
	_vlayoutMain->addStretch();
	_vlayoutMain->addWidget(_widget1);
	_vlayoutMain->setContentsMargins(10, 10, 10, 10);
	setLayout(_vlayoutMain);


	connect(_widget, &QPushButton::clicked, [this]() {
		system("color 34");
		});


	connect(_widget1, &QPushButton::clicked, [this]() {
		system("color 19");
		});
}