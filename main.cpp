#include <iostream>
#include <QApplication>
#include <QString>
#include <QDialog>
#include <QLabel>
#include "Exerc/Account.hxx"
#include "Exerc/Complex.hxx"
#include "Exerc/Point.hxx"

using namespace std;

#include <QLayout>
#include <QGridLayout>
#include <QDebug>
#include <QFormLayout>
#include "examSlot.hxx"

int main(int argc, char *argv[])
{


    QApplication a(argc, argv);

    Clock d;
    d.show();
    /*

    //布局
    QWidget w;
    QLineEdit *name = new QLineEdit;
    QLineEdit *email = new QLineEdit;
    QLineEdit *address = new QLineEdit;
    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow(Dialog::tr("&Name:"), name);
    formLayout->addRow(Dialog::tr("&Email:"), email);
    formLayout->addRow(Dialog::tr("&Address:"), address);
    //formLayout->setLabelAlignment(Qt::AlignRight);
    formLayout->setRowWrapPolicy(QFormLayout::WrapAllRows);
    w.setLayout(formLayout);
    cout << "hello" << endl;
    w.show();

     */

    /*QWidget w;
    //显示图片
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