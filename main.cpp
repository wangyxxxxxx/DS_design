#include <QWidget>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QDoubleValidator>
#include <QApplication>
#include <QPushButton>
#include <QString>
#include <iostream>
#include "MainWindow.h"
using namespace std;
int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    MainWindow window;


    window.show();


    return a.exec();
}

