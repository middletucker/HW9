/******************************************************************************
 CSCI 130: Matrix Example
*******************************************************************************/
#include <iomanip>
#include <iostream>
using namespace std;

// function prototypes
void printMatrix_3col(int matrix[][3], int N_ROWS, int C);
int CountUnhealthySensitive(int matrix[][3], int N_ROWS, int C);
int meanAirQualityIndex(int matrix[][3], int N_ROWS, int C);

////////////////////// MAIN ///////////////////////////////////////
int main() {
  const int n_rows = 10;
  const int city_col = 3;
  int G_Avg = 0, F_Avg = 0, D_Avg = 0, G_Result = 0, F_Result = 0, D_Result = 0;
  int AirQuality_Index[n_rows][city_col] = {
      {50, 68, 58},   {58, 115, 78}, {62, 110, 81}, {66, 124, 110},
      {64, 152, 121}, {46, 143, 90}, {46, 143, 90}, {25, 91, 91},
      {27, 19, 59},   {17, 13, 27}};

  printMatrix_3col(AirQuality_Index, n_rows, city_col);

  // Determine and print unhealthy air index for each city
  G_Result = CountUnhealthySensitive(AirQuality_Index, n_rows, 1);
  cout << G_Result << endl;
  F_Result = CountUnhealthySensitive(AirQuality_Index, n_rows, 2);
  cout << F_Result << endl;
  D_Result = CountUnhealthySensitive(AirQuality_Index, n_rows, 3);
  cout << D_Result << endl;
  cout << endl;

  // Determine and print average air index
  G_Avg = meanAirQualityIndex(AirQuality_Index, n_rows, 1);
  F_Avg = meanAirQualityIndex(AirQuality_Index, n_rows, 2);
  D_Avg = meanAirQualityIndex(AirQuality_Index, n_rows, 3);

  cout << "From 10/4/2020 to 10/13/2020, the averge air quality in: \n";
  cout << "Grand Junction: " << G_Avg << endl;
  cout << "Fort Collins: " << F_Avg << endl;
  cout << "Denver/Boulder: " << D_Avg << endl;

  return 0;
}

/////////////// USER-DEFINED MATRIX FUNCTIONS ////////////////////////////
// Recall: you can omit the size of the first dimension, but not the second

// function to print the matrix in a matrix with 3 columns
void printMatrix_3col(int matrix[][3], int N_ROWS, int C) {
  int row, col;
  for (row = 0; row < N_ROWS; row++) {
    for (col = 0; col < C; col++)
      cout << setw(6) << matrix[row][col] << " ";

    cout << endl;
  }
}

int CountUnhealthySensitive(int matrix[][3], int N_ROWS, int C) {
  int row, col, count = 0, unhealthy_level = 101;
  for (row = 0; row < N_ROWS; row++) {

    if (matrix[row][C] >= unhealthy_level) {
      count++;
    }
  }
  return count;
}

int meanAirQualityIndex(int matrix[][3], int N_ROWS, int C) {
  int sum = 0;
  int avg = 0;

  for (int i = 0; i < N_ROWS; i++) {
    sum = sum + matrix[i][C];
    cout << matrix[i][C] << "    ";
  }

  avg = sum / N_ROWS;
  // cout << sum << endl;
  // cout << avg << endl;
  return avg;
}