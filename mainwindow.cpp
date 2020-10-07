#include <QWidget>
#include <QFileDialog>
#include <vector>
#include <string>

#include "mainwindow.h"
#include "patterntablewidget.h"

//#include <QStyle>
// https://forum.learnpyqt.com/t/are-there-any-built-in-qicons/185/2

MainWindow::MainWindow()
{
    setWindowTitle("Nes Dev Tools");
    setFixedSize(800, 800);
    
    fileMenu = menuBar()->addMenu("&File");
    //openAction = new QAction(this->style()->standardIcon(QStyle::SP_DialogOpenButton), "&New", this);
    openAction = new QAction("&Open", this);
    fileMenu->addAction(openAction);
    connect(openAction, &QAction::triggered, this, &MainWindow::onOpenAction);

    std::vector<QWidget *> patternTables;
    patternTables.push_back(new PatternTableWidget(this));
    patternTables.push_back(new PatternTableWidget(this));
    patternTables.push_back(new PatternTableWidget(this));

    QTabWidget * ptTab = new QTabWidget(this);
    for (unsigned int i = 0; i < patternTables.size(); i++)
    {
        ptTab->addTab(patternTables.at(i), "Pattern Table " + QString::number(i + 1));
    }

    setCentralWidget(ptTab);
}

void MainWindow::onOpenAction()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open the CHR file", QDir::homePath(), "*.chr");

    // QFileDialog returns an empty string when the dialog is cancelled
    if (filename.isEmpty())
    {
        qDebug() << "[DEBUG] File selection was cancelled";
        return;
    }

    // TODO: Do some checks to see if the file is read-only, valid, etc.
    setWindowTitle("NES Dev Tools - " + filename);
    qDebug() << "[DEBUG] Attempting to open CHR file: " << filename;
    QFile chrFile(filename);
}