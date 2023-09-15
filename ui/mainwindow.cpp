//
// Created by Reaper on 2023/9/13.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include <QFile>
#include <thread>
#include <fstream>
#include <QScrollArea>
#include <QFileDialog>
#include <QPainter>
#include "mainwindow.h"
#include "ui_MainWindow.h"
#include "TCPListener.h"


namespace ui {
    MainWindow::MainWindow(QWidget *parent) :
            QMainWindow(parent), ui(new Ui::MainWindow) {
        ui->setupUi(this);
        //加载qss
        QFile qss("./qss/MaterialDark.qss");
        qss.open(QFile::ReadOnly);
        qApp->setStyleSheet(qss.readAll());
        qss.close();
        //设置窗口不可放大
        this->setFixedSize(this->width(), this->height());
        //设置label可以复制
        ui->label->setTextInteractionFlags(Qt::TextSelectableByMouse);
        //设置按钮2、3、4、5、6不可用
        ui->Button2->setEnabled(false);
        ui->Button4->setEnabled(false);
        ui->Button5->setEnabled(false);
        ui->Button6->setEnabled(false);
        //设置label文本为已断开
        ui->label->setText("Waiting for connection...");
        timerId = 0;
        ui->pictureShowBtn->setEnabled(false);
        //设置combobox的文本
        ui->comboBox->addItem("El2no");
        ui->comboBox->addItem("Bd2no");
        ui->comboBox->addItem("No2xy");
        ui->comboBox_1->clear();
        ui->comboBox_1->addItem("no1");
        ui->comboBox_1->addItem("no2");
        ui->comboBox_1->addItem("no3");
        ui->comboBox_4->clear();
        ui->comboBox_4->addItem("no1");
        ui->comboBox_4->addItem("no2");
        ui->comboBox_4->addItem("no3");
        ui->comboBox_2->addItem("El2no");
        ui->comboBox_2->addItem("Bd2no");
        ui->comboBox_2->addItem("No2xy");
        ui->comboBox_3->addItem("El2no");
        ui->comboBox_3->addItem("Bd2no");
        ui->comboBox_3->addItem("No2xy");

        //设置qurryLine_1的hint
        ui->qurryLine_1->setPlaceholderText("下界");
        ui->qurryLine_2->setPlaceholderText("上界");
        ui->qurryLine_3->setPlaceholderText("no1");
        ui->qurryLine_4->setPlaceholderText("no2");
        ui->qurryLine_5->setPlaceholderText("no3");


        //设置lineEdit只接受数字
        ui->qurryLine_1->setValidator(new QIntValidator(-100000, 1000000, this));
        ui->qurryLine_2->setValidator(new QIntValidator(-100000, 1000000, this));
        ui->qurryLine_3->setValidator(new QIntValidator(-100000, 1000000, this));
        ui->qurryLine_4->setValidator(new QIntValidator(-100000, 1000000, this));
        ui->qurryLine_5->setValidator(new QIntValidator(-100000, 1000000, this));

        //给label_2添加事件过滤器
        ui->label_2->installEventFilter(this);


    }

    MainWindow::~MainWindow() {
        delete ui;
    }

    void MainWindow::initToolBar() {


    }

    void MainWindow::on_Button1_clicked() {
        ui->label->setText(QString::fromStdString(tcp.displayHostIP() + ':' + to_string(tcp.displayHostPort())));
        tcp.startWaitConnectionMultiThread();
        //启动定时器
        timerId = startTimer(1000);
        //设置按键不可用
        ui->Button1->setEnabled(false);
        //设置按键2可用
        ui->Button2->setEnabled(true);
    }

    void MainWindow::on_Button2_clicked() {
        //关闭监听，保存文件
        tcp.stopReceiveMultiThread();
        ofstream fs("text.txt", ios::out);
        if (fs.is_open()) {
            fs << tcp.recvBuffer.str();
            fs.close();
        }
        tcp.closeClient();

        //设置label文本为已断开
        string s = "Disconnected.";
        s += "\n";
        s += tcp.recvBuffer.str();
        ui->label->setText(s.c_str());
        //关闭计时器
        killTimer(timerId);
        //设置按键1可用
        ui->Button1->setEnabled(true);
        //设置按键2不可用
        ui->Button2->setEnabled(false);
        //设置按键3可用
        ui->Button3->setEnabled(true);
    }

