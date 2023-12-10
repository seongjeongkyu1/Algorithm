#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

#define MAX 101

int mat[MAX][MAX];

int CMM(int arr[], int i, int j) {
  if (i == j) return 0;

  if (mat[i][j] != -1) return mat[i][j];

  mat[i][j] = INT_MAX;

  for (int k = i; k < j; k++) {
    int tmp = CMM(arr, i, k);
    int tmp2 = CMM(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];

    mat[i][j] = min(mat[i][j], tmp + tmp2);
  }

  return mat[i][j];
}
int CMM_Memoization(int* arr, int i, int j) {
  for (int a = 0; a <= MAX; a++) {
    for (int b = 0; b <= MAX; b++) {
      mat[a][b] = -1;
    }
  }
  return CMM(arr, i, j);
}

int main(void) {
  int testNum, num, data;

  cin >> testNum;
  for (int i = 0; i < testNum; i++) {
    cin >> num;
    int* arr = new int[num + 1];
    for (int j = 0; j <= num; j++) {
      cin >> data;
      arr[j] = data;
    }
    int ans = CMM_Memoization(arr, 1, num);
    cout << ans << endl;
  }
  return 0;
}