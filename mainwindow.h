#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "bynarynumberoperation.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void getAnswer(QString,bool);

private:
    Ui::MainWindow *ui;
    BinaryNumbersOperation *operation;
};
#endif // MAINWINDOW_H
