//
// Created by Reaper on 2023/9/13.
//

#ifndef QTFINAL_MAINWINDOW_H
#define QTFINAL_MAINWINDOW_H

#include <QMainWindow>
#include "TCPListener.h"
#include "Mesh.h"
#include <unistd.h>

namespace ui {
    QT_BEGIN_NAMESPACE
    namespace Ui { class MainWindow; }
    QT_END_NAMESPACE

    class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow() override;

        int timerId;

    protected:
        //初始化工具栏的函数
        void initToolBar();

        //初始化菜单栏的函数
        void initMenuBar();

        //初始化状态栏的函数
        void initStatusBar();

    private slots:

        void on_Button1_clicked();

        void on_Button2_clicked();

        void on_Button3_clicked();

        void on_Button4_clicked();

        void on_Button5_clicked();

        void on_Button6_clicked();

        void on_pictureShowBtn_clicked();

        void on_ascBtn_clicked();

        void on_descBtn_clicked();

        void on_qurryBtn_clicked();

        void on_delBtn_clicked();


        //comboBox修改时
        void on_comboBox_currentIndexChanged(int index);

        void on_comboBox_2_currentIndexChanged(int index);

        void on_comboBox_3_currentIndexChanged(int index);

        void on_checkBox_del_stateChanged(int arg1);




    private:
        Ui::MainWindow *ui;

        TCPListener tcp;

        Mesh mesh;

        bool drawFlag = false;//是否绘制
        bool drawTriangleFlag = false;//是否绘制三角形
        bool drawTriangleColorFlag = true;//是否绘制三角形颜色
        bool drawLineColorFlag = false;//是否绘制线颜色
        bool drawPointFlag = false;//是否绘制点
        bool drawPointColorFlag = false;//是否绘制点颜色
        bool drawHVFlag = false;//是否绘制高压边界
        bool drawGNDFlag = false;//是否绘制低压边界

        //重写定时器事件
        void timerEvent(QTimerEvent *event) override;

        //重写事件过滤器
        bool eventFilter(QObject *watched, QEvent *event) override;
    };
} // ui

#endif //QTFINAL_MAINWINDOW_H
