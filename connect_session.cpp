#include "connect_session.h"
#include "ui_connect_session.h"

connect_session::connect_session(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::connect_session)
{
    ui->setupUi(this);
}

connect_session::~connect_session()
{
    delete ui;
}
