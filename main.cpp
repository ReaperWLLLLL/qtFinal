#include <QApplication>
#include <QPushButton>
#include "mainwindow.h"
#include "lapacke.h"
#include "lapacke_example_aux.h"
#include "mesh.h"
#include "TCPListener.h"

using namespace std;
using namespace ui;


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    //设置全局字体为得意黑
    QFont font("得意黑", 12);
    QApplication::setFont(font);
    MainWindow w;
    w.show();
    //mesh.solve();
    return QApplication::exec();
}
