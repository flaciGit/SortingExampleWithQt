#ifndef CUSTOMDATA_H
#define CUSTOMDATA_H

#include <QVector>

struct CustomDataStruct
{
    QVector<QVector<int>> result;
    QVector<int> swapsDone;
};

class CustomData
{
public:
    CustomData();
    ~CustomData();
    void addData(QVector<int> currentData, int currentSwapsDone);
    CustomDataStruct getData();

private:
    CustomDataStruct *data;
};

#endif // CUSTOMDATA_H
