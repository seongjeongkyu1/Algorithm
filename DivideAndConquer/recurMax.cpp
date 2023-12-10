#include <algorithm>
#include <iostream>
using namespace std;

#define MAX_SIZE 100

int recurMax(int a[], int left, int right);

int main() {
  int testNum;
  cin >> testNum;
  for (int i = 0; i < testNum; i++) {
    int sz;
    int a[100];
    cin >> sz;
    for (int j = 0; j < sz; j++) {
      cin >> a[j];
    }
    cout << recurMax(a, 0, sz - 1) << endl;
  }
}

int recurMax(int a[], int left, int right) {
  int mid;

  if (left == right)
    return a[left];
  else {
    mid = (left + right) / 2;
    return max(recurMax(a, left, mid), recurMax(a, mid + 1, right));
  }
}