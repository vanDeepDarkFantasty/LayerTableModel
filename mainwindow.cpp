#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "layeritemdelegate.h"
#include "layertablemodel.h"
#include "layertableview.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap *pixmap = new QPixmap(50, 50);
    pixmap->fill("red");
    LayerTableView *view = new LayerTableView;
   //view->addNewLayer();
    //view->model->addItem("student", );

    setCentralWidget(view);
}

MainWindow::~MainWindow()
{
    delete ui;
}
