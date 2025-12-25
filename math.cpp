#include "math.h"
#include <iostream>
#include <QDebug>
#include <vector>
#include <string>
#include <QTableWidgetItem>
#include <sstream>

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

//only useful for debugging
void printBoolVector(vector<bool> vec){

    for (bool num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

//not useful because matrix is not used
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
        return {};
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
    //std::cout << "Zhegalkatron activated" << std::endl;
    int size = topRow.size();
    for (int i = 0; i < size; i++){
        output.push_back(topRow[0]);
        //Uncomment next line to display the whole triangle
        //displayBoolVector(topRow);

        //end condition
        if (topRow.size() == 1){
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
    return {};
}

// Not really useful as all calculation are made on a funcion itself rather than using matrix, but could be useful for something else.
vector<vector<bool>> generateTruthTable(vector<bool> boolFunc) {
    int size = boolFunc.size();
    int n = 0;
    while ((1 << n) < size) n++;
    vector<vector<bool>> funMatrix((1 << n),vector<bool>(n+1));
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
    std::string result;
    int n = polynom.size();

    if (n == 0) return result;

    for (int i = 0; i < n; i++) {
        if (polynom[i]) {
            if (!result.empty()) {
                result += " ⊕ ";
            }

            if (i == 0) {
                result += "1";
            } else {
                // Generate term from binary representation
                std::string term;
                int temp = i;
                int bitPos = 0;
                bool firstFactor = true;

                while (temp > 0) {
                    if (temp & 1) {
                        if (!firstFactor) {
                            term += "*";
                        }
                        term += "x" + std::to_string(bitPos + 1);
                        firstFactor = false;
                    }
                    bitPos++;
                    temp >>= 1;
                }

                result += term;
            }
        }
    }

    return result;
}
void displayTruthTableFromVector(QTableWidget* table, const std::vector<bool>& outputs)
{
    if (!table) return;

    size_t N = outputs.size();
    if (N == 0) {
        table->clear();
        table->setRowCount(0);
        table->setColumnCount(0);
        return;
    }

    int numVars = 0;
    if (N > 1) {
        unsigned int value = static_cast<unsigned int>(N - 1);
        while (value > 0) {
            value >>= 1;
            numVars++;
        }
    }

    int numCols = numVars + 1;

    table->clear();
    table->setRowCount(static_cast<int>(N));
    table->setColumnCount(numCols);

    QStringList headers;
    for (int i = 1; i <= numVars; ++i)
        headers << QString("x%1").arg(i);
    headers << "f";
    table->setHorizontalHeaderLabels(headers);

    // Fill table
    for (size_t row = 0; row < N; ++row) {
        for (int col = 0; col < numVars; ++col) {
            bool bit = (row >> (numVars - 1 - col)) & 1U;
            table->setItem(static_cast<int>(row), col,
                          new QTableWidgetItem(bit ? "1" : "0"));
        }

        bool outputVal = outputs[row];
        QString outputText = outputVal ? "1" : "0";
        QTableWidgetItem* outputItem = new QTableWidgetItem(outputText);

        if (outputVal) {
            outputItem->setForeground(QColor(Qt::blue));
        } else {
            outputItem->setForeground(QColor(Qt::red));
        }

        outputItem->setTextAlignment(Qt::AlignCenter);

        table->setItem(static_cast<int>(row), numVars, outputItem);
    }
}

std::string calculateSDNF(const std::vector<bool>& f) {
    size_t n = 0;
    size_t tableSize = 1;
    while (tableSize < f.size()) {
        ++n;
        tableSize <<= 1;
    }

    std::vector<std::string> minterms;

    for (size_t i = 0; i < tableSize; ++i) {
        //assume that each missing element is 0
        bool output = (i < f.size()) ? f[i] : false;
        if (output) {
            std::ostringstream term;
            bool first = true;
            for (size_t var = 0; var < n; ++var) {
                if (!first) term << " ∧ ";
                first = false;
                //check each variable
                if ((i >> var) & 1) {
                    term << "x" << (var + 1);
                } else {
                    term << "¬x" << (var + 1);
                }
            }
            if (n == 0) {
                term << "1";
            }
            minterms.push_back("(" + term.str() + ")");
        }
    }

    if (minterms.empty()) return "0";
    //concatinate stuff
    std::ostringstream result;
    for (size_t i = 0; i < minterms.size(); ++i) {
        if (i > 0) result << " ∨ ";
        result << minterms[i];
    }
    return result.str();
}

std::string calculateSKNF(const std::vector<bool>& f) {
    size_t n = 0;
    size_t tableSize = 1;
    while (tableSize < f.size()) {
        ++n;
        tableSize <<= 1;
    }

    std::vector<std::string> maxterms;

    for (size_t i = 0; i < tableSize; ++i) {
        bool output = (i < f.size()) ? f[i] : false;
        if (!output) {
            std::ostringstream term;
            bool first = true;
            for (size_t var = 0; var < n; ++var) {
                if (!first) term << " ∨ ";
                first = false;

                if ((i >> var) & 1) {
                    term << "¬x" << (var + 1);
                } else {
                    term << "x" << (var + 1);
                }
            }
            if (n == 0) {
                term << "0";
            }
            maxterms.push_back("(" + term.str() + ")");
        }
    }

    if (maxterms.empty()) return "1";

    std::ostringstream result;
    for (size_t i = 0; i < maxterms.size(); ++i) {
        if (i > 0) result << " ∧ ";
        result << maxterms[i];
    }
    return result.str();
}
