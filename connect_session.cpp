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
    delete msg;
    delete ui;
}

void connect_session::on_ok_btn_clicked()
{

    QByteArray ba = this->ui->ip_txt->text().toUtf8();
    char* msg_text = ba.data();
    msg->set_address(msg_text);

    int port_num = this->ui->port_txt->text().toInt();
    msg->set_port(port_num);

    if(ui->role_selector->currentText().toStdString() == "Server") {
        msg->setup_server();
    } else {
        msg->setup_client();
    }

    this->close();
}


void connect_session::on_cancel_btn_clicked()
{
    this->close();
}

void connect_session::set_message_server(message_server* msg) {
    this->msg = msg;
}

