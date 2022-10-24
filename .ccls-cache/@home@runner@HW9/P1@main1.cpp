#include <iomanip>
#include <iostream>

using namespace std;

void printMatrix(double matrix[][7], int R, int C);

int main() {
  int R = 5, C = 7;
  double studentGrade[60][7] = {{1, 100, 100, 100, 100},
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
    }
  }

  printMatrix(studentGrade, R, C);
}

void printMatrix(double matrix[][7], int R, int C) {
  int row, col;
  for (row = 0; row < R; row++) {
    for (col = 0; col < C; col++)
      cout << setw(6) << matrix[row][col] << " ";

    cout << endl;
  }
}