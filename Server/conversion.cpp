#include "conversion.h"

 
SelectRequest deserialize(byteArray &in)
{
     SelectRequest request;
     QDataStream in(byteArray);

     qint32 listSize;
     in >> listSize;
     request.list.resize(listSize);
     for (qint32 i = 0; i < listSize; ++i) {
        int enumInt;
        in >> enumInt; // Read as int first
        request.list[i] = static_cast<MyEnum>(enumInt); // Cast back to enum
    }

    in >> request.location >> request.storageId >> request.accessToken >> request.useApplicability;

    return requst;

}
