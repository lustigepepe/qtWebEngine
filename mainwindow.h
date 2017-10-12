#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "document.h"

#include <QMainWindow>
#include <QtCore/QFileInfo>
#include <QtCore/QUrl>

class Utils : public QObject {
    Q_OBJECT
public:
    Q_INVOKABLE static QUrl fromUserInput(const QString& userInput);
};

inline QUrl Utils::fromUserInput(const QString& userInput)
{
    QFileInfo fileInfo(userInput);
    if (fileInfo.exists())
        return QUrl::fromLocalFile(fileInfo.absoluteFilePath());
    return QUrl::fromUserInput(userInput);
}

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    void loadTextFile();
    Document m_content;
};

#endif // MAINWINDOW_H
