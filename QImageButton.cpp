#include "QImageButton.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QPainter>
#include <QStyleOption>

QImageButton::QImageButton(QWidget *parent, const QString image_path, const QString button_name, const int button_width, const int button_height, const int image_size) : QPushButton{parent} {
    QPixmap image(image_path);
    QIcon image_icon(image);

    this->image_path_ = image_path;
    this->image_size_ = image_size;
    this->image_ = image;
    this->image_icon_ = image_icon;
    this->button_name_ = button_name;

    setIcon(image_icon_);
    setIconSize(image_.scaled(image_size, image_size, Qt::IgnoreAspectRatio, Qt::FastTransformation).size());// scaledToWidth(image_width_, Qt::FastTransformation).size());
    setText(button_name_);
    setStyleSheet("QPushButton { color: black; background-color: #D5E8D4; font-family:Georgia; font-size: 25px; text-align: center; padding-left: 10px; padding-right: 10px; }");
    setFixedSize(button_width, button_height);
}
