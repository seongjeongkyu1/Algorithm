#include <iostream>
using namespace std;

#define MAX_SIZE 100

int binarySearch(int a[], int left, int right, int value);
int main() {
  int testNum;
  cin >> testNum;
  for (int i = 0; i < testNum; i++) {
    int num, value, a[MAX_SIZE], left, right;
    cin >> num >> value;
    for (int i = 0; i < num; i++) {
      cin >> a[i];
    }
    cout << binarySearch(a, 0, num - 1, value) << endl;
  }
}

int binarySearch(int a[], int left, int right, int value) {
  int mid;

  if (left > right) {
    return -1;
  } else {
    mid = (left + right) / 2;
    if (a[mid] == value) {
      return mid;
    } else if (a[mid] > value) {
      return binarySearch(a, left, mid - 1, value);
    } else {
      return binarySearch(a, mid + 1, right, value);
    }
  }
}