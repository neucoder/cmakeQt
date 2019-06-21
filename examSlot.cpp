//
// Created by ys on 19-6-16.
//


#include "examSlot.hxx"
#include <string>
using namespace std;


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

    label = new QLabel("0", this);
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
    connect(btn1, SIGNAL(clicked()), this, SLOT(changeValue()));
    connect(this, SIGNAL(sentValue(QString)), label, SLOT(setText(QString)));

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

void Dialog::changeValue()
{
    count ++;
    QString s = QString::number(count);
    emit sentValue(QString(s));
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

TreeWidget::TreeWidget(QWidget *parent) : QDialog(parent)
{
    tree = new QTreeWidget(this);
    //设置列数
    tree->setColumnCount(1);
    //设置标题头隐藏
    tree->setHeaderHidden(true);

    QTreeWidgetItem *Friend = new QTreeWidgetItem(tree, QStringList(QString("朋友")));
    QTreeWidgetItem *frd = new QTreeWidgetItem(Friend);
    frd->setText(0, "老张");


    QTreeWidgetItem *ClassMate = new QTreeWidgetItem(tree, QStringList(QString("同学")));
    QTreeWidgetItem *fly = new QTreeWidgetItem(QStringList(QString("fly")));
    ClassMate->addChild(fly);

    QTreeWidgetItem *Strange = new QTreeWidgetItem(tree);
    Strange->setText(0, tr("陌生人"));
    tree->addTopLevelItem(ClassMate);
    tree->addTopLevelItem(Strange);
    //展开qtree的所有节点
    tree->expandAll();
    //响应QtreeWidget节点上的双击事件

    connect(tree, SIGNAL(itemDoubleClicked(QTreeWidgetItem*, int)), this, SLOT(item_Dblclicked(QTreeWidgetItem*, int)));
    this->setWindowTitle("QtreeWidgetDemo");
    this->resize(230, 200);
    tree->resize(230, 200);




}


void TreeWidget::item_Dblclicked(QTreeWidgetItem *item, int column)
{
    QString str = item->text(column);
    QMessageBox::warning(this, "响应双击事件", "你双击了\'"+str+"\'",
            QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);
}

TableWidget::TableWidget(QWidget *parent) : QWidget(parent)
{
    auto *table = new QTableWidget(10, 5, this);
    table->setWindowTitle("Qtable & item");
    table->resize(350,200);
    QStringList header;
    header << "month" << "Name" << "Description";
    table->setHorizontalHeaderLabels(header);
    table->setItem(0,0,new QTableWidgetItem("jan"));
    table->setItem(1,0,new QTableWidgetItem("feb"));
    table->setItem(2,0,new QTableWidgetItem("mar"));

    table->setItem(0,1,new QTableWidgetItem("file1"));
    table->setItem(1,1,new QTableWidgetItem("file2"));
    table->setItem(2,1,new QTableWidgetItem("file3"));

    table->show();
}

RichText::RichText(QWidget *parent):QWidget(parent)
{
    colorBtn = new QPushButton("color", this);
    fontBtn = new QPushButton("font", this);

    edit = new QTextEdit(this);

    colorBtn->setGeometry(30,30,80,30);
    fontBtn->setGeometry(120,30,80,30);
    edit->setGeometry(30,80,220,150);
    connect(colorBtn, SIGNAL(clicked()), this, SLOT(clickedColorButton()));
    connect(fontBtn, SIGNAL(clicked()), this, SLOT(clickedFontButton()));



}

void RichText::clickedColorButton()
{
    auto *colorDialog = new QColorDialog(this);
    colorDialog->setCurrentColor(QColor(Qt::black));
    if(QDialog::Accepted == colorDialog->exec())
    {
        edit->setTextColor(colorDialog->currentColor());
    }
}

void RichText::clickedFontButton()
{
    auto *fontDialog = new QFontDialog(this);
    fontDialog->setCurrentFont(edit->font());
    if(QDialog::Accepted == fontDialog->exec())
    {
        edit->setCurrentFont(fontDialog->currentFont());
    }
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle(tr("Main Window"));
    //定义action
    openAction = new QAction(tr("&open file"),this);
    auto exitAction = new QAction(tr("&dialog"),this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("Opening an existing file"));
    connect(openAction, &QAction::triggered, this, &MainWindow::open);
    connect(exitAction, &QAction::triggered, this, &MainWindow::close);


    setAction = new QAction(tr("options..."), this);
    setAction->setStatusTip(tr("environment setting"));

    connect(setAction, &QAction::triggered, this, &MainWindow::setting);






    //添加菜单
    QMenu *file = menuBar()->addMenu(tr("&File"));
    file->addAction(openAction);
    file->addAction(setAction);


    //添加工具栏

    QToolBar *toolBar = addToolBar(tr("&File"));
    toolBar->addAction(openAction);

    //设置状态栏信息
    QStatusBar *status = statusBar();
    status->addAction(openAction);
    status->addAction(setAction);

}

void MainWindow::open()
{
    QMessageBox::information(this, tr("Information"),tr("Open"));
}

void MainWindow::setting()
{
    myDialog *dialog = new myDialog(this);
    dialog->show();

}

FileDialog::FileDialog(QWidget *parent) : QDialog(parent)
{
    resize(400, 600);
    btn = new QPushButton("File Dialog", this);
    btn->setGeometry(20, 20, 100, 20);
    label = new QLabel(this);
    label->setText("file path");
    label->setGeometry(20,50,300, 20);
    connect(btn, SIGNAL(clicked()), this, SLOT(slotOpenFileDlg()));
    colorBtn = new QPushButton("color select", this);
    colorBtn->setGeometry(20, 80, 100, 20);
    connect(colorBtn, SIGNAL(clicked()), this, SLOT(slotColor()));

    fontBtn = new QPushButton("Font ",this);
    fontBtn->setGeometry(20, 100, 100, 60);
    connect(fontBtn, SIGNAL(clicked()), this, SLOT(fontDlg()));

    Message1 = new QPushButton("info",this);
    Message1->setGeometry(20, 180, 60, 20);
    Message2 = new QPushButton("critical",this);
    Message2->setGeometry(20, 200, 60, 20);
    Message3 = new QPushButton("waring",this);
    Message3->setGeometry(20, 220, 60, 20);
    Message4 = new QPushButton("question",this);
    Message4->setGeometry(20, 240, 60, 20);
    Message5 = new QPushButton("about",this);
    Message5->setGeometry(20, 260, 60, 20);

    connect(Message1, SIGNAL(clicked()), this, SLOT(message1()));
    connect(Message2, SIGNAL(clicked()), this, SLOT(message2()));
    connect(Message3, SIGNAL(clicked()), this, SLOT(message3()));
    connect(Message4, SIGNAL(clicked()), this, SLOT(message4()));
    connect(Message5, SIGNAL(clicked()), this, SLOT(message5()));





}

void FileDialog::slotOpenFileDlg()
{
    QString s = QFileDialog::getOpenFileName(
            this,
            "open file dialog",
            "/",
            "C++ files(*.cpp);;C files(*.c);;Header files (*.h);;All files(*)"
            );

    label->setText(s);

}

void FileDialog::slotColor()
{
    QColor color = QColorDialog::getColor(Qt::blue);
    if(color.isValid())
    {
        int r, g, b;
        color.getRgb(&r, &g, &b);
        qDebug() << "R:" << r << " B:" << g << " B:" << b;
    }

}

void FileDialog::fontDlg()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok);
    if(ok)
    {
        fontBtn->setFont(font);
    }

}

