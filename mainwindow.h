#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QAction>
#include <QtGui>
#include <QAction>
#include <QMenuBar>
#include <QMenu>
#include <QTabWidget>
#include <Qt>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    public:
        MainWindow();
    private slots:
    private:
    void onOpenAction();
    // Menus
    QMenu *fileMenu;
    QMenu *helpMenu;
    // Actions
    QAction *quitAction;
    QAction *aboutAction;
    QAction *saveAction;
    QAction *cancelAction;
    QAction *openAction;
    QAction *newAction;
    QAction *aboutQtAction;
};

#endif