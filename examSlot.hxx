//
// Created by ys on 19-6-16.
//

#ifndef CMAKEQT_EXAMSLOT_HXX
#define CMAKEQT_EXAMSLOT_HXX

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


class Clock : public QWidget
{
private:
    float radius;
    int xSecond, ySecond, xMinute, yMinute, xHour, yHour;
    int xCenter, yCenter;
    int second, minute, hour;
    void CalcPosition();
    QPushButton *closeBtn;
    bool isMouseDown = false;
    QPoint mousePoint, ds;


protected:
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *event);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);


public:
    Clock(QWidget *parent=0);

};

//二维绘图系统
class Draw : public QWidget
{

protected:
    void paintEvent(QPaintEvent *);

public:

};



//标准对话框

class FileDialog : public QDialog
{
Q_OBJECT
private:
    QLabel *label;
    QPushButton *btn;
    QPushButton *colorBtn;
    QPushButton *fontBtn;
    QPushButton *Message1;
    QPushButton *Message2;
    QPushButton *Message3;
    QPushButton *Message4;
    QPushButton *Message5;
public:
    FileDialog(QWidget *parent = 0);

    ~FileDialog()
    {}

public slots:

    void slotOpenFileDlg();

    void slotColor();

    void fontDlg();

    void message1();

    void message2();

    void message3();

    void message4();

    void message5();
};


//菜单和工具栏
class MainWindow : public QMainWindow
{
Q_OBJECT
private:
    QAction *openAction;
    QAction *setAction;
public:
    MainWindow(QWidget *parent = 0);

    ~MainWindow()
    {}

public slots:

    void open();

    void setting();
};


//富文本控件

class RichText : public QWidget
{
Q_OBJECT
private:
    QPushButton *colorBtn;
    QPushButton *fontBtn;
    QTextEdit *edit;

public:
    RichText(QWidget *parent = 0);

    ~RichText()
    {}

public slots:

    void clickedColorButton();

    void clickedFontButton();


};

//表格控件

class TableWidget : public QWidget
{
public:
    TableWidget(QWidget *parent = 0);

    ~TableWidget()
    {}
};


//树状控件

class TreeWidget : public QDialog
{
Q_OBJECT
private:
    QTreeWidget *tree;

public:
    TreeWidget(QWidget *parent = 0);

    ~TreeWidget()
    {};

public slots:

    void item_Dblclicked(QTreeWidgetItem *item, int column);

};


//层叠窗体
class QStackW : public QDialog
{
Q_OBJECT

private:

public slots:

public:
    QStackW(QWidget *parent = 0);

};

//选项卡效果
class QTab : public QDialog
{
Q_OBJECT

private:
    QTabWidget *tabWidget;
public slots:


public:

    QTab(QWidget *parent = 0);

    ~QTab()
    {};
};


class Dialog : public QDialog
{
Q_OBJECT

private:
    QLabel *label;
    QPushButton *btn, *btn1;
    QComboBox *comBox;
    QSlider *slider;
    QLabel *sliLabel;

    //进度条
    QLabel *fileNum;
    QProgressBar *bar;
    QPushButton *startBtn;
    QPushButton *stopBtn;

    //抽屉效果
    QToolBox *toolBox;

    int count = 0;
public slots:

    void onChanged(int index);

    void setLabelText(int pos);

    void startProgress();

    void resetProcess();

    void changeValue();

signals:

    void sentValue(QString str);

public:

    Dialog(QWidget *parent = 0);

    ~Dialog()
    { delete label; };
};


class ExamA : public QObject
{
Q_OBJECT

public:
    ExamA()
    { Value = 0; }

    void setValue(int NewVal)
    {
        if (NewVal == Value)
        {
            return;
        }
        Value = NewVal;
        emit stateChanged(Value);
    }

signals:

    void stateChanged(int Value);


private:
    int Value;
};


class ExamB : public QObject
{

Q_OBJECT

public:
    ExamB()
    {}

public slots:

    void Function(int value)
    {
        std::cout << "new value = " << value << std::endl;
    };
};

void testSSlots();

#endif //CMAKEQT_EXAMSLOT_HXX
