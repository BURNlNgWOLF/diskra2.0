#include "math.h"
#include <iostream>
#include <QDebug>
#include <vector>
using std::vector;
int HowLongIsBoolFunc(QString func){
    const int length = func.length();
    for (QChar c: func){
        qDebug() << c;
        if (c != '0' && c != '1'){
            return -1;
        }
    }
    return length;
}
int displayBoolVector(vector<bool> vec){

    for (bool num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
vector<bool> polynomZhegalkina(vector<bool> topRow){
    vector<bool> bottomRow = {false};
    vector<bool> output;
    std::cout << "started calculating" << std::endl;
    int size = topRow.size();
    std::cout << "Initial function: ";
    displayBoolVector(topRow);
    for (int i = 0; i < size; i++){
        output.push_back(topRow[0]);
        // Displaying the whole triangle
        //displayBoolVector(topRow);
        //end condition
        if (topRow.size() == 1){
            std::cout << "Zhegalkin polynomial as function: ";
            displayBoolVector(output);
            return output;
        }
        bottomRow.clear();
        for (int j = 0; j < topRow.size() - 1; j++){
            bottomRow.push_back(topRow[j] ^ topRow[j+1]);
        }
        topRow.clear();
        topRow = bottomRow;
        bottomRow.clear();
    }
    displayBoolVector(output);
    return {0};
}



