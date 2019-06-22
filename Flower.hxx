//
// Created by ys on 2019/6/20.
//

#ifndef CMAKEQT_FLOWER_HXX
#define CMAKEQT_FLOWER_HXX

#include <QCoreApplication>
#include <QLabel>
#include <iostream>
#include <QDialog>
#include <QPushButton>
#include <QComboBox>
#include <QProgressBar>
#include <QToolBox>
#include <QTabWidget>
#include <QLineEdit>
#include <QStackedWidget>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QListWidget>
#include <QList>
#include <QMessageBox>
#include <QTableWidget>
#include <QTextEdit>
#include <QColorDialog>
#include <QFontDialog>
#include <QMainWindow>
#include <QMenuBar>
#include <QStatusBar>
#include <QToolBar>
#include "mydialog.h"
#include <QFileDialog>
#include <QColorDialog>
#include <QDebug>
#include <QFontDialog>
#include <QPainter>
#include <qmath.h>
#include <QMouseEvent>
#include <QPoint>
#include <QApplication>
#include <QDesktopWidget>
#include <QString>

class Rotation : public  QWidget
{
Q_OBJECT
private:
    QPushButton *rotation;
    int angle;



protected:
    void paintEvent(QPaintEvent *);
public slots:
    void rotate();
public:
    Rotation(QWidget *parent=0);


};




class Flower
{
public:
    int x;
    int y;
    int w, h;
    int vx, vy;
    int pos;
    int trans;
    bool draw;


    void init(int screenWidth, int screenHeight)
    {

        w = 10 + rand() % 50;
        h = w;
        x = rand() % screenWidth;
        y = -w;
        vx = -1 + rand()%3;
        vy = 3 + rand() %3;
        pos = rand()%3;
        trans = 2 + rand()%8;
        draw = true;
    }

    void start(int screenWidth, int screenHeight)
    {
        w = 10 + rand() % 50;
        h = w;
        x = rand() % screenWidth;
        y = rand() % screenHeight;
        vx = -1 + rand()%3;
        vy = 3 + rand() %3;
        pos = rand()%3;
        trans = 2 + rand()%8;
        draw = false;
    }

};


class FlowerFly : public QWidget
{
Q_OBJECT
private:
    Flower flower[200];
    QPoint mousePoint, ds;
    int ScreenWidth, ScreenHeight;
    int angle;


protected:
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *event);
    //void mouseMoveEvent(QMouseEvent *e);
    //void mouseReleaseEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);


public:
    FlowerFly(QWidget *parent=0);

};



class FramelessWindow : public QWidget
{
Q_OBJECT
protected:
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *event);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);


public:
    FramelessWindow(QWidget *parent=0);
};




#endif //CMAKEQT_FLOWER_HXX
