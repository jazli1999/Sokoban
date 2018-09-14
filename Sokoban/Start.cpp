#include "Start.h"

Start::Start() {
  QPushButton *log = new QPushButton("Log in");
  QPushButton *sign = new QPushButton("Sign up");
  QPushButton *exit = new QPushButton("Exit");

  QVBoxLayout *options = new QVBoxLayout;
  options->addWidget(log);
  options->addWidget(sign);
  options->addWidget(exit);


  /*log->setIcon(QIcon("Resources\\ButtonNormal.png"));
  log->setIconSize(QSize(buttonH1,buttonW1));*/


 /* setButtonStyle(log);
  setButtonStyle(sign);
  setButtonStyle(exit);*/

  setWindowTitle("Account");

  QObject::connect(log, SIGNAL(clicked()), this, SLOT(logIn()));
  QObject::connect(sign, SIGNAL(clicked()), this, SLOT(signUp()));
  QObject::connect(exit, SIGNAL(clicked()), this, SLOT(close()));

  setFixedHeight(height);
  setFixedWidth(width);

  log->setFixedHeight(buttonH1);
  log->setFixedWidth(buttonW1);
  sign->setFixedHeight(buttonH1);
  sign->setFixedWidth(buttonW1);
  exit->setFixedHeight(buttonH1);
  exit->setFixedWidth(buttonW1);

  options->setAlignment(Qt::AlignHCenter);
  setLayout(options);

  setAutoFillBackground(true);
  QPalette* backGround = new QPalette;
  backGround->setBrush(QPalette::Background, QBrush(QPixmap("Resources//StartWall.jpg")));
  setPalette(*backGround);
}

Start::~Start() {

}

void Start::logIn() {
  logUser = new Users(LogIn);
  logUser->show();
  QObject::connect(logUser, SIGNAL(closeSignal()), this, SLOT(play()));
  QObject::connect(logUser, SIGNAL(sendsignal()), this, SLOT(show()));
  this->hide();
}

void Start::signUp() {
  signUser = new Users(SignUp);
  QObject::connect(signUser, SIGNAL(closeSignal()), this, SLOT(play()));
  QObject::connect(signUser, SIGNAL(sendsignal()), this, SLOT(show()));
  signUser->show();
  this->hide();
}

void Start::play() {
  Game* game = new Game;
  game->show();
}


/*void Start::setButtonStyle(QPushButton* button) {
  button->setStyleSheet("QPushButton{background-image:/Resources/ButtonNormal.png)}"
    "QPushButton:hover{border-image: url(:/Resources/ButtonHover.png)}"
    "QPushButton:pressed{border-image: url(:/Resources/ButtonPressed.png)}");
}*/