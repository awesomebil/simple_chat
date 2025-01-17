#include "chatsession.h"
#include "message_server.h"
#include <thread>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    chatSession w;

    message_server session;
    w.set_msg(&session);
    w.get_connect_session_dialog()->set_message_server(&session);

    w.show();
    w.get_connect_session_dialog()->show();
    return a.exec();
}
