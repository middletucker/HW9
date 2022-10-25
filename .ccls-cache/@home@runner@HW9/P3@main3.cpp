#include <iomanip>
#include <iostream>

using namespace std;

int TrueFalse(char matrix[][5], int R, int C);

int main() {
  int grade1, grade2, grade3, grade4, grade5, grade6;
  char tests[6][5] = {
      {'T', 'F', 'T', 'T', 'T'}, {'T', 'T', 'T', 'T', 'T'},
      {'T', 'T', 'F', 'F', 'T'}, {'F', 'T', 'F', 'F', 'F'},
      {'F', 'F', 'F', 'F', 'F'}, {'T', 'T', 'F', 'T', 'F'},
  };
  grade1 = TrueFalse(char matrix[][5], int R, int C);
}
int TrueFalse(char matrix[][5], int R, int C) {
  int count, grade;
  for (int i = 0; i == R; i++) {
    for (int j = 1; j < C; j++) {
      if (matrix[i][j] == 'T') {
        count = count + 5;
      }
    }
    grade = count / C;
    return grade;
  }