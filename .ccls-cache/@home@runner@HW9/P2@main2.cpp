#include <iomanip>
#include <iostream>

using namespace std;

void printMatrix(double matrix[][8], int R, int C);
void Column8(double matrix[][8], int R, int C);

int main() {
  double studentGrade[60][8] = {{1, 100, 100, 100, 100},
                                {2, 100, 0, 100, 0},
                                {3, 82, 94, 73, 86},
                                {4, 64, 74, 84, 94},
                                {5, 94, 84, 74, 64}};

  for (int i = 0; i < 5; i++) {
    for (int j = 1; j < 6; j++) {
      studentGrade[i][5] = (studentGrade[i][1] + studentGrade[i][2] +
                            studentGrade[i][2] + studentGrade[i][4]) /
                           4;
      studentGrade[i][6] =
          (studentGrade[i][1] * .2) + (studentGrade[i][2] * .3) +
          (studentGrade[i][2] * .3) + (studentGrade[i][4] * .2);
      // Column8(studentGrade, i, j);
    }
  }
  Column8(studentGrade, 5, 8);
  printMatrix(studentGrade, 5, 8);
}

void printMatrix(double matrix[][8], int R, int C) {
  int row, col;
  for (row = 0; row < R; row++) {
    for (col = 0; col < C; col++)
      cout << setw(6) << matrix[row][col] << " ";

    cout << endl;
  }
}

void Column8(double matrix[][8], int R, int C) {
  int lowest;
  for (int i = 0; i < R; i++) {
    for (int j = 1; j < C; j++) {
      if (matrix[i][C] <= lowest) {
        lowest = matrix[i][C];
      }
    }
    matrix[i][7] =
        (matrix[i][1] + matrix[i][2] + matrix[i][2] + matrix[i][4] - lowest) /
        4;
  }
}