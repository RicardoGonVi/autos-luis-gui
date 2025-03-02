#include "QImageButton.h"

#include <QPixmap>

QImageButton::QImageButton(QWidget *parent,
                           std::shared_ptr<QImageButtonSettings> settings)
    : QPushButton{parent}, settings_(settings) {
  QPixmap image(settings->image_path);
  QIcon image_icon(image);

  this->image_ = image;
  this->image_icon_ = image_icon;
}

bool QImageButton::StartImageButton() {
  bool error = false;
  QString button_style =
      "QPushButton { color: black; background-color: #" +
      this->settings_->button_color +
      "; font-family: Georgia; font-size: 25px; text-align: center; "
      "padding: 10px; margin: 20px;}";

  if (settings_ == nullptr) {
    error = true;
    return error;
  }

  setIcon(this->image_icon_);
  setIconSize(image_
                  .scaled(this->settings_->image_height,
                          this->settings_->image_width, Qt::IgnoreAspectRatio,
                          Qt::FastTransformation)
                  .size());
  setText(this->settings_->button_name);
  setStyleSheet(button_style);
  setMinimumSize(this->settings_->button_width, this->settings_->button_height);
  setMaximumSize(this->settings_->button_width * 2,
                 this->settings_->button_height * 2);

  return error;
}

void QImageButton::AttachToWindow(QTransitionWindow *window) {
  connect(this, &QPushButton::clicked, this,
          [=]() { this->OpenWindow(window); });
}

void QImageButton::OpenWindow(QTransitionWindow *window) { window->show(); }
