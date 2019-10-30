#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "selectionsort.h"
#include "bubblesort.h"
#include "customdata.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    void buildResultText(QString parsedInputString, int length, CustomDataStruct result);

    SelectionSort selectionSort;
    BubbleSort bubblesort;
};

#endif // MAINWINDOW_H
