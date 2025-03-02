#ifndef QIMAGEBUTTON_H
#define QIMAGEBUTTON_H

#include "Windows/QtransitionWindow.h"
#include <QPushButton>

struct QImageButtonSettings {
  int image_width = 60;
  int image_height = 60;
  int button_width = 240;
  int button_height = 100;
  QString image_path = "../../images/none-image.png";
  QString button_name = "";
  QString button_color = "FFFFFF";

  QImageButtonSettings(QString i_path = "../../images/none-image.png",
                       QString b_name = "", QString b_color = "FFFFFF")
      : image_path(i_path), button_name(b_name), button_color(b_color) {}
};

class QImageButton : public QPushButton {
  Q_OBJECT

public:
  /**
   * @brief QImageButton: QImageButton constructor
   *
   * @param: QWidget parent: Widget parent
   * @param: std::shared_ptr<QImageButtonSettings> settings: QImageButton
   * settings parameters
   */
  explicit QImageButton(
      QWidget *parent = nullptr,
      std::shared_ptr<QImageButtonSettings> settings = nullptr);

  /**
   * @brief StartImageButton: Starts a QImageButton when ran. Setting have to be
   * set before running this.
   *
   * @return: bool value indicating if an error was produced when running the
   * QImageButton
   */
  bool StartImageButton();

  /**
   * @brief AttachToWindow:  Attachs the QImageButton pushbutton action to a
   * Window. Opens the window when pushed.
   *
   * @param window: Receives the QTransitionWindow to attach the QImageButton
   * to.
   */
  void AttachToWindow(QTransitionWindow *window);

  /**
   * @brief OpenWindow: Opens a QTransitionWindow window.
   *
   * @param window: Receives the QTransitionWindow to be oppened.
   */
  void OpenWindow(QTransitionWindow *window);

private:
  std::shared_ptr<QImageButtonSettings>(settings_);

signals:
};

#endif // QIMAGEBUTTON_H
