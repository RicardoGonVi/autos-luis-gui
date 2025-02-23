#include "window.h"
#include "./ui_window.h"
#include "QImageButton.h"

Window::Window(QWidget *parent) : QMainWindow(parent),  ui(new Ui::Window) {
    QString search_IB_path = "../../images/searcher-magnifying-glass.png";
    QString search_IB_name= "BUSCAR";
    QImageButton *search_IB = new QImageButton(this, search_IB_path, search_IB_name);

    QString add_IB_path = "../../images/add.png";
    QString add_IB_name= "AGREGAR";
    QImageButton *add_IB = new QImageButton(this, add_IB_path, add_IB_name);

    QString sell_IB_path = "../../images/sell.png";
    QString sell_IB_name= "VENDER";
    QImageButton *sell_IB = new QImageButton(this, sell_IB_path, sell_IB_name);

    QString list_IB_path = "../../images/list.png";
    QString list_IB_name= "LISTAR";
    QImageButton *list_IB = new QImageButton(this, list_IB_path, list_IB_name);

    ui->setupUi(this);
    ui->horizontalLayout->addWidget(search_IB);
    ui->horizontalLayout->addWidget(add_IB);
    ui->horizontalLayout->addWidget(sell_IB);
    ui->horizontalLayout->addWidget(list_IB);
}

Window::~Window()
{
    delete ui;
}