    void MainWindow::on_Button3_clicked() {
        //调出文件选择框
        QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Text Files (*.txt)"));
        mesh = Mesh(fileName.toStdString());
        string s;
        s += "File loaded. Filename:";
        s += fileName.toStdString();
        s += "\n";
        ui->label->setText(s.c_str());
        //设置按键4可用
        ui->Button4->setEnabled(true);

    }

    void MainWindow::on_Button4_clicked() {
        mesh.solve();
        //设置按键5可用
        ui->Button5->setEnabled(true);
        ui->label->setText("Solved.");
    }

    void MainWindow::on_Button5_clicked() {
        if (mesh.add_record()) {
            ui->label->setText("Record added.");
        } else {
            ui->label->setText("Record not added.");
        };
        //设置按键6可用
        ui->Button6->setEnabled(true);
        ui->pictureShowBtn->setEnabled(true);

    }

    void MainWindow::on_Button6_clicked() {
        string s;
        s += "Record:\n";
        s += mesh.qurry_record();
        s += "\n";
        ui->label->setText(s.c_str());
    }

    //重写timerEvent函数
    void MainWindow::timerEvent(QTimerEvent *event) {
        if (event->timerId() == timerId) {
            qDebug() << timerId;
            //检查tcp的状态
            if (tcp.readState() == CLIENT_CONNECTED) {
                ui->label->setText("Connected.");
                tcp.startReceiveMultiThread();
                //关闭定时器
                killTimer(timerId);
            }
        } else {
            //传递给父类的timerEvent
            QMainWindow::timerEvent(event);
        }
    }

    void MainWindow::on_comboBox_currentIndexChanged(int index) {
        string s;
        s += "You choose: ";
        switch (index) {
            case 0: {
                s += "El2no";
                ui->label->setText(s.c_str());
                //设置comboBox_1的文本
                ui->comboBox_1->clear();
                ui->comboBox_1->addItem("no1");
                ui->comboBox_1->addItem("no2");
                ui->comboBox_1->addItem("no3");

                break;
            }

            case 1: {
                s += "Bd2no";
                ui->label->setText(s.c_str());
                //设置comboBox_1的文本
                ui->comboBox_1->clear();
                ui->comboBox_1->addItem("bd");
                ui->comboBox_1->addItem("no1");
                ui->comboBox_1->addItem("no2");

                break;
            }

            case 2: {
                s += "No2xy";
                ui->label->setText(s.c_str());
                //设置comboBox_1的文本
                ui->comboBox_1->clear();
                ui->comboBox_1->addItem("x");
                ui->comboBox_1->addItem("y");
                break;
            }

            default: {
                s += "Error";
                ui->label->setText(s.c_str());
                break;
            }

        }
    }

    void MainWindow::on_comboBox_2_currentIndexChanged(int index) {
        string s;
        s += "You choose: ";
        switch (index) {
            case 0: {
                s += "El2no";
                ui->label->setText(s.c_str());
                //设置comboBox_4的文本
                ui->comboBox_4->clear();
                ui->comboBox_4->addItem("no1");
                ui->comboBox_4->addItem("no2");
                ui->comboBox_4->addItem("no3");

                break;
            }

            case 1: {
                s += "Bd2no";
                ui->label->setText(s.c_str());
                //设置comboBox_4的文本
                ui->comboBox_4->clear();
                ui->comboBox_4->addItem("bd");
                ui->comboBox_4->addItem("no1");
                ui->comboBox_4->addItem("no2");

                break;
            }

            case 2: {
                s += "No2xy";
                ui->label->setText(s.c_str());
                //设置comboBox_4的文本
                ui->comboBox_4->clear();
                ui->comboBox_4->addItem("x");
                ui->comboBox_4->addItem("y");

                break;
            }

            default: {
                s += "Error";
                ui->label->setText(s.c_str());
                break;
            }

        }
    }

