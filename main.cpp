#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "TableModel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    TableModel *tableModel = new TableModel(":/data.txt");
    if(!tableModel->load()) return 1;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("tmodel", tableModel);
    engine.load(QUrl("qrc:/main.qml"));

    return app.exec();
}

