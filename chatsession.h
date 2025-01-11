#ifndef CHATSESSION_H
#define CHATSESSION_H

#include <QMainWindow>

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

private:
    Ui::chatSession *ui;
};
#endif // CHATSESSION_H