    void MainWindow::on_comboBox_3_currentIndexChanged(int index) {
        string s;
        s += "You choose: ";
        switch (index) {
            case 0: {
                s += "El2no";
                ui->label->setText(s.c_str());
                ui->qurryLine_3->setPlaceholderText("no1");
                ui->qurryLine_4->setPlaceholderText("no2");
                ui->qurryLine_5->setPlaceholderText("no3");

                ui->qurryLine_3->setEnabled(true);
                ui->qurryLine_4->setEnabled(true);
                ui->qurryLine_5->setEnabled(true);

                break;
            }

            case 1: {
                s += "Bd2no";
                ui->label->setText(s.c_str());
                ui->qurryLine_3->setPlaceholderText("bd");
                ui->qurryLine_4->setPlaceholderText("no1");
                ui->qurryLine_5->setPlaceholderText("no2");
                if (ui->checkBox_del->isChecked()) {
                    ui->qurryLine_3->setEnabled(false);
                    ui->qurryLine_3->setPlaceholderText("");
                    ui->qurryLine_4->setEnabled(true);
                    ui->qurryLine_5->setEnabled(true);
                } else {
                    ui->qurryLine_3->setEnabled(true);
                    ui->qurryLine_4->setEnabled(true);
                    ui->qurryLine_5->setEnabled(true);
                }
                break;
            }

            case 2: {
                s += "No2xy";
                ui->label->setText(s.c_str());
                ui->qurryLine_3->setPlaceholderText("x");
                ui->qurryLine_4->setPlaceholderText("y");
                ui->qurryLine_5->setPlaceholderText("");
                ui->qurryLine_5->setEnabled(false);
                ui->qurryLine_4->setEnabled(true);
                ui->qurryLine_3->setEnabled(true);
                if (ui->checkBox_del->isChecked()) {
                    ui->qurryLine_4->setEnabled(false);
                    ui->qurryLine_4->setPlaceholderText("");
                } else {
                    ui->qurryLine_4->setEnabled(true);
                    ui->qurryLine_4->setPlaceholderText("y");
                }
                break;
            }

            default: {
                s += "Error";
                ui->label->setText(s.c_str());
                break;
            }

        }
    }

    void MainWindow::on_pictureShowBtn_clicked() {
        //在label_2上申请绘图事件
        drawFlag = 1;
        ui->label_2->repaint();
    }

    void MainWindow::on_checkBox_del_stateChanged(int arg1) {
        int index = ui->comboBox_3->currentIndex();
        switch (index) {
            case 0: {
                ui->qurryLine_3->setEnabled(true);
                ui->qurryLine_4->setEnabled(true);
                ui->qurryLine_5->setEnabled(true);
                if (arg1 == 2) {
                    ui->delBtn->setText("删除数据");
                } else {
                    ui->delBtn->setText("添加数据");
                }
                break;
            }

            case 1: {
                if (arg1 == 2) {
                    ui->qurryLine_3->setEnabled(false);
                    ui->qurryLine_3->setPlaceholderText("");
                    ui->qurryLine_4->setEnabled(true);
                    ui->qurryLine_5->setEnabled(true);
                    ui->delBtn->setText("删除数据");
                } else {
                    ui->qurryLine_3->setEnabled(true);
                    ui->qurryLine_3->setPlaceholderText("bd");
                    ui->qurryLine_4->setEnabled(true);
                    ui->qurryLine_5->setEnabled(true);
                    ui->delBtn->setText("添加数据");
                }

                break;
            }

            case 2: {
                if (arg1 == 2) {
                    ui->qurryLine_4->setEnabled(false);
                    ui->qurryLine_4->setPlaceholderText("");
                    ui->qurryLine_5->setEnabled(false);
                    ui->qurryLine_5->setPlaceholderText("");
                    ui->delBtn->setText("删除数据");
                } else {
                    ui->qurryLine_4->setEnabled(true);
                    ui->qurryLine_4->setPlaceholderText("y");
                    ui->qurryLine_5->setEnabled(false);
                    ui->qurryLine_5->setPlaceholderText("");
                    ui->delBtn->setText("添加数据");
                }
                break;
            }

            default: {
                break;
            }

        }

    }

