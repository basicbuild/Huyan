#pragma once

#include <QWidget>
#include "ui_UIHuyan.h"
#include <QLabel>
#include <QButtonGroup>
#include "UIToolButton.h"

class UIHuyan : public QWidget
{
	Q_OBJECT

public:

	enum tagModelType {
		mt_recommend = 1, // �Ƽ�ģʽ
		mt_read, // �Ķ�ģʽ
		mt_blaze, // ǿ��ģʽ
		mt_night, // ��ҹģʽ
		mt_games // ��Ϸģʽ
	};


	UIHuyan(QWidget *parent = Q_NULLPTR);
	~UIHuyan();

private slots:
		void on_slider_bright_activated(int _bright);
		void on_slider_color_activated(int _color);
		void on_mouse_press();
private:
	Ui::UIHuyan ui;

	void initUI();
	UIToolButton* _uiToolButton1;
	UIToolButton* _uiToolButton2;
	UIToolButton* _uiToolButton3;
	UIToolButton* _uiToolButton4;
	UIToolButton* _uiToolButton5;
};
