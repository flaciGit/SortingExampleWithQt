#include "bubblesort.h"

#include<QDebug>

BubbleSort::BubbleSort(){}

void BubbleSort::swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
CustomData BubbleSort::doSort(QVector<int> arr)
{
    CustomData *resultData = new CustomData();
    int swapNumber = 1;

    int i, j;
    for (i = 0; i < arr.length() - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < arr.length() - i - 1; j++)
            if (arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
                resultData->addData(arr,swapNumber);
                swapNumber++;
            }

    qDebug() << "Did a Bubble Sort!";

    return *resultData;
}
