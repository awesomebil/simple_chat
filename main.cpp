#include "chatsession.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    chatSession w;
    w.show();
    return a.exec();
}
