#include <iostream>
#include <climits>
using namespace std;

#define MAX 101

int mat[MAX][MAX], P[MAX][MAX];

int CMM(int arr[], int num) {
  for (int i = 0; i < num; i++) mat[i][i] = 0;

  for (int diagonal = 1; diagonal < num; diagonal++) {
    for (int j = 1; j < num - diagonal; j++) {
      int k = diagonal + j;
      mat[j][k] = INT_MAX;

      for (int L = j; L <= k - 1; L++) {
        int sum = mat[j][L] + mat[L + 1][k] + arr[j - 1] * arr[L] * arr[k];
        if (sum < mat[j][k]) {
          mat[j][k] = sum;
          P[j][k] = L;
        }
      }
    }
  }
  return mat[1][num - 1];
}

void order(int i, int j) {
  if (i == j) cout << "M" << i;
  else {
    int k = P[i][j];
    cout << "(";
    order(i, k);
    order(k + 1, j);
    cout << ")";
  }
}

int main() {
  int testNum, num, data;
  cin >> testNum;
  for (int i = 0; i < testNum; i++) {
    cin >> num;
    int* arr = new int[num + 1];
    for (int j = 0; j <= num; j++) {
      cin >> data;
      arr[j] = data;
    }
    int answer = CMM(arr, num + 1);
    order(1, num);
    cout << endl << answer << endl;
  }
  return 0;
}