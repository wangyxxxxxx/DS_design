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
#include "Graph.h"
#include "SortWidget.h"
using namespace std;
int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    SortWidget sortwidget;


    sortwidget.show();


    return a.exec();
}

