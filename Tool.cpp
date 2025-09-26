//
// Created by 王雨轩 on 25-9-25.
//

#include "Tool.h"
#include <iostream>
#include <QString>
using namespace std;

QString arrtoqs(int arr[],int size) {
    QString result;

    for (int i = 0; i < size; i++) {
        if (i > 0) result += ", ";  // 添加分隔符
        result += QString::number(arr[i]);
    }

    result += "\n";

    return result;
}

// int* qstoarr(QString qstr) {
//     int count=0;
//     for (int i = 0; i < qstr.length(); i++) {
//         QChar ch = qstr.at(i);
//
//         if (ch.isDigit()) {
//             count++;
//         }
//     }
//
//     int* arr = new int[count];
//     for (int i = 0,j=0; i < qstr.length(); i++) {
//         QChar ch2 = qstr.at(i);
//         if (ch2.isDigit()) {
//             arr[j]=ch2.digitValue();
//             j++;
//         }
//     }
//     return arr;
// }