    void MainWindow::on_ascBtn_clicked() {
        switch (ui->comboBox->currentIndex()) {
            case 0: {
                switch (ui->comboBox_1->currentIndex()) {
                    case 0: {
                        ui->label->setText(QString::fromStdString(mesh.display_sorted(0, "no1", true)));
                        break;
                    }
                    case 1: {
                        ui->label->setText(QString::fromStdString(mesh.display_sorted(0, "no2", true)));
                        break;
                    }
                    case 2: {
                        ui->label->setText(QString::fromStdString(mesh.display_sorted(0, "no3", true)));
                        break;
                    }
                    default: {
                        break;
                    }
                }
                break;
            }

            case 1: {
                switch (ui->comboBox_1->currentIndex()) {
                    case 0: {
                        ui->label->setText(QString::fromStdString(mesh.display_sorted(1, "bd", true)));
                        break;
                    }
                    case 1: {
                        ui->label->setText(QString::fromStdString(mesh.display_sorted(1, "no1", true)));
                        break;
                    }
                    case 2: {
                        ui->label->setText(QString::fromStdString(mesh.display_sorted(1, "no2", true)));
                        break;
                    }
                    default: {
                        break;
                    }
                }
                break;
            }

            case 2: {
                switch (ui->comboBox_1->currentIndex()) {
                    case 0: {
                        ui->label->setText(QString::fromStdString(mesh.display_sorted(2, "x", true)));
                        break;
                    }
                    case 1: {
                        ui->label->setText(QString::fromStdString(mesh.display_sorted(2, "y", true)));
                        break;
                    }
                    default: {
                        break;
                    }
                }
                break;
            }
        }
    }

    void MainWindow::on_descBtn_clicked() {
        switch (ui->comboBox->currentIndex()) {
            case 0: {
                switch (ui->comboBox_1->currentIndex()) {
                    case 0: {
                        ui->label->setText(QString::fromStdString(mesh.display_sorted(0, "no1", false)));
                        break;
                    }
                    case 1: {
                        ui->label->setText(QString::fromStdString(mesh.display_sorted(0, "no2", false)));
                        break;
                    }
                    case 2: {
                        ui->label->setText(QString::fromStdString(mesh.display_sorted(0, "no3", false)));
                        break;
                    }
                    default: {
                        break;
                    }
                }
                break;
            }

            case 1: {
                switch (ui->comboBox_1->currentIndex()) {
                    case 0: {
                        ui->label->setText(QString::fromStdString(mesh.display_sorted(1, "bd", false)));
                        break;
                    }
                    case 1: {
                        ui->label->setText(QString::fromStdString(mesh.display_sorted(1, "no1", false)));
                        break;
                    }
                    case 2: {
                        ui->label->setText(QString::fromStdString(mesh.display_sorted(1, "no2", false)));
                        break;
                    }
                    default: {
                        break;
                    }
                }
                break;
            }

            case 2: {
                switch (ui->comboBox_1->currentIndex()) {
                    case 0: {
                        ui->label->setText(QString::fromStdString(mesh.display_sorted(2, "x", false)));
                        break;
                    }
                    case 1: {
                        ui->label->setText(QString::fromStdString(mesh.display_sorted(2, "y", false)));
                        break;
                    }
                    default: {
                        break;
                    }
                }
                break;
            }
        }

    }

