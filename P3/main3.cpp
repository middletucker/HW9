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
  grades[0] = TrueFalse(tests, 0, 4);
  grades[1] = TrueFalse(tests, 1, 4);
  grades[2] = TrueFalse(tests, 2, 4);
 
}
int TrueFalse(char matrix[][5], int R, int C) {
  double count = 0, grade = 0;
  // for (int i = 0; i == R; i++) {
  for (int j = 0; j < C; j++) {
    if (matrix[R][j] == 'T') {
      count = count + 5;
    }
  }
  // }
  cout << count << endl;
  grade = (count / (C * 5)) * 100;
  return grade;
}