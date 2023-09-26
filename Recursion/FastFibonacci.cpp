#include <iostream>
using namespace std;

void multiplyMatrix(long long A[2][2], long long B[2][2]);
void power(long long matrix[2][2], int num);

long long fibonacci(int n);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int numTestCases;
  cin >> numTestCases;

  for (int i = 0; i < numTestCases; ++i) {
    long long n;
    cin >> n;
    cout << fibonacci(n) << endl;
  }
}

void multiplyMatrix(long long A[2][2], long long B[2][2]) {
  long long result[2][2] = {{0, 0}, {0, 0}};

  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 2; k++) result[i][j] += A[i][k] * B[k][j] % 10000;

  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) A[i][j] = result[i][j];
}

void power(long long matrix[2][2], int num) {
  if (num <= 1) return;

  long long baseMatrix[2][2] = {{1, 1}, {1, 0}};
  power(matrix, num / 2);
  multiplyMatrix(matrix, matrix);

  if (num % 2 != 0) {
    long long temp[2][2];
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++) temp[i][j] = matrix[i][j];

    multiplyMatrix(matrix, baseMatrix);
  }
}

long long fibonacci(int n) {
  long long matrix[2][2] = {{1, 1}, {1, 0}};

  if (n <= 1)
    return n;
  else if (n == 2)
    return 1;
  else
    power(matrix, n - 1);

  return matrix[0][0] % 1000;
}
