/*
Lillian Tucker
CSCI130
10/25/2022
Description: A program that determines grades at the end of the semester. For each student, identified by an integer number between 1 and 60, four exam grades must be kept, and two final grade averages must be computed. The first grade average is simply the average of all four grades. The second grade average is computed by weighting the four grades as follows: The first grade gets a weight of 0.2, the second grade gets a weight of 0.3, the third grade gets a weight of 0.3, and the fourth grade gets a weight of 0.2. That is, the final grade is computed as follows:
0.2 * grade1 + 0.3 * grade2 + 0.3 * grade3 + 0.2 * grade4
  */
#include <iomanip>
#include <iostream>

using namespace std;

// Initialize function
void printMatrix(double matrix[][7], int R, int C);

int main() {
  // initialize variables and matrix
  int R = 5, C = 7;
  double studentGrade[60][7] = {{1, 100, 100, 100, 100},
                                {2, 100, 0, 100, 0},
                                {3, 82, 94, 73, 86},
                                {4, 64, 74, 84, 94},
                                {5, 94, 84, 74, 64}};

  for (int i = 0; i < 5; i++) {
    for (int j = 1; j < 6; j++) {
      // student grade average (no weight)
      studentGrade[i][5] = (studentGrade[i][1] + studentGrade[i][2] +
                            studentGrade[i][2] + studentGrade[i][4]) /
                           4;
      // student grade average (weighted)
      studentGrade[i][6] =
          (studentGrade[i][1] * .2) + (studentGrade[i][2] * .3) +
          (studentGrade[i][2] * .3) + (studentGrade[i][4] * .2);
    }
  }

  printMatrix(studentGrade, R, C);
}
// function to print matrix
void printMatrix(double matrix[][7], int R, int C) {
  int row, col;
  for (row = 0; row < R; row++) {
    for (col = 0; col < C; col++)
      cout << setw(6) << matrix[row][col] << " ";

    cout << endl;
  }
}