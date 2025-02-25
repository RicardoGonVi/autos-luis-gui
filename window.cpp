#include "window.h"
#include "./ui_window.h"
#include "QImageButton.h"

Window::Window(QWidget *parent) : QMainWindow(parent), ui(new Ui::Window) {
  /* Search button */
  QString search_IB_path = "../../images/searcher-magnifying-glass.png";
  QString search_IB_name = "BUSCAR";
  QString search_IB_bg_color = "D5E8D4";
  std::shared_ptr<QImageButtonSettings> search_settings =
      std::make_shared<QImageButtonSettings>(search_IB_path, search_IB_name,
                                             search_IB_bg_color);
  QImageButton *search_IB = new QImageButton(this, search_settings);
  QTransitionWindow *search_window = new QTransitionWindow();

  /* Add button */
  QString add_IB_path = "../../images/add.png";
  QString add_IB_name = "AGREGAR";
  QString add_IB_bg_color = "FFE6CC";
  std::shared_ptr<QImageButtonSettings> add_settings =
      std::make_shared<QImageButtonSettings>(add_IB_path, add_IB_name,
                                             add_IB_bg_color);
  QImageButton *add_IB = new QImageButton(this, add_settings);
  QTransitionWindow *add_window = new QTransitionWindow();

  /* Sell button */
  QString sell_IB_path = "../../images/sell.png";
  QString sell_IB_name = "VENDER";
  QString sell_IB_bg_color = "B1DDF0";
  std::shared_ptr<QImageButtonSettings> sell_settings =
      std::make_shared<QImageButtonSettings>(sell_IB_path, sell_IB_name,
                                             sell_IB_bg_color);
  QImageButton *sell_IB = new QImageButton(this, sell_settings);
  QTransitionWindow *sell_window = new QTransitionWindow();

  /* List button */
  QString list_IB_path = "../../images/list.png";
  QString list_IB_name = "LISTAR";
  QString list_IB_bg_color = "F9F7ED";
  std::shared_ptr<QImageButtonSettings> list_settings =
      std::make_shared<QImageButtonSettings>(list_IB_path, list_IB_name,
                                             list_IB_bg_color);
  QImageButton *list_IB = new QImageButton(this, list_settings);
  QTransitionWindow *list_window = new QTransitionWindow();

  /* Starting ImageButtons */
  search_IB->StartImageButton();
  add_IB->StartImageButton();
  sell_IB->StartImageButton();
  list_IB->StartImageButton();

  /* Attaching ImageButtons */
  search_IB->AttachToWindow(search_window);
  add_IB->AttachToWindow(add_window);
  sell_IB->AttachToWindow(sell_window);
  list_IB->AttachToWindow(list_window);

  /* Main Interface Setup */
  ui->setupUi(this);
  ui->horizontalLayout->addWidget(search_IB);
  ui->horizontalLayout->addWidget(add_IB);
  ui->horizontalLayout->addWidget(sell_IB);
  ui->horizontalLayout->addWidget(list_IB);

  /* Main Interface Setup */
  ui->setupUi(this);
  ui->horizontalLayout->addWidget(search_IB);
  ui->horizontalLayout->addWidget(add_IB);
  ui->horizontalLayout->addWidget(sell_IB);
  ui->horizontalLayout->addWidget(list_IB);

  /* Status Bar */
  // ui->statusbar->showMessage("CARROS DISPONIBLES: XXXX  |   GNC: YYYY  |   EN
  // TALLER: ZZZ  |  RESERVADOS: AA ");
  QLabel *statusLabel = new QLabel("CARROS DISPONIBLES: XXXX  |   GNC: YYYY  | "
                                   "  EN TALLER: ZZZ  |  RESERVADOS: AA ");
  statusLabel->setAlignment(Qt::AlignCenter); // Center the text
  statusLabel->setStyleSheet("color: #000000; background-color: #769BD1; "
                             "font-family: Georgia; font-size: 14px;");
  ui->statusbar->addPermanentWidget(statusLabel, 1); // The '1' makes it expand
}

Window::~Window() { delete ui; }
