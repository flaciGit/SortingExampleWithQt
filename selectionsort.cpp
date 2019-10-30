#include "selectionsort.h"

#include<QDebug>

SelectionSort::SelectionSort(){}

void SelectionSort::swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

CustomData SelectionSort::doSort(QVector<int> arr)
{
    CustomData *resultData = new CustomData();
    int swapNumber = 1;

    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < arr.length() - 1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < arr.length(); j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;

        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
        resultData->addData(arr,swapNumber);
        swapNumber++;
    }

    qDebug() << "Did a Selection Sort!";

    return *resultData;
}

