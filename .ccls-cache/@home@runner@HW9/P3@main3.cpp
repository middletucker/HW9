#include <iomanip>
#include <iostream>

using namespace std;

int TrueFalse(char matrix[][5], int R, int C);

int main() {
  double grades[6];
  double grade1, grade2, grade3, grade4, grade5, grade6;
  char tests[6][5] = {
      {'T', 'F', 'T', 'T', 'T'}, {'T', 'T', 'T', 'T', 'T'},
      {'T', 'T', 'F', 'F', 'T'}, {'F', 'T', 'F', 'F', 'F'},
      {'F', 'F', 'F', 'F', 'F'}, {'T', 'T', 'F', 'T', 'F'},
  };
  grades[0] = TrueFalse(tests, 0, 5);
  grades[1] = TrueFalse(tests, 1, 5);
  grades[2] = TrueFalse(tests, 2, 5);
  grades[3] = TrueFalse(tests, 3, 5);
  grades[4] = TrueFalse(tests, 4, 5);
  grades[5] = TrueFalse(tests, 5, 5);

  for (int i = 0; i < 6; i++) {
    cout << setw(6) << setprecision(3) << grades[i];
  }
}
int TrueFalse(char matrix[][5], int R, int C) {
  double count = 0, grade = 0;
  
  for (int j = 0; j < C; j++) {
    if (matrix[R][j] == 'T') {
      count = count + 5;
    }
  }

  grade = (count / 25) * 100;
  return grade;
}