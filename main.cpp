#include <iostream>
#include "MainWindow.h"
using namespace std;
int main(int argc, char *argv[]) {


    SetConsoleOutputCP(65001);


    QApplication a(argc, argv);
    MainWindow window;

    window.show();

    return a.exec();
}

