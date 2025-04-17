#include "window.h"
#include "./ui_window.h"
#include "QFooterDisplayBar.h"
#include "QImageButton.h"

/* Color definitions */
#define GREEN "D5E8D4"
#define ORANGE "FFE6CC"
#define BLUE "B1DDF0"
#define PINK "F9F7ED"

Window::Window(QWidget *parent) : QMainWindow(parent), ui(new Ui::Window) {

  /* Images paths */
  QString search_image = "../../images/searcher-magnifying-glass.png";
  QString add_image = "../../images/add.png";
  QString sell_image = "../../images/sell.png";
  QString list_image = "../../images/list.png";
  QString car_image = "../../images/car.png";
  QString person_image = "../../images/person.png";
  QString mechanic_image = "../../images/mechanic.png";

  /* Button names */
  QString search_IB_name = "BUSCAR";
  QString add_IB_name = "AGREGAR";
  QString sell_IB_name = "VENDER";
  QString list_IB_name = "LISTAR";
  QString search_window_car_IB_name = "VEHÍCULOS";
  QString search_window_lawyer_IB_name = "ABOGADOS";
  QString search_window_client_IB_name = "CLIENTES";
  QString search_window_mechanic_IB_name = "MECÁNICOS";
  QString search_window_owner_IB_name = "DUEÑOS";

  /* Window label */
  QString search_window_label = "¿Qué desea buscar?";

  /* Footer label */
  QString footer_label = "CARROS DISPONIBLES: XXXX  |   GNC: YYYY  |   EN "
                         "TALLER: ZZZ  |  RESERVADOS: AA ";

  /* Settings */
  std::shared_ptr<QImageButtonSettings> search_settings =
      std::make_shared<QImageButtonSettings>(search_image, search_IB_name,
                                             GREEN);
  std::shared_ptr<QImageButtonSettings> add_settings =
      std::make_shared<QImageButtonSettings>(add_image, add_IB_name, ORANGE);
  std::shared_ptr<QImageButtonSettings> sell_settings =
      std::make_shared<QImageButtonSettings>(sell_image, sell_IB_name, BLUE);
  std::shared_ptr<QImageButtonSettings> list_settings =
      std::make_shared<QImageButtonSettings>(list_image, list_IB_name, PINK);
  std::shared_ptr<QImageButtonSettings> search_window_car_IB_settings =
      std::make_shared<QImageButtonSettings>(car_image,
                                             search_window_car_IB_name);
  std::shared_ptr<QImageButtonSettings> search_window_lawyer_IB_settings =
      std::make_shared<QImageButtonSettings>(person_image,
                                             search_window_lawyer_IB_name);
  std::shared_ptr<QImageButtonSettings> search_window_client_IB_settings =
      std::make_shared<QImageButtonSettings>(person_image,
                                             search_window_client_IB_name);
  std::shared_ptr<QImageButtonSettings> search_window_mechanic_IB_settings =
      std::make_shared<QImageButtonSettings>(mechanic_image,
                                             search_window_mechanic_IB_name);
  std::shared_ptr<QImageButtonSettings> search_window_owner_IB_settings =
      std::make_shared<QImageButtonSettings>(person_image,
                                             search_window_owner_IB_name);

  std::shared_ptr<QFooterDisplayBarSettings> footer_settings =
      std::make_shared<QFooterDisplayBarSettings>(footer_label);

  /* ImageButton definitions */
  QImageButton *search_IB = new QImageButton(this, search_settings);
  QImageButton *add_IB = new QImageButton(this, add_settings);
  QImageButton *sell_IB = new QImageButton(this, sell_settings);
  QImageButton *list_IB = new QImageButton(this, list_settings);
  QImageButton *search_window_car_IB =
      new QImageButton(this, search_window_car_IB_settings);
  QImageButton *search_window_lawyer_IB =
      new QImageButton(this, search_window_lawyer_IB_settings);
  QImageButton *search_window_client_IB =
      new QImageButton(this, search_window_client_IB_settings);
  QImageButton *search_window_mechanic_IB =
      new QImageButton(this, search_window_mechanic_IB_settings);
  QImageButton *search_window_owner_IB =
      new QImageButton(this, search_window_owner_IB_settings);

  /* Transition Window definitions */
  QTransitionWindow *search_window = new QTransitionWindow();
  QTransitionWindow *add_window = new QTransitionWindow();
  QTransitionWindow *sell_window = new QTransitionWindow();
  QTransitionWindow *list_window = new QTransitionWindow();

  /* Footer Display Bar definition */
  QFooterDisplayBar *footer = new QFooterDisplayBar(this, footer_settings);

  /* Starting ImageButtons */
  /* Main window buttons */
  search_IB->StartImageButton();
  add_IB->StartImageButton();
  sell_IB->StartImageButton();
  list_IB->StartImageButton();

  /* Search window buttons */
  search_window_car_IB->StartImageButton();
  search_window_lawyer_IB->StartImageButton();
  search_window_client_IB->StartImageButton();
  search_window_mechanic_IB->StartImageButton();
  search_window_owner_IB->StartImageButton();

  /* Attaching ImageButtons */
  search_IB->AttachToWindow(search_window);
  add_IB->AttachToWindow(add_window);
  sell_IB->AttachToWindow(sell_window);
  list_IB->AttachToWindow(list_window);

  /* Adding Buttons to Transition windows */
  search_window->SetText(search_window_label);

  search_window->AddButton(search_window_car_IB);
  search_window->AddButton(search_window_lawyer_IB);
  search_window->AddButton(search_window_client_IB);
  search_window->AddButton(search_window_mechanic_IB);
  search_window->AddButton(search_window_owner_IB);

  /* Starting Footer Display Bar */
  footer->StartFooterDisplayBar();

  /* Main Interface Setup */
  ui->setupUi(this);
  ui->horizontalLayout->addWidget(search_IB);
  ui->horizontalLayout->addWidget(add_IB);
  ui->horizontalLayout->addWidget(sell_IB);
  ui->horizontalLayout->addWidget(list_IB);

  /* Status Bar */
  ui->statusbar->addPermanentWidget(footer, 1);
}

Window::~Window() { delete ui; }
