#include "mainwindow.h"
//#include <QApplication>

#ifndef QT_NO_WIDGETS
#include <QtWidgets/QApplication>
typedef QApplication Application;
#else
//#include <QtGui/QGuiApplication>
//typedef QGuiApplication Application;
#endif



#include <QtQml/QQmlApplicationEngine>
#include <QtQml/QQmlContext>
#include <QtWebEngine/qtwebengineglobal.h>

static QUrl startupUrl()
{
    QUrl ret;
    QStringList args(qApp->arguments());
    args.takeFirst();
    Q_FOREACH (const QString& arg, args) {
        if (arg.startsWith(QLatin1Char('-')))
             continue;
        ret = Utils::fromUserInput(arg);
        if (ret.isValid())
            return ret;
    }
    return QUrl(QStringLiteral("http://qt.io/"));
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    w.show();

    QtWebEngine::initialize();
    QQmlApplicationEngine appEngine;
    Utils utils;
    appEngine.rootContext()->setContextProperty("utils", &utils);

    appEngine.load(QUrl("qrc:/main.qml"));
    QMetaObject::invokeMethod(appEngine.rootObjects().first(), "load", Q_ARG(QVariant, startupUrl()));


    return app.exec();
}
