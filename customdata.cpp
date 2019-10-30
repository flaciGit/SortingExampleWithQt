#include "customdata.h"

CustomData::CustomData()
{
    data = new CustomDataStruct();
}

CustomData::~CustomData()
{
    delete data;
}

void CustomData::addData(QVector<int> currentData, int currentSwapsDone)
{
    data->result.append(currentData);
    data->swapsDone.append(currentSwapsDone);
}

CustomDataStruct CustomData::getData()
{
    return *data;
}
