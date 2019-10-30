#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <QVector>
#include "customdata.h"

class BubbleSort
{
public:
    BubbleSort();

private:
    void swap(int *xp, int *yp);

public:
    //QVector<int> doSort(QVector<int> arr);
    CustomData doSort(QVector<int> arr);
};

#endif // BUBBLESORT_H
