#include "QTransitionWindow.h"
#include "ui_QTransitionWindow.h"

QTransitionWindow::QTransitionWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::QTransitionWindow) {
  ui->setupUi(this);
  ui->horizontalLayout->setContentsMargins(0, 40, 0, 0);
}

void QTransitionWindow::AddButton(QPushButton *button) {
  ui->horizontalLayout->addWidget(button);
}

void QTransitionWindow::SetText(const QString text) {
  QFont font;

  font.setPointSize(40);
  font.setFamily("Georgia");
  font.setBold(true);
  ui->label->setMargin(25);
  ui->label->setText(text);
  ui->label->setFont(font);
}

QTransitionWindow::~QTransitionWindow() { delete ui; }
