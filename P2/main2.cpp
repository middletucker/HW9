/*
Lillian Tucker
CSCI130
10/25/2022
Description: Modified code from CSCI HW9/P1, that adds an eighth column to the
array. The grade in the eighth column is calculated by computing the average of
the top three grades only.
  */
#include <iomanip>
#include <iostream>

using namespace std;

// initialize functions
void printMatrix(double matrix[][8], int R, int C);
void Column8(double matrix[][8], int R, int C);

int main() {
  // initialize matrix
  double studentGrade[60][8] = {{1, 100, 100, 100, 100},
                                {2, 100, 0, 100, 0},
                                {3, 82, 94, 73, 86},
                                {4, 64, 74, 84, 94},
                                {5, 94, 84, 74, 64}};

  for (int i = 0; i < 5; i++) {
    for (int j = 1; j < 6; j++) {
      // grade average without weight
      studentGrade[i][5] = (studentGrade[i][1] + studentGrade[i][2] +
                            studentGrade[i][2] + studentGrade[i][4]) /
                           4;
      // grade average with weight
      studentGrade[i][6] =
          (studentGrade[i][1] * .2) + (studentGrade[i][2] * .3) +
          (studentGrade[i][2] * .3) + (studentGrade[i][4] * .2);
    }
  }
  // run functions
  Column8(studentGrade, 5, 4);
  printMatrix(studentGrade, 5, 8);
}

void printMatrix(double matrix[][8], int R, int C) {
  int row, col;
  for (row = 0; row < R; row++) {
    for (col = 0; col < C; col++)
      cout << setw(6) << setprecision(3) << matrix[row][col] << " ";

    cout << endl;
  }
}

void Column8(double matrix[][8], int R, int C) {
  int lowest;
  // finding lowest value in matrix
  for (int i = 0; i < R; i++) {
    for (int j = 1; j < C; j++) {
      if (matrix[i][j] < lowest) {
        lowest = matrix[i][j];
      }
    }
    // calculate grade average without lowest score
    matrix[i][7] =
        (matrix[i][1] + matrix[i][2] + matrix[i][3] + matrix[i][4] - lowest) /
        3;

    // "reset" lowest value so it can be replaced by next calculation
    lowest = 200;
  }
}