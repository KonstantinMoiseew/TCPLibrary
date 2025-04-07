#include "tcpserver.h"
#include "conversion.h"
#include <QDebug>
PolynomTcpServer::PolynomTcpServer(QObject* parent) : QTcpServer(parent), clientSocket(nullptr)
{
    if(this->listen(QHostAddress::LocalHost, 0))
    {
        qDebug() << "Server started on port: " << this->serverPort();
        cout << this->serverPort(); //pass Port to the client
    }

    else
    {
        qDebug() << "Server failed to stert";
    }
    qObject::connect(this, &QTcpServer::newConnection, this, &MyTcpServer::handleNewConnection);
}

void PolynomTcpServer::handleNewConnection()
{
    if(clientsocket)
    {
        qDebug() << "Another connection attempting to connect, but one connection's alredy been established";
        QTcpSocket* rejectsocket = nextPendingConnection();
        rejectsocket->disconnectFromHost();
        return;
    }

    else
    {
        clientsocket = nextPendingConnection();
        qDebug() << "Client conected";

        QObject::connect(clientsocket, &QTcpSocket::readyRead, this, &MyTcpServer::readFromClient);
        QObject::connect(clientsocket, &QTcpSocket::disconnected, this, &MyTcpServer::clientDisconected);
    }
}

void PolynomTcpServer::clientDisconected()
{
    qDebug() << "Client disconnected.";
    clientSocket->deleteLater(); // Clean up the socket
    clientSocket = nullptr; // Reset the pointer

    emit disconnected();
}

void PolynomTcpServer::readFromClient()
{
    QByteArray data = clientsocket->readAll(); // Read all available data
    qDebug() << "PolynomTcpServer received data: " << data;
    requst = deserialize(data);
}

void PolynomTcpServer::sendToClient()
{
    //clientSocket->write
}

