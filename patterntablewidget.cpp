#include "patterntablewidget.h"
// TODO: Probably includes way too much stuff!
#include <QtGui>
#include <QDebug>
#include <iostream>

// TODO: Don't need QFrame so just change to QWidget (border will be the QTabWidget)
PatternTableWidget::PatternTableWidget(QWidget *parent)
    : QWidget(parent)
{
    this->setMouseTracking(true);

    this->setFixedSize(512, 512);
}

void PatternTableWidget::mouseMoveEvent(QMouseEvent *e)
{
    int x = e->pos().x() - (e->pos().x() % 4);
    int y = e->pos().y() - (e->pos().y() % 4);

    qDebug() << "x: " << x << " y: " << y;
}

void PatternTableWidget::drawWidget(QPainter &qp)
{
    for (int x = 0; x < 128; x++)
    {
        for (int y = 0; y < 128; y++)
        {
            QColor redColor(rand()%255, rand()%255, rand()%255);
            qp.setPen(redColor);
            qp.setBrush(redColor);
            qp.drawRect(x*4, y*4, 3, 3);

            if (y % 8 == 0)
            {
                QColor lineColor(100, 100, 100);
                qp.setPen(lineColor);
                qp.setBrush(lineColor);
                qp.drawLine(0, y*4, 512, y*4); 
            }
        }
        if (x % 8 == 0)
        {
           QColor lineColor(100, 100, 100);
           qp.setPen(lineColor);
           qp.setBrush(lineColor);
           qp.drawLine(x*4, 0, x*4, 512); 
        }
    }
}

void PatternTableWidget::paintEvent(QPaintEvent *e)
{
  
  QPainter qp(this);
  drawWidget(qp);
  
  QWidget::paintEvent(e);  
}