/************************************
*
*
*
************************************/
#pragma once
#include <QtWidgets/QDialog>
#include "UITitleBar.h"
#include <QMainWindow>

class huyan : public QDialog
{
    Q_OBJECT

public:
    huyan(QWidget *parent = Q_NULLPTR);

protected:
    void mouseReleaseEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void paintEvent(QPaintEvent* event);

private:
    void initUI();

    bool m_bPressed = true;
    QPoint m_point;

    bool m_bShadow = true;
    int m_nShadowWidth = 10;
};
