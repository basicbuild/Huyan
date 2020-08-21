#pragma once

#include <QWidget>
#include "ui_UIHuyan.h"
#include <QLabel>

class UIHuyan : public QWidget
{
	Q_OBJECT

public:
	UIHuyan(QWidget *parent = Q_NULLPTR);
	~UIHuyan();

private slots:
		void on_slider_bright_activated(int _bright);
		void on_slider_color_activated(int _color);
		void on_mouse_press();
private:
	Ui::UIHuyan ui;

	void initUI();
};
