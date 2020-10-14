#ifndef PATTERNTABLEWIDGET_H
#define PATTERNTABLEWIDGET_H

#include <QWidget>

class PatternTableWidget : public QWidget
{
    Q_OBJECT

    public:
        PatternTableWidget(QWidget *parent = 0);

    public slots:

    protected:
        void mouseMoveEvent(QMouseEvent *e);
        void paintEvent(QPaintEvent *e);
        void drawWidget(QPainter &qp);

    private:
        int mouse_x = 0;
        int mouse_y = 0;
};

#endif