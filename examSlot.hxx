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

#include <QListWidget>

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

    QTab(QWidget *parent=0);
    ~QTab(){};
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

    int count=0;
public slots:
    void onChanged(int index);
    void setLabelText(int pos);
    void startProgress();
    void resetProcess();


public:

    Dialog(QWidget *parent=0);
    ~Dialog() { delete  label;};
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
    { }

public slots:
    void Function(int value)
    {
        std::cout << "new value = "  << value << std::endl;
    };
};

void testSSlots();

#endif //CMAKEQT_EXAMSLOT_HXX
