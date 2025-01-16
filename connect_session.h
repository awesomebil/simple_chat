#ifndef CONNECT_SESSION_H
#define CONNECT_SESSION_H

#include <QWidget>

namespace Ui {
class connect_session;
}

class connect_session : public QWidget
{
    Q_OBJECT

public:
    explicit connect_session(QWidget *parent = nullptr);
    ~connect_session();

private:
    Ui::connect_session *ui;
};

#endif // CONNECT_SESSION_H
