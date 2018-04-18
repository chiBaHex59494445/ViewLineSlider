#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "GraphicsViewSlider/customgraphicsview.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setItemWidth(10);
    ui->graphicsView->setLinePixelSize(3);
}

MainWindow::~MainWindow()
{
    delete ui;
}
