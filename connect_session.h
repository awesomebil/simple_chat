#ifndef CONNECT_SESSION_H
#define CONNECT_SESSION_H

#include <QWidget>
#include "message_server.h"

namespace Ui {
class connect_session;
}

class connect_session : public QWidget
{
    Q_OBJECT

public:
    explicit connect_session(QWidget *parent = nullptr);
    void set_message_server(message_server*);
    ~connect_session();

private slots:
    void on_ok_btn_clicked();

    void on_cancel_btn_clicked();

private:
    Ui::connect_session *ui;
    message_server *msg;
};

#endif // CONNECT_SESSION_H
