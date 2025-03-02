#include "QtransitionWindow.h"
#include "ui_QTransitionWindow.h"

QTransitionWindow::QTransitionWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::QTransitionWindow) {
  ui->setupUi(this);
}

QTransitionWindow::~QTransitionWindow() { delete ui; }