    void MainWindow::on_qurryBtn_clicked() {
        //获取下界
        int low = ui->qurryLine_1->text().toInt();
        //获取上界
        int high = ui->qurryLine_2->text().toInt();

        switch (ui->comboBox_2->currentIndex()) {
            case 0: {
                switch (ui->comboBox_4->currentIndex()) {
                    case 0: {
                        ui->label->setText(QString::fromStdString(mesh.display_mid(0, "no1", high, low)));
                        break;
                    }
                    case 1: {
                        ui->label->setText(QString::fromStdString(mesh.display_mid(0, "no2", high, low)));
                        break;
                    }
                    case 2: {
                        ui->label->setText(QString::fromStdString(mesh.display_mid(0, "no3", high, low)));
                        break;
                    }
                    default: {
                        break;
                    }
                }
                break;
            }

            case 1: {
                switch (ui->comboBox_4->currentIndex()) {
                    case 0: {
                        ui->label->setText(QString::fromStdString(mesh.display_mid(1, "bd", high, low)));
                        break;
                    }
                    case 1: {
                        ui->label->setText(QString::fromStdString(mesh.display_mid(1, "no1", high, low)));
                        break;
                    }
                    case 2: {
                        ui->label->setText(QString::fromStdString(mesh.display_mid(1, "no2", high, low)));
                        break;
                    }
                    default: {
                        break;
                    }
                }
                break;
            }

            case 2: {
                switch (ui->comboBox_4->currentIndex()) {
                    case 0: {
                        ui->label->setText(QString::fromStdString(mesh.display_mid(2, "x", high, low)));
                        break;
                    }
                    case 1: {
                        ui->label->setText(QString::fromStdString(mesh.display_mid(2, "y", high, low)));
                        break;
                    }
                    default: {
                        break;
                    }
                }
                break;
            }

            default: {
                break;
            }
        }

    }

    void MainWindow::on_delBtn_clicked() {
        switch (ui->comboBox_3->currentIndex()) {
            case 0: {
                if (ui->checkBox_del->isChecked()) {
                    if (mesh.del(ui->qurryLine_3->text().toInt(), ui->qurryLine_4->text().toInt(),
                                 ui->qurryLine_5->text().toInt())) {
                        ui->label->setText("data deleted.");
                    } else {
                        ui->label->setText("error.");
                    }
                } else {
                    El2no el2no;
                    el2no.set(ui->qurryLine_3->text().toInt(), ui->qurryLine_4->text().toInt(),
                              ui->qurryLine_5->text().toInt());
                    mesh.add(el2no);
                    ui->label->setText("data added.");
                }
                break;
            }

            case 1: {
                if (ui->checkBox_del->isChecked()) {
                    if (mesh.del(ui->qurryLine_3->text().toInt())) {
                        ui->label->setText("data deleted.");
                    } else {
                        ui->label->setText("error.");
                    }
                } else {
                    Bd2no bd2no;
                    bd2no.set(ui->qurryLine_3->text().toInt(), ui->qurryLine_4->text().toInt(),
                              ui->qurryLine_5->text().toInt());
                    mesh.add(bd2no);
                    ui->label->setText("data added.");
                }
                break;
            }

            case 2: {
                if (ui->checkBox_del->isChecked()) {
                    if (mesh.del(ui->qurryLine_3->text().toInt())) {
                        ui->label->setText("data deleted.");
                    } else {
                        ui->label->setText("error.");
                    }
                } else {
                    No2xy no2xy;
                    no2xy.set(ui->qurryLine_3->text().toInt(), ui->qurryLine_4->text().toInt());
                    mesh.add(no2xy);
                    ui->label->setText("data added.");
                }
                break;
            }

            default: {
                break;
            }
        }
    }

