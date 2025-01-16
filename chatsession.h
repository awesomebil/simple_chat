#ifndef CHATSESSION_H
#define CHATSESSION_H

#include <QMainWindow>
#include "connect_session.h"

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
    ~chatSession();

private slots:
    void on_actionConnect_to_server_triggered();

private:
    Ui::chatSession *ui;
    connect_session *connect_dialog;
};
#endif // CHATSESSION_H
