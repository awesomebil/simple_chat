#include "chatsession.h"
#include "./ui_chatsession.h"

chatSession::chatSession(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::chatSession)
{
    ui->setupUi(this);
}

chatSession::~chatSession()
{
    delete ui;
}