    bool MainWindow::eventFilter(QObject *watched, QEvent *event) {
        //若label上出现绘图事件
        if (watched == ui->label_2 && event->type() == QEvent::Paint && drawFlag == 1) {
            //获取label的宽度
            int width = ui->label_2->width();
            //获取label的高度
            int height = ui->label_2->height();
            //获取label的画布
            QPixmap pixmap(width, height);
            //设置画布为白色
            pixmap.fill(Qt::white);
            //从mesh的no2xy中获取点的坐标
            vector<No2xy> no2xyVec = mesh.no2xyVec;
            //获取点的个数
            int no2xyVecSize = no2xyVec.size();
            //获取点的坐标
            vector<double> x;
            vector<double> y;
            for (int i = 0; i < no2xyVecSize; i++) {
                x.push_back(no2xyVec[i].get("x"));
                y.push_back(no2xyVec[i].get("y"));
            }
            //打印record
            vector<double> record = mesh.record;
            for (int i = 0; i < record.size(); i++) {
                qDebug() << record[i];
            }
            //获取点的最大值和最小值
            double xMax = *max_element(x.begin(), x.end());
            double xMin = *min_element(x.begin(), x.end());
            double yMax = *max_element(y.begin(), y.end());
            double yMin = *min_element(y.begin(), y.end());
            //获取点的个数
            int xSize = x.size();
            //获取点的坐标
            vector<int> xPixel;
            vector<int> yPixel;
            for (int i = 0; i < xSize; i++) {
                xPixel.push_back((int) ((x[i] - xMin) / (xMax - xMin) * width));
                yPixel.push_back((int) ((y[i] - yMin) / (yMax - yMin) * height));
            }
            //获取三角形的个数
            int el2noVecSize = mesh.el2noVec.size();
            //获取三角形的坐标
            vector<int> el2no1;
            vector<int> el2no2;
            vector<int> el2no3;
            for (int i = 0; i < el2noVecSize; i++) {
                el2no1.push_back(mesh.el2noVec[i].get("no1"));
                el2no2.push_back(mesh.el2noVec[i].get("no2"));
                el2no3.push_back(mesh.el2noVec[i].get("no3"));
            }
            double recordMax = *max_element(record.begin(), record.end());
            double recordMin = *min_element(record.begin(), record.end());
            //绘制三角形
            QPainter painter(&pixmap);

            if (drawTriangleFlag) {
                painter.setPen(QPen(Qt::black, 1));
                for (int i = 0; i < el2noVecSize; i++) {
                    painter.drawLine(xPixel[el2no1[i]], yPixel[el2no1[i]], xPixel[el2no2[i]],
                                     yPixel[el2no2[i]]);
                    painter.drawLine(xPixel[el2no2[i]], yPixel[el2no2[i]], xPixel[el2no3[i]],
                                     yPixel[el2no3[i]]);
                    painter.drawLine(xPixel[el2no3[i]], yPixel[el2no3[i]], xPixel[el2no1[i]],
                                     yPixel[el2no1[i]]);
                }
            }

            //绘制点
            if (drawPointFlag) {
                if (!drawPointColorFlag) {
                    painter.setPen(QPen(Qt::black, 6));
                    for (int i = 0; i < xSize; i++) {
                        painter.drawPoint(xPixel[i], yPixel[i]);
                    }
                } else {
                    //根据record的值设置点的颜色，最高为红色，最低为蓝色

                    for (int i = 0; i < xSize; i++) {
                        int color = (int) ((record[i] - recordMin) / (recordMax - recordMin) * 255);
                        painter.setPen(QPen(QColor(color, 0, 255 - color), 6));
                        painter.drawPoint(xPixel[i], yPixel[i]);
                    }
                }
            }

            //绘制高压边界
            if (drawHVFlag) {
                painter.setPen(QPen(Qt::red, 2));
                //从bd中获取编号为6、7、14、15的边界
                vector<Bd2no> bd2noVec = mesh.bd2noVec;
                for (auto bd2no: bd2noVec) {
                    if (bd2no.get("bd") == 6 || bd2no.get("bd") == 7 || bd2no.get("bd") == 14 ||
                        bd2no.get("bd") == 15) {
                        painter.drawLine(xPixel[bd2no.get("no1")], yPixel[bd2no.get("no1")], xPixel[bd2no.get("no2")],
                                         yPixel[bd2no.get("no2")]);
                    }
                }
            }

            //绘制低压边界
            if (drawGNDFlag) {
                //从bd中获取编号为5、13、16的边界
                vector<Bd2no> bd2noVec = mesh.bd2noVec;
                painter.setPen(QPen(Qt::blue, 2));
                for (auto bd2no: bd2noVec) {
                    if (bd2no.get("bd") == 5 || bd2no.get("bd") == 13 || bd2no.get("bd") == 16) {
                        painter.drawLine(xPixel[bd2no.get("no1")], yPixel[bd2no.get("no1")], xPixel[bd2no.get("no2")],
                                         yPixel[bd2no.get("no2")]);
                    }
                }
            }

            //根据三点的record为三角形填充颜色，最高为红色，最低为蓝色
            if(drawTriangleColorFlag){
                //遍历三角形
                for(int i=0;i<el2noVecSize;i++){
                    //获取三角形的三个点的record
                    double record1=record[el2no1[i]];
                    double record2=record[el2no2[i]];
                    double record3=record[el2no3[i]];
                    //将record最大的点的坐标设置为x1,y1，record最小的点的坐标设置为x3,y3，中间值的点的坐标设置为x2,y2
                    int x1,y1,x2,y2,x3,y3;
                    if(record1>record2&&record1>record3){
                        x1=xPixel[el2no1[i]];
                        y1=yPixel[el2no1[i]];
                        if(record2>record3){
                            x2=xPixel[el2no2[i]];
                            y2=yPixel[el2no2[i]];
                            x3=xPixel[el2no3[i]];
                            y3=yPixel[el2no3[i]];
                        }else{
                            x2=xPixel[el2no3[i]];
                            y2=yPixel[el2no3[i]];
                            x3=xPixel[el2no2[i]];
                            y3=yPixel[el2no2[i]];
                        }
                    }else if(record2>record1&&record2>record3){
                        x1=xPixel[el2no2[i]];
                        y1=yPixel[el2no2[i]];
                        if(record1>record3){
                            x2=xPixel[el2no1[i]];
                            y2=yPixel[el2no1[i]];
                            x3=xPixel[el2no3[i]];
                            y3=yPixel[el2no3[i]];
                        }else{
                            x2=xPixel[el2no3[i]];
                            y2=yPixel[el2no3[i]];
                            x3=xPixel[el2no1[i]];
                            y3=yPixel[el2no1[i]];
                        }
                    }else{
                        x1=xPixel[el2no3[i]];
                        y1=yPixel[el2no3[i]];
                        if(record1>record2){
                            x2=xPixel[el2no1[i]];
                            y2=yPixel[el2no1[i]];
                            x3=xPixel[el2no2[i]];
                            y3=yPixel[el2no2[i]];
                        }else{
                            x2=xPixel[el2no2[i]];
                            y2=yPixel[el2no2[i]];
                            x3=xPixel[el2no1[i]];
                            y3=yPixel[el2no1[i]];
                        }
                    }//脏代码
                    //获取三角形的三个点的颜色
                    int color1=(int)((record1-recordMin)/(recordMax-recordMin)*255);
                    int color2=(int)((record2-recordMin)/(recordMax-recordMin)*255);
                    int color3=(int)((record3-recordMin)/(recordMax-recordMin)*255);
                    //设置三角形的颜色
                    QPolygon polygon;
                    polygon.setPoints(3,x1,y1,x2,y2,x3,y3);
                    //设置渐变从x1,y1到x3,y3
                    QLinearGradient gradient(x1,y1,x3,y3);
                    //将color存储入vector
                    vector<int> color;
                    color.push_back(color1);
                    color.push_back(color2);
                    color.push_back(color3);
                    //将color从大到小排序
                    sort(color.begin(),color.end(),greater<int>());
                    //设置渐变的颜色
                    gradient.setColorAt(0,QColor(color[0],0,255-color[0]));
                    gradient.setColorAt(0.5,QColor(color[1],0,255-color[1]));
                    gradient.setColorAt(1,QColor(color[2],0,255-color[2]));

                    painter.setBrush(gradient);
                    //将多边形的边线设置为透明
                    painter.setPen(Qt::NoPen);
                    painter.drawPolygon(polygon);
                }
            }
            //在label上显示画布
            ui->label_2->setPixmap(pixmap);
            //设置绘图标志位为0
            drawFlag = false;
        }
        return QObject::eventFilter(watched, event);
    }
} // ui
