#ifndef QTRANSITIONWINDOW_H
#define QTRANSITIONWINDOW_H

#include <QDialog>
#include <QPushButton>

namespace Ui {
class QTransitionWindow;
}

class QTransitionWindow : public QDialog {
  Q_OBJECT

public:
  /**
   * @brief QTransitionWindow:  QTransitionWindow class constructor.
   */
  explicit QTransitionWindow(QWidget *parent = nullptr);

  /**
   * @brief ~QTransitionWindow: QTransitionWindow class destructor
   */
  ~QTransitionWindow();

  /**
   * @brief AddButton: QTransitionWindow method that allows adding a button to
   * it.
   * @param button: Adds button to the horizontal layout.
   */
  void AddButton(QPushButton *button);

private:
  /**
   * @brief ui: user interface window
   */
  Ui::QTransitionWindow *ui;
};

#endif // QTRANSITIONWINDOW_H
