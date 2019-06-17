//
// Created by ys on 19-6-16.
//

#include <QtWidgets/QMessageBox>
#include "examSlot.hxx"
#include <QThread>


void testSSlots()
{
    ExamA a;
    ExamB b;
    QObject::connect(&a, SIGNAL(stateChanged(int)), &b, SLOT(Function(int)));
    a.setValue(100);
}

Dialog::Dialog(QWidget *parent) : QDialog(parent)
{
    resize(300, 300);

    QIcon icon1("/home/ys/Pictures/play.ico");

    label = new QLabel("label", this);
    btn = new QPushButton("click",this);
    btn1 = new QPushButton("show", this);
    btn->setIcon(icon1);
    btn->setFlat(true);
    btn->setText("click");
    btn->setGeometry(20,20,40,16);
    btn->setCheckable(true);
    btn1->setGeometry(80, 20, 40, 16);
    label->setGeometry(160, 20, 40, 16);
    count = 0;
    //复选框
    comBox = new QComboBox(this);
    comBox->setGeometry(20, 60, 100,20);
    comBox->addItem("ftp");
    comBox->addItem("www");

    //滑动条
    slider = new QSlider(Qt::Horizontal, this);
    slider->setMinimum(0);
    slider->setMaximum(300);
    slider->setValue(50);
    slider->update();

    sliLabel = new QLabel(this);
    QFont font;
    font.setFamily(QStringLiteral("Arial"));
    font.setPointSize(14);
    sliLabel->setFont(font);
    sliLabel->setAlignment(Qt::AlignHCenter);
    sliLabel->setText("50");
    sliLabel->setGeometry(20, 100, 50, 20);
    slider->setGeometry(80, 100, 200, 20);


    //进度条
    fileNum = new QLabel(this);
    fileNum->setText(tr("复制文件数目:0"));
    fileNum->setGeometry(20, 140, 200, 18);

    bar = new QProgressBar(this);
    bar->setGeometry(120, 180, 200, 20);
    startBtn = new QPushButton(this);
    startBtn->setText(tr("开始"));
    startBtn->setGeometry(20, 180, 40, 20);
    stopBtn = new QPushButton(this);
    stopBtn->setText(tr("重置"));
    stopBtn->setGeometry(70, 180, 40, 20);


    //抽屉效果


    toolBox = new QToolBox(this);

    QWidget *tBW1 = new QWidget(toolBox);
    QPushButton *tBBtn1 = new QPushButton("wind", tBW1);
    QPushButton *tBBtn2 = new QPushButton("cake", tBW1);

    tBW1->setGeometry(0, 220, 40, 40);
    tBBtn1->setGeometry(5, 5, 40, 20);
    tBBtn2->setGeometry(5, 30, 40, 20);
    //向qtoolbox中添加第一个抽屉
    toolBox->addItem(tBW1,"friend");

    //添加第二个
    QPushButton *btnStrange = new QPushButton("Stranger");
    toolBox->addItem(btnStrange, "Stranger");
    toolBox->setGeometry(0, 220, 130, 160);


    connect(startBtn, SIGNAL(clicked()), this, SLOT(startProgress()));
    connect(stopBtn, SIGNAL(clicked()), this, SLOT(resetProcess()));

    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(setLabelText(int)));

    connect(btn, SIGNAL(clicked()), label, SLOT(close()));
    connect(comBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onChanged(int)));
    connect(btn1, SIGNAL(clicked()), label, SLOT(show()));

}

void Dialog::onChanged(int index)
{
    QMessageBox::warning(this, "message", comBox->itemText(index), QMessageBox::Ok);
}

void Dialog::setLabelText(int pos)
{
    QString str = QString("%1").arg(pos);
    sliLabel->setText(str);
}

void Dialog::startProgress()
{
    bar->setRange(0, 1000);
    for (int i = 0; i <= 1000; ++i)
    {
        bar->setValue(i);
        QString str = QString("%1").arg(i);
        str = "复制文件数目:" + str;
        fileNum->setText(str);


    }
}

void Dialog::resetProcess()
{
    bar->setValue(0);
    QString str = "复制文件数目:0" ;
    fileNum->setText(str);
}


QTab::QTab(QWidget *parent) : QDialog(parent)
{
    tabWidget = new QTabWidget(this);
    //新建第一个页面的部件
    QWidget *widget = new QWidget();
    QLineEdit *lineEdit1 = new QLineEdit(widget);
    lineEdit1->setGeometry(10,10,190,30);
    QPushButton *pushButton = new QPushButton("Test",widget);
    pushButton->setGeometry(10,45,190,30);
    //新建第二个页面的部件
    QLabel * label = new QLabel("Hello, qt");
    label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    //新建地三个部件的页面
    QPushButton *pushButton3 = new QPushButton("click me");

    //向qtab中添加页面
    tabWidget->addTab(widget, "tab1");
    tabWidget->addTab(label, "tab2");
    tabWidget->addTab(pushButton3, "tab3");
    tabWidget->setGeometry(0,0,220,150);
    this->resize(220,150);
    this->setWindowTitle("QtabWidgetDemo");



}

QStackW::QStackW(QWidget *parent)
{
    QListWidget *leftlist = new QListWidget(this);
    QStackedWidget *stack = new QStackedWidget(this);
    QLabel *label1 = new QLabel("Label 1");
    QLabel *label2 = new QLabel("Label 2");
    QLabel *label3 = new QLabel("Label 3");
    label1->setAlignment(Qt::AlignCenter);
    //添加层叠窗体
    stack->addWidget(label1);
    stack->addWidget(label2);
    stack->addWidget(label3);

    //设置列表框

    leftlist->addItem("Label1");
    leftlist->addItem("Label2");
    leftlist->addItem("Label3");

    leftlist->setGeometry(10,10,70,200);
    stack->setGeometry(85,10,300,200);
    resize(390,220);
    connect(leftlist, SIGNAL(currentRowChanged(int)), stack, SLOT(setCurrentIndex(int)));

}
