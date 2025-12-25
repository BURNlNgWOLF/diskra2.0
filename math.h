#ifndef MATH_H
#define MATH_H
#include <QString>
#include <vector>
#include <QTableWidget>
int HowLongIsBoolFunc(QString);
std::vector<bool> polynomZhegalkina(std::vector<bool>);
std::vector<std::vector<bool>> generateTruthTable(std::vector<bool> boolFunc);
std::vector<bool> QStringTovector(QString func);
std::string zhegalkinToString(std::vector<bool> polynom);
void printBoolMatrix(std::vector<std::vector<bool>> mat);
void printBoolVector(std::vector<bool> vec);
void displayTruthTableFromVector(QTableWidget* table, const std::vector<bool>& outputs);
std::string calculateSDNF(const std::vector<bool>& outputs);
std::string calculateSKNF(const std::vector<bool>& outputs);

#endif // MATH_H
