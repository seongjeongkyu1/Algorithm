#include <algorithm>
#include <iostream>
using namespace std;

void merge(int a[], int low, int mid, int high);
void mergeSort(int a[], int sz);
int cnt;

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
    mergeSort(a, sz);
    cout << cnt << endl;
    cnt = 0;
  }
}

void merge(int a[], int low, int mid, int high) {
  int i, j, k;
  int tmp[100];
  for (i = low; i <= high; i++) {
    tmp[i] = a[i];
  }

  i = k = low;
  j = mid + 1;
  while (i <= mid && j <= high) {
    if (tmp[i] <= tmp[j]) {
      a[k++] = tmp[i++];
    } else {
      a[k++] = tmp[j++];
    }
    cnt++;
  }
  while (i <= mid) {
    a[k++] = tmp[i++];
  }
  while (j <= high) {
    a[k++] = tmp[j++];
  }
}

void mergeSort(int a[], int sz) {
  int size = 1;
  int low, mid, high;

  while (size < sz) {
    for (int i = 0; i < sz; i += 2 * size) {
      low = i;
      mid = min(low + size - 1, sz - 1);
      high = min(i + 2 * size - 1, sz - 1);

      merge(a, low, mid, high);
    }
    size *= 2;
  }
}