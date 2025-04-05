#ifndef QFOOTERDISPLAYBAR_H
#define QFOOTERDISPLAYBAR_H

#include <QWidget>

struct QFooterDisplayBarSettings {
  int text_size;
  QString footer_text;
  QString footer_color;
  QString text_color;
  QString text_font;

  QFooterDisplayBarSettings(QString f_text = "", QString f_color = "3d3d3d",
                            QString t_color = "F0F0F0",
                            QString t_font = "Georgia", int t_size = 12)
      : footer_text(f_text), footer_color(f_color), text_color(t_color),
        text_font(t_font), text_size(t_size) {}
};

class QFooterDisplayBar : public QWidget {
  Q_OBJECT
public:
  explicit QFooterDisplayBar(QWidget *parent = nullptr,
                             std::shared_ptr<QFooterDisplayBarSettings> = nullptr);

  bool StartFooterDisplayBar();

private:
  std::shared_ptr<QFooterDisplayBarSettings> settings_;
signals:
};

#endif // QFOOTERDISPLAYBAR_H
