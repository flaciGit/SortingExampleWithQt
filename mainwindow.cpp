#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // get numbers from first box
    QString textEditString = ui->inputField->toPlainText();

    QStringList numberStringList;
    numberStringList = textEditString.split(QRegExp("[\n]"),QString::SkipEmptyParts);

    // parse content to int
    QVector<int> numberVector;
    foreach(QString s, numberStringList){
        if(s.toInt())
            numberVector.append(s.toInt());
    }

    if(numberVector.length() < 2)
        return;

    QString parsedInputString;
    foreach(int n, numberVector){
        parsedInputString += QString::number(n) + " ";
    }
    ui->parsedField->setText(parsedInputString);

    // choose sort
    CustomDataStruct resultData;
    switch(ui->selectSort->currentIndex()){
        case 0:
            resultData = selectionSort.doSort(numberVector).getData();

            numberVector = resultData.result.last();

            buildResultText(parsedInputString, numberVector.length(), resultData);

            break;
        case 1:
            resultData = bubblesort.doSort(numberVector).getData();

            numberVector = resultData.result.last();

            buildResultText(parsedInputString, numberVector.length(), resultData);
            break;
        default:
            break;
    }

    // build output
    QString outputContent;
    foreach(int n, numberVector){
        outputContent += QString::number(n) + " ";
    }

    // set output
    ui->outputField->setText(outputContent);

}

void MainWindow::buildResultText(QString parsedInputString, int length, CustomDataStruct resultData)
{
    QString resultString;

    resultString +=  "Starting state:\t" + parsedInputString + "\tNumber of elements:\t" + QString::number(length) + "\n";

    for(int i = 0; i < resultData.result.length(); i++)
    {
    //foreach(QVector<int> i, resultData.result){
        QString localString;
        foreach(int n, resultData.result[i]){
            localString += QString::number(n) + " ";
        }

        resultString += "Actual state:\t" + localString + "\tNumber of swaps:\t" +  QString::number(resultData.swapsDone[i]) + "\n";

    }

    ui->resultText->setText(resultString);

}

