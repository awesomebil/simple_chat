#ifndef CHATSESSION_H
#define CHATSESSION_H

#include <QMainWindow>
#include "connect_session.h"
#include "message_server.h"
#include <thread>

QT_BEGIN_NAMESPACE
namespace Ui {
class chatSession;
}
QT_END_NAMESPACE

class chatSession : public QMainWindow
{
    Q_OBJECT

public:
    chatSession(QWidget *parent = nullptr);
    message_server* get_msg();
    void set_msg(message_server*);
    connect_session* get_connect_session_dialog();
    ~chatSession();

private slots:
    void on_actionConnect_to_server_triggered();
    void on_sendButton_clicked();
    void display_message(const QString&);

private:
    Ui::chatSession *ui;
    connect_session *connect_dialog;
    message_server *msg;
    char* send_msg;
};
#endif // CHATSESSION_H
