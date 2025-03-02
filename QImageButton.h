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
  explicit QImageButton(
      QWidget *parent = nullptr,
      std::shared_ptr<QImageButtonSettings> settings = nullptr);
  bool StartImageButton();

  void AttachToWindow(QTransitionWindow *window);

  void OpenWindow(QTransitionWindow *window);

private:
  std::shared_ptr<QImageButtonSettings>(settings_);
  QPixmap image_;
  QIcon image_icon_;

signals:
};

#endif // QIMAGEBUTTON_H
