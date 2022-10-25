#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

double Determinant(double matrix[][2]);
void Adjoint(double matrixA[][2], double matrixB[][2]);
void printMatrix(double matrix[][2], int, int);

int main() {
  double D;
  double Matrix[2][2] = {{1, 1}, {1, 1}},
         inverseMatrix[2][2] = {{0, 0}, {0, 0}};

  D = Determinant(Matrix);

  cout << "Test Case 1: \n";

  if (D != 0) {
    Adjoint(Matrix, inverseMatrix);

    inverseMatrix[0][0] = (1 / D) * inverseMatrix[0][0];
    inverseMatrix[0][1] = (1 / D) * inverseMatrix[0][1];
    inverseMatrix[1][0] = (1 / D) * inverseMatrix[1][0];
    inverseMatrix[1][1] = (1 / D) * inverseMatrix[1][1];

    printMatrix(inverseMatrix, 2, 2);

  } else {
    cout << "Singular matrix entered. Cannot find inverse \n";
  }
}

double Determinant(double matrix[][2]) {
  double D;

  D = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);

  return D;
}
void Adjoint(double matrixA[][2], double matrixB[][2]) {
  matrixB[0][0] = matrixA[1][1];
  matrixB[0][1] = -1 * (matrixA[0][1]);
  matrixB[1][0] = -1 * (matrixA[1][0]);
  matrixB[1][1] = matrixA[0][0];
}
void printMatrix(double matrix[][2], int N_ROWS, int C) {
  int row, col;
  for (row = 0; row < N_ROWS; row++) {
    for (col = 0; col < C; col++)
      cout << setw(6) << matrix[row][col] << " ";

    cout << endl;
  }
}