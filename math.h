#ifndef MATH_H
#define MATH_H
#include <QString>
#include <vector>

int HowLongIsBoolFunc(QString);
std::vector<bool> polynomZhegalkina(std::vector<bool>);
std::vector<std::vector<bool>> generateTruthTable(std::vector<bool> boolFunc);
std::vector<bool> QStringTovector(QString func);
void printBoolMatrix(std::vector<std::vector<bool>> mat);
void printBoolVector(std::vector<bool> vec);

#endif // MATH_H
