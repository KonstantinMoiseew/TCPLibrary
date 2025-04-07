#pragma once
#include <iostream>
#include <QTcpServer>
#include <QTcpSocket>


class PolynomTcpServer : public QTcpServer
{
    Q_OBJECT

public:
    PolynomTcpServer(QObject parent = nullptr) : QTcpServer(parent), clientsocket(nullptr);

public slots:
    void sendToClient();

signals:
    void disconnected();


private slots:
    void handleNewConnection();

    void readFromClient();

    void clientDisconected();


private:
    QTcpSocket* clientsocket;
    SelectRequest request;


}
