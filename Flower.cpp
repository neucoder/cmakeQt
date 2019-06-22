//
// Created by ys on 2019/6/20.
//

#include "Flower.hxx"
#include <iostream>

using namespace std;

void FlowerFly::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    QPen pen;
    QPixmap pix, newimg;
    QMatrix rm;
    rm.rotate(-angle);



    for (int i = 0; i < 200; ++i)
    {
        if(flower[i].draw)
        {
            QString str = QString("img/flower%1.png").arg(flower[i].pos);
            //qDebug() << str ;
            pix.load(str);
            newimg = pix.scaled(flower[i].w, flower[i].h);
            painter.save();

            int mx = newimg.width() / 2;
            int my = newimg.height() / 2;
            painter.setOpacity(1.0 * flower[i].trans / 10);
            painter.translate(flower[i].x + mx, flower[i].y + my);
            painter.rotate(angle);
            painter.drawPixmap(0, 0, newimg.width(), newimg.height(), newimg);
            //painter.drawPixmap(x() + flower[i].x, y() + flower[i].y, newimg.width(), newimg.height(), newimg);

            painter.restore();
        }
    }

    //painter.drawRect(0,0,width()-1,height()-1);
}

void FlowerFly::timerEvent(QTimerEvent *event)
{
    QObject::timerEvent(event);
    if (angle >= 360*10)
    {
        angle = 0;
    }
    else
    {
        angle+=2;
    }

    for (int i = 0; i < 200; ++i)
    {
        flower[i].x += flower[i].vx;
        flower[i].y += flower[i].vy;
        if (flower[i].x < 0 -50- flower[i].w || flower[i].y > height() || flower[i].x > width())
        {
            flower[i].init(ScreenWidth, ScreenHeight);
        }

    }
    //repaint();
    update();
}

/*
void FlowerFly::mouseMoveEvent(QMouseEvent *e)
{
    QWidget::mouseMoveEvent(e);
}

void FlowerFly::mouseReleaseEvent(QMouseEvent *e)
{
    QWidget::mouseReleaseEvent(e);
    ds = e->pos() - mousePoint;
    move(pos() + ds);
}
*/
void FlowerFly::mousePressEvent(QMouseEvent *e)
{
    QWidget::mousePressEvent(e);


    if (e->button() == Qt::RightButton)
    {
        close();
    }

}

FlowerFly::FlowerFly(QWidget *parent) : QWidget(parent)
{


    QRect rec = QApplication::desktop()->screenGeometry();
    ScreenHeight = rec.height();
    ScreenWidth = rec.width();
    angle = 0;

    for (int i = 0; i < 200; ++i)
    {
        flower[i].start(ScreenWidth, ScreenHeight);
    }

//    for (int i = 0; i < 10; ++i)
//    {
//        cout << flower[i].x << " " << flower[i].y << " " << flower[i].w << " " << flower[i].h <<  endl;
//    }


    setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);

    setAttribute(Qt::WA_NoSystemBackground);
    setAttribute(Qt::WA_TranslucentBackground);
    //setAttribute(Qt::WA_PaintOnScreen);
    //setAttribute(Qt::WA_TransparentForMouseEvents);



    resize(ScreenWidth, ScreenHeight);
    move(0, 0);
    startTimer(15);

}


FramelessWindow::FramelessWindow(QWidget *parent) : QWidget(parent)
{

}

void FramelessWindow::paintEvent(QPaintEvent *)
{

}

void FramelessWindow::timerEvent(QTimerEvent *event)
{
    QObject::timerEvent(event);
}

void FramelessWindow::mouseMoveEvent(QMouseEvent *e)
{
    QWidget::mouseMoveEvent(e);
}

void FramelessWindow::mouseReleaseEvent(QMouseEvent *e)
{
    QWidget::mouseReleaseEvent(e);
}

void FramelessWindow::mousePressEvent(QMouseEvent *e)
{
    QWidget::mousePressEvent(e);
}

Rotation::Rotation(QWidget *parent) : QWidget(parent)
{
    rotation = new QPushButton("rotation", this);
    rotation->setGeometry(20, 20, 80, 20);
    angle = 10;
    resize(400, 300);
    connect(rotation, SIGNAL(clicked()), this, SLOT(rotate()));

}

void Rotation::rotate()
{
    angle += 10;
    cout << "rotate:" << angle << endl;
    update();
}

void Rotation::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    QPixmap img, newimg;
    img.load("flower.png");
    QMatrix rm;
    rm.rotate(-angle);
    newimg = img.transformed(rm);
    painter.drawPixmap(20, 60, img.width(), img.height(), newimg);

    cout << "paint:" << angle << endl;

}
