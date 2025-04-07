#pragma once

#include <QByteArray>
#include <QDataStream>

enum SelectPolynomObjectTypes : int {

        // Без типа.
        None = 0,

        // Элемент.
        Element = 4,

        // Группа.
        ElementGroup = 39,

        // Каталог.
        ElementCatalog = 40,

        // Справочник.
        Reference = 48,

        // Каталог документов.
        DocumentCatalog = 69,

        // Группа документов.
        DocumentGroup = 70,

        // Документ.
        Document = 71,

        // Файл.
        File = 72,

        // Каталог представлений.
        ViewpointCatalog = 91,

        // Группа представлений.
        ViewpointGroup = 92,

        // Представление.
        Viewpoint = 93,

        // Заявка
        Ticket = 218
};


class SelectRequest
{
public:

        //Фильтр идентификаторов типов объектов ПОЛИНОМ:MDM подлежащих выбору.
        QList<SelectPolynomObjectTypes> filterTypeIds;


        //Строка расположение объекта который требуется выбрать при открытии.
        QString location;


        //Идентификатор хранилища.
        QString storageId;


        //Токен доступа к ПОЛИНОМ:MDM.
        QString accessToken;


        //Признак учета применяемости.
        bool useApplicability;
};

SelectRequest deserialize(byteArray &in);
