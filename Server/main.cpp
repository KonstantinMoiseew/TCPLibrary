#include <QApplication>
#include "tcpserver.h"
#include "conversion.h"

main(int argc, char *argv[])
{
    QApplication app;
    PolynomTcpServer server;


    app.exec();
}
