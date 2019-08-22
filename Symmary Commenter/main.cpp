#include <QApplication>
#include "mainwindow.h"

// scps 파일을 직접 open한 경우 (프로그램을 셋팅 파일로 실행)
// argv[1]에 해당 scps 파일의 경로가 담긴다.

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window(argv);
    window.show();

    return app.exec();
}
