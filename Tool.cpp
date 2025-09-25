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