void FileDialog::message1()
{
    QMessageBox::information(NULL,"info", "Content", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

}

void FileDialog::message2()
{
    QMessageBox::critical(NULL,"critical", "Content", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

}

void FileDialog::message3()
{
    QMessageBox::warning(NULL,"warningl", "Content", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

}

void FileDialog::message4()
{
    QMessageBox::question(NULL,"question", "Content", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

}

void FileDialog::message5()
{
    QMessageBox::about(NULL,"about", "about this application");

}

void Draw::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.save();
    QBrush brush(Qt::red);
    painter.setBrush(brush);
    painter.translate(100,100);
    painter.drawRect(0,0,50,50);
    painter.restore();
    QPen pen;
    pen.setWidth(5);
    painter.setPen(pen);
    painter.drawRect(10,10,50,50);


    /*
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 30));
    painter.drawText(rect(), Qt::AlignCenter, "Qt");
    painter.drawEllipse(QRect(0,0,width()-1,height()-1));
     */
}

#define PI 3.1415926
void Clock::CalcPosition()
{
    float secondHandLen, minuteHandLen, hourHandLen;
    secondHandLen = radius * 0.8;
    minuteHandLen = radius * 0.65;
    hourHandLen   = radius * 0.5;
    xSecond = xCenter + secondHandLen * cos(second * PI/30 - PI/2);
    ySecond = yCenter + secondHandLen * sin(second * PI/30 - PI/2);

    xMinute = xCenter + minuteHandLen * cos(minute * PI/30 - PI/2);
    yMinute = yCenter + minuteHandLen * sin(minute * PI/30 - PI/2);

    xHour = xCenter + hourHandLen * cos((hour + 1.0 * minute / 60) * PI/6 - PI/2);
    yHour = yCenter + hourHandLen * sin((hour + 1.0 * minute / 60) * PI/6 - PI/2);
}

void Clock::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen pen;
    QPixmap pix, newimg;

    //pix.load("flower.png");
    //painter.drawPixmap(0,0,pix.width(), pix.height(), pix);


//    for (int i = 0; i < 10; ++i)
//    {
//        int r = 10+rand() % 50;
//        int x = rand() % 453;
//        int y = rand() % 531;
//        newimg = pix.scaled(r, r);
//
//        painter.drawPixmap(x, y, newimg.width(), newimg.height(), newimg);
//
//    }


    pen.setWidth(4);
    pen.setColor(Qt::blue);
    painter.setPen(pen);
    painter.drawEllipse(QPointF(120.0,120.0),radius,radius);

    pen.setColor(Qt::green);
    painter.setPen(pen);
    painter.drawLine(xCenter, yCenter, xSecond, ySecond);

    pen.setWidth(6);
    pen.setColor(Qt::yellow);
    painter.setPen(pen);
    painter.drawLine(xCenter, yCenter, xMinute, yMinute);

    pen.setWidth(8);
    pen.setColor(Qt::red);
    painter.setPen(pen);
    painter.drawLine(xCenter, yCenter, xHour, yHour);



}

void Clock::timerEvent(QTimerEvent *event)
{
    QObject::timerEvent(event);
    CalcPosition();
    second++;
    if(second==59)
    {
        second = 0;
        minute++;
    }

    if(minute==59)
    {
        minute=0;
        hour++;
    }

    if(hour==23)
    {
        hour = 0;
    }

    update();
}

Clock::Clock(QWidget *parent) : QWidget(parent)
{

    setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);

    setAttribute(Qt::WA_NoSystemBackground);
    setAttribute(Qt::WA_TranslucentBackground);
    //setAttribute(Qt::WA_PaintOnScreen);
    //setAttribute(Qt::WA_TransparentForMouseEvents);


    resize(453,531);
    radius = 100;
    xCenter = 120, yCenter = 120;
    hour = 3;
    minute = 56;
    second = 55;
    closeBtn = new QPushButton("close", this);
    closeBtn->setGeometry(400, 530, 40, 20);
    //QString style = "background:url(quan.png);background-repeat:none;";
   // setStyleSheet(style);



    CalcPosition();
    startTimer(1000);
}

void Clock::mouseMoveEvent(QMouseEvent *e)
{
    QWidget::mouseMoveEvent(e);
    if(isMouseDown)
    {


    }


}

void Clock::mouseReleaseEvent(QMouseEvent *e)
{
    QWidget::mouseReleaseEvent(e);

    ds = e->pos() - mousePoint;
    move(pos()+ds);
    isMouseDown = false;
}

void Clock::mousePressEvent(QMouseEvent *e)
{
    QWidget::mousePressEvent(e);

    if(e->button()==Qt::LeftButton)
    {
        isMouseDown = true;
        mousePoint = e->pos();

    }

    if(e->button()==Qt::RightButton)
    {
        close();
    }

}

