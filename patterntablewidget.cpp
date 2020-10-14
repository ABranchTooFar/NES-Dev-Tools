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
    mouse_x = e->pos().x() - (e->pos().x() % 4);
    mouse_y = e->pos().y() - (e->pos().y() % 4);


    update();
}

void PatternTableWidget::drawWidget(QPainter &qp)
{
    qDebug() << "x: " << mouse_x << " y: " << mouse_y;
    for (int x = 0; x < 128; x++)
    {
        for (int y = 0; y < 128; y++)
        {
            // TODO: Move this out of the loop now that it is not random
            QColor redColor(255, 0, 0);
            if (x*4 == mouse_x && y*4 == mouse_y)
            {
                redColor = QColor(0, 0, 255);
            }
            qp.setPen(redColor);
            qp.setBrush(redColor);
            qp.drawRect(x*4, y*4, 2, 2);

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