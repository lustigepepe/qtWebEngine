#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>

//#include <QWebEngineView>
#include <QQmlApplicationEngine>
#include <qtwebengineglobal.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadTextFile();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString searchString = ui->lineEdit->text();
    ui->textEdit->find(searchString, QTextDocument::FindWholeWords);
}

void MainWindow::loadTextFile()
{
    QFile inputFile(":/input.txt");
    inputFile.open(QIODevice::ReadOnly);

    QTextStream in(&inputFile);
    QString line = in.readAll();
    inputFile.close();

    ui->textEdit->setPlainText(line);
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);

}

void MainWindow::on_pushButton_2_clicked()
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QtWebEngine::initialize();

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));


//    QWebEngineView view;
//    view.setUrl(QUrl(QStringLiteral("http://www.qt.io")));
//    view.resize(1024, 750);
//    view.show();
}
