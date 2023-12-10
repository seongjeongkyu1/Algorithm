#include <climits>
#include <iostream>
using namespace std;

#define MAX 10

int CMM(int arr[], int i, int j) {
  if (i == j) return 0;

  int min = INT_MAX;
  int cnt = 0;

  int k = i;

  while (k < j) {
    int a = CMM(arr, i, k);
    int b = CMM(arr, k + 1, j);
    int c = arr[i - 1] * arr[k] * arr[j];
    cnt = a + b + c;

    if (cnt < min) min = cnt;
    k++;
  }

  return min;
}

int main() {
  int testNum, num, data;
  cin >> testNum;
  for (int i = 0; i < testNum; i++) {
    cin >> num;
    int arr[MAX];
    for (int j = 0; j <= num; j++) {
      cin >> data;
      arr[j] = data;
    }
    int answer = CMM(arr, 1, num);
    cout << answer << endl;
  }

  return 0;
}