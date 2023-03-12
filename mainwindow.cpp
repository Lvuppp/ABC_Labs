#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    operation = new BinaryNumbersOperation();
   // QObject::connect(operation,SIGNAL(BinaryNumbersOperation::sendAnswerOfTwoBinaryNumbers(QString,bool)),
   //                  this,SLOT(MainWindow::getAnswer(QString,bool)));
    qDebug() << operation->SummaryOfTwoBinaryNumbers(40,23);
    qDebug() << operation->SubstractionOfTwoBinaryNumbers(-40,23);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getAnswer(QString answer, bool isOverflow)
{
    ui->label->setText(answer);

    if(isOverflow){
        ui->label_2->setText("Overflow");
    }
}

