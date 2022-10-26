/*
Lillian Tucker
CSCI130
10/25/2022
Description: Given a two dimensional answer array, in which each row corresponds
to the answers provided on one test, write a function that accepts the
two-dimensional array and number of tests as parameters and returns a
one-dimensional array containing the grades for each test. (Each question is
worth 5 points, so the maximum possible grade is 25.)
  */
#include <iomanip>
#include <iostream>

using namespace std;

// initialize function
int TrueFalse(char matrix[][5], int R, int C);

int main() {
  // initialize variables and matrix
  double grades[6];
  double grade1, grade2, grade3, grade4, grade5, grade6;
  char tests[6][5] = {
      {'T', 'F', 'T', 'T', 'T'}, {'T', 'T', 'T', 'T', 'T'},
      {'T', 'T', 'F', 'F', 'T'}, {'F', 'T', 'F', 'F', 'F'},
      {'F', 'F', 'F', 'F', 'F'}, {'T', 'T', 'F', 'T', 'F'},
  };

  // assign values to grades array
  grades[0] = TrueFalse(tests, 0, 5);
  grades[1] = TrueFalse(tests, 1, 5);
  grades[2] = TrueFalse(tests, 2, 5);
  grades[3] = TrueFalse(tests, 3, 5);
  grades[4] = TrueFalse(tests, 4, 5);
  grades[5] = TrueFalse(tests, 5, 5);

  // print cases in a row
  for (int i = 0; i < 6; i++) {
    cout << setw(10) << "Student " << i + 1;
  }
  cout << endl;
  for (int i = 0; i < 6; i++) {
    cout << setw(10) << setprecision(3) << grades[i];
  }
  cout << endl << endl;

  // print cases in a column
  for (int i = 0; i < 6; i++) {
    cout << setw(10) << "Student " << i + 1;
    cout << setw(10) << setprecision(3) << grades[i] << endl;
  }
}
int TrueFalse(char matrix[][5], int R, int C) {
  double count = 0, grade = 0; // resetting values for each run

  // checking each column for correct answer
  for (int j = 0; j < C; j++) {
    if (matrix[R][j] == 'T') {
      count = count + 5;
    }
  }

  grade = (count / 25) * 100;
  return grade;
}