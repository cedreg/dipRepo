#include "matrix.h"
#include <iostream>


Matrix::Matrix(int rows, int columns){
    this->rows = rows;
    this->columns = columns;

    mArray = new bool*[this->rows];
    for(int i = 0; i < rows; i++){
        mArray[i] = new bool[this->columns];
    }


    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->columns; j++){
            mArray[i][j] = false;
        }
    }
}

int Matrix::getNumberOfRows() const{
    return rows;
}

int Matrix::getNumberOfColumns() const{
    return columns;
}

bool Matrix::getCellState(int m, int n) const{
    return mArray[m][n] ? true : false;
}

void Matrix::renderMatrix(){
    for (int i = 0; i < rows;i++){
        for (int j = 0; j < columns; j++){
            std::cout << mArray[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "--------------------------\n";
}

void Matrix::setMatrix(int *arr, int r, int c){
    if (r != rows) return;
    if (c != columns) return;


    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            mArray[i][j] = *(arr + i * c + j);
        }
    }

}
