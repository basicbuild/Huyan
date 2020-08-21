#include "huyan.h"
#include "stdafx.h"
#include <QVBoxLayout>
#include <QGraphicsDropShadowEffect>
#include <qpushbutton.h>
#include "UIHuyan.h"

huyan::huyan(QWidget *parent)
    : QDialog(parent)
{
    initUI();
}

void huyan::initUI()
{
    setFixedSize(800, 450);
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    this->setWindowFlags(Qt::FramelessWindowHint);
    // 总布局
    QVBoxLayout* _vlayoutContent = new QVBoxLayout(this);

    // 标题栏
    UITitleBar *_uiTitleBar = new UITitleBar(this);

    //  huyan
    UIHuyan* _uiHuyan = new UIHuyan(this);

    _vlayoutContent->addWidget(_uiTitleBar);
    _vlayoutContent->addWidget(_uiHuyan);
  //  _vlayoutContent->addStretch();
    _vlayoutContent->setContentsMargins(10, 10, 10, 10);

    setLayout(_vlayoutContent);
}

void huyan::mouseMoveEvent(QMouseEvent* event)
{
    if (m_bPressed)
        move(event->pos() - m_point + pos());
}

void huyan::mouseReleaseEvent(QMouseEvent* event)
{
    Q_UNUSED(event);
    m_bPressed = false;
}

void huyan::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_bPressed = true;
        m_point = event->pos();
    }
}

void huyan::paintEvent(QPaintEvent* event)
{
    if (m_bShadow)
    {
        QPainterPath path;
        path.setFillRule(Qt::WindingFill);
        path.addRect(m_nShadowWidth, m_nShadowWidth, this->width() - m_nShadowWidth * 2, this->height() - m_nShadowWidth * 2);
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing, true);
        painter.fillPath(path, QBrush(Qt::white));
        QColor color(0, 128, 192, 50);
        //QColor color(125, 125, 125, 50);
        for (int i = 0; i < m_nShadowWidth; i++)
        {
            QPainterPath path;
            path.setFillRule(Qt::WindingFill);
            path.addRect(m_nShadowWidth - i, m_nShadowWidth - i, this->width() - (m_nShadowWidth - i) * 2, this->height() - (m_nShadowWidth - i) * 2);
            color.setAlpha(100 - qSqrt(i) * 50);
            painter.setPen(color);
            painter.drawPath(path);
        }

        return;
    }
    else
        return QWidget::paintEvent(event);
}
