#include "QFooterDisplayBar.h"
#include <QLabel>
#include <QVBoxLayout>

QFooterDisplayBar::QFooterDisplayBar(QWidget *parent,
                                     QFooterDisplayBarSettings *settings)
    : QWidget{parent}, settings_(settings) {}

bool QFooterDisplayBar::StartFooterDisplayBar() {
  bool error = false;

  if (settings_ == nullptr) {
    error = true;
    return error;
  }

  QLabel *status_label = new QLabel(this->settings_->footer_text);
  QString footer_style =
      "color: #" + this->settings_->text_color + "; background-color: #" +
      this->settings_->footer_color +
      "; font-family:" + this->settings_->text_font +
      "; font-size: " + QString::number(this->settings_->text_size) +
      "; "
      "padding: 0px;";
  QVBoxLayout *layout = new QVBoxLayout(this);

  /* Stilling the resultant widget */
  status_label->setStyleSheet(footer_style);
  status_label->setAlignment(Qt::AlignCenter);
  layout->addWidget(status_label);
  layout->setContentsMargins(0, 0, 0, 0);
  layout->setSpacing(0);

  setLayout(layout);

  return error;
}
