#include <iostream>
#include <QApplication>
#include <QString>
#include <QDialog>
#include <QLabel>
#include "Exerc/Account.hxx"
#include "Exerc/Complex.hxx"
#include "Exerc/Point.hxx"
using namespace std;

#include <QDebug>
#include "examSlot.hxx"
int main(int argc, char *argv[])
{




    QApplication a(argc, argv);

    FileDialog w;
    cout << "hello" << endl;
    w.show();
    /*QWidget w;

    w.setGeometry(300, 300, 500, 500);
    QLabel *label = new QLabel(&w);
    label->setText("Label");
    label->setGeometry(10,10,50,50);
    label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QLabel *pTag = new QLabel(&w);
    QImage image("/home/ys/Pictures/aa.png");
    pTag->setPixmap(QPixmap::fromImage(image));
    pTag->setGeometry(60,60,image.width(), image.height());

    w.show();*/
    return a.exec();


    return 0;
}