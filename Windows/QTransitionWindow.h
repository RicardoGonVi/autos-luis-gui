#ifndef QTRANSITIONWINDOW_H
#define QTRANSITIONWINDOW_H

#include <QDialog>

namespace Ui {
class QTransitionWindow;
}

class QTransitionWindow : public QDialog
{
    Q_OBJECT

public:
    explicit QTransitionWindow(QWidget *parent = nullptr);
    ~QTransitionWindow();

private:
    Ui::QTransitionWindow *ui;
};

#endif // QTRANSITIONWINDOW_H
