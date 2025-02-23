#ifndef QIMAGEBUTTON_H
#define QIMAGEBUTTON_H

#include <QPushButton>

class QImageButton : public QPushButton {
    Q_OBJECT

public:
    explicit QImageButton(QWidget *parent = nullptr, const QString image_path = "../../images/none-image.png", const QString button_name = "", const int button_width = 240, const int button_height = 100, const int image_size = 60);

private:
    int image_size_;
    QPixmap image_;
    QIcon image_icon_;
    QString button_name_;
    QString image_path_;

signals:
};

#endif // QIMAGEBUTTON_H
