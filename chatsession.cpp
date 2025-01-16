#include "chatsession.h"
#include "./ui_chatsession.h"
// #include <iostream>

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


void chatSession::on_actionConnect_to_server_triggered()
{
    connect_dialog = new connect_session;
    connect_dialog->show();

    // std::cout << "Event triggered to show dialog window" << std::endl;
}

