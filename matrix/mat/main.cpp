#include <iostream>
#include <deque>
#include "matrix.h"

using namespace std;

bool checkMatrix(const Matrix& matrix);

bool checkMatrix(const Matrix& matrix){
    // für speicherung der grösse des QUADRATS
    int squareSum = 0;
    //int 2D array
    int** a = new int *[matrix.getNumberOfRows()];
    for (int i = 0; i < matrix.getNumberOfColumns(); i++){
        a[i] = new int [matrix.getNumberOfColumns()];
    }
    //2D array auf 0 initialisieren
    for(int i = 0; i < matrix.getNumberOfRows(); i++){
        for(int j = 0; j < matrix.getNumberOfColumns(); j++){
            a[i][j] = 0;
        }
    }

    //ERSTE ROW mit matrix werten gleich setzen // HIER MACHT SICH DAS VERTAUESCH DER ROWS + COLUMNS BEMERKBAR
    for(int i = 0; i < matrix.getNumberOfColumns(); i++){
        a[0][i] = (int) matrix.getCellState(0, i);
    }

    //ERSTE CLOUMN mit matrix werten gleichsetzen // HIER MACHT SICH DAS VERTAUESCH DER ROWS + COLUMNS BEMERKBAR
    for(int i = 0; i < matrix.getNumberOfRows(); i++){
        a[i][0] = (int) matrix.getCellState(i, 0);
    }

    //make Square comp ->
    deque<int> tmp;
    for(int i = 1; i < matrix.getNumberOfRows(); i++){
        for (int j = 1; j < matrix.getNumberOfColumns(); j++){
            if(matrix.getCellState(i, j) == 1){
                tmp.push_back(a[i - 1][j -1]);

                if(a[i - 1][j] <= tmp.front()){
                    tmp.push_front(a[i - 1][j]);
                } else{
                    tmp.push_back(a[i - 1][j]);
                }

                if(a[i][j -1] <= tmp.front()){
                    tmp.push_front(a[i][j -1]);
                } else{
                    tmp.push_back(a[i][j -1]);
                }

                a[i][j] = tmp.front() + 1;

            } else{
                a[i][j] = 0;
            }

            if(squareSum < a[i][j]) squareSum = a[i][j];

            tmp.clear();
        }
    }

    //CHECK DRAW OF ARRAY

    for (int i = 0; i<matrix.getNumberOfRows();i++){
        for (int j = 0; j < matrix.getNumberOfColumns(); j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << "--------------------------\n";


    return squareSum >= 2 ? true : false;
}

int main(int argc, char** argv){
 // AUCHTUNG LEIDER ROWS MIT COLUMNS VERTAUSCHT... (Da ARRAY ZUERST IN DIE TIEFE GEHEN UND DANN ERST IN DIE BREITE)
    Matrix a1(4, 5);

    int test[4][5] = {{0,0,1,1,1},{1,0,1,1,1},{0,1,1,1,1},{1,0,1,1,1}};
    int columns = 5, rows = 4;

    //a1.setMatrix(test[0], rows, columns);
    a1.setMatrix(test[0], rows, columns);
    a1.renderMatrix();

    //cout << a1.getNumberOfRows() << " " << a1.getNumberOfColumns() << endl;


    //cout << (a1.getCellState(1, 4) ? "TRUE":"FALSE") << endl;

    cout << (checkMatrix(a1) ? "ES IST EIN QUADRAT VORHANDEN!" : "ES IST KEIN QUADRAT VORHANDEN!");
    return 0;
}
