#include "math.h"
#include <iostream>
#include <QDebug>
#include <vector>
#include <string>
using std::vector;
int HowLongIsBoolFunc(QString func){
    const int length = func.length();
    for (QChar c: func){
        if (c != '0' && c != '1'){
            return 0;
        }
    }
    return length;
}

void printBoolVector(vector<bool> vec){

    for (bool num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
void printBoolMatrix(std::vector<std::vector<bool>> mat){
    for(int i = 0; i < mat.size(); i++){
      for(int j = 0; j < mat[0].size(); j++){
       std::cout << mat[i][j];
      }
      std::cout << std::endl;
    }
}
vector<bool> QStringTovector(QString func){
    if (!HowLongIsBoolFunc(func)){
        std::cout << "NOT A BOOLEAN FUNCTION" << std::endl;
        return {0};
    }
    vector<bool> output;
    for (QChar c: func){
        if (c == '0') output.push_back(false);
        if (c == '1') output.push_back(true);
    }
    return output;
}
vector<bool> polynomZhegalkina(vector<bool> topRow){
    vector<bool> bottomRow = {false};
    vector<bool> output;
    std::cout << "Zhegalkatron activated" << std::endl;
    int size = topRow.size();
    for (int i = 0; i < size; i++){
        output.push_back(topRow[0]);
        //Uncomment next line to display the whole triangle
        //displayBoolVector(topRow);

        //end condition
        if (topRow.size() == 1){
            //std::cout << "Zhegalkin polynomial as function: ";
            //printBoolVector(output);
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
    printBoolVector(output);
    return {0};
}
vector<vector<bool>> generateTruthTable(vector<bool> boolFunc) {
    int size = boolFunc.size();
    int n = 0;
    // n is amount of variables needed to fill the whole table
    while ((1 << n) < size) n++;
    vector<vector<bool>> funMatrix((1 << n),vector<bool>(n+1));

    //cout << "matrix is " << funMatrix.size() << "by " << funMatrix[0].size() << endl;
    //cout << "size 1 is: " << funMatrix.size() << endl;
    //cout << "size 2 is: " << funMatrix[0].size() << endl;
    //fills the whole truth table variable values
    for(int i = 0; i < funMatrix.size(); i++){
        for(int j = 0; j < funMatrix[0].size()-1; j++){
            funMatrix [i][j] = (i >> (n - 1 - j)) & 1;
        }
    }
    for(int i = 0; i < boolFunc.size(); i++){
        funMatrix[i][n] = boolFunc[i];
    }
    return funMatrix;
}

std::string zhegalkinToString(vector<bool> polynom){

    return "a";
}



