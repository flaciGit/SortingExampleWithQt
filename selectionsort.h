#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <QVector>
#include "customdata.h"

class SelectionSort
{

public:
    SelectionSort();

private:
    void swap(int *xp, int *yp);

public:
    //QVector<int> doSort(QVector<int> arr);
    CustomData doSort(QVector<int> arr);
};

#endif // SELECTIONSORT_H
