#include "QTransitionWindow.h"
#include "ui_QTransitionWindow.h"

QTransitionWindow::QTransitionWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::QTransitionWindow) {
  ui->setupUi(this);
}

void QTransitionWindow::AddButton(QPushButton *button) {
  ui->horizontalLayout->addWidget(button);
}

QTransitionWindow::~QTransitionWindow() { delete ui; }
