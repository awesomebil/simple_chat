#include "chatsession.h"
#include "./ui_chatsession.h"
// #include <iostream>

chatSession::chatSession(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::chatSession)
{
    ui->setupUi(this);
    connect_dialog = new connect_session;
}

chatSession::~chatSession()
{
    delete ui;
}


void chatSession::on_actionConnect_to_server_triggered()
{
    connect_dialog->show();

    // std::cout << "Event triggered to show dialog window" << std::endl;
}


void chatSession::on_sendButton_clicked()
{
    // Implement write to socket here.
    QByteArray ba = this->ui->send_txt->toPlainText().toUtf8();
    send_msg = ba.data();
    msg->send_data_to_network(send_msg);
}

message_server* chatSession::get_msg() {
    return msg;
}

void chatSession::set_msg(message_server* msg) {
    this->msg = msg;
    connect(msg, &message_server::message_received, this, &chatSession::display_message);
}

connect_session* chatSession::get_connect_session_dialog() {
    return this->connect_dialog;
}

void chatSession::display_message(const QString &message) {
    ui->msg_thread_txt->append(message);
}
