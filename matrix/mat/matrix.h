#ifndef MATRIX_H
#define MATRIX_H

class Matrix{
    private:
        bool** mArray;
        int rows;
        int columns;

    public:
        Matrix(int rows, int columns);
        bool getCellState(int m, int n) const;
        int getNumberOfRows() const;
        int getNumberOfColumns() const;
        void renderMatrix();
        void setMatrix(int *arr, int r, int c);
};

#endif
