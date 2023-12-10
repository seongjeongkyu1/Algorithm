#include <iostream>
using namespace std;

void swap(int *a, int *b);
void quicksort_Hoare(int a[], int low, int high);
int partition_Hoare(int a[], int low, int high);
void quicksort_Lomuto(int a[], int low, int high);
int partition_Lomuto(int a[], int low, int high);
int swapH = 0, swapL = 0, cntH = 0, cntL = 0;

int main() {
  int testNum;
  cin >> testNum;
  for (int i = 0; i < testNum; i++) {
    int num, a[1000], b[1000];
    cin >> num;
    for (int j = 0; j < num; j++) {
      cin >> a[j];
      b[j] = a[j];
    }
    quicksort_Hoare(a, 0, num - 1);
    quicksort_Lomuto(b, 0, num - 1);
    cout << swapH << " " << swapL << " " << cntH << " " << cntL << endl;
    swapH = 0, swapL = 0, cntH = 0, cntL = 0;
  }
}

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void quicksort_Hoare(int a[], int low, int high) {
  if (low >= high) return;

  int p = partition_Hoare(a, low, high);
  quicksort_Hoare(a, low, p);
  quicksort_Hoare(a, p + 1, high);
}

int partition_Hoare(int a[], int low, int high) {
  int pivot = a[low];
  int i = low - 1;
  int j = high + 1;

  while (true) {
    do {
      i++;
      cntH++;
    } while (a[i] < pivot);
    do {
      j--;
      cntH++;
    } while (a[j] > pivot);
    if (i < j) {
      swap(&a[i], &a[j]);
      swapH++;
    } else
      return j;
  }
}

void quicksort_Lomuto(int a[], int low, int high) {
  if (low >= high) return;
  int p = partition_Lomuto(a, low, high);
  quicksort_Lomuto(a, low, p - 1);
  quicksort_Lomuto(a, p + 1, high);
}

int partition_Lomuto(int a[], int low, int high) {
  int pivot = a[low];
  int j = low;
  for (int i = low + 1; i <= high; i++) {
    cntL++;
    if (a[i] < pivot) {
      j++;
      cout << a[i] << " " << a[j] << endl;
      swap(&a[i], &a[j]);
      swapL++;
    }
  }
  int pivot_pos = j;
  swapL++;
  cout << a[pivot_pos] << " " << a[low] << endl;
  swap(&a[pivot_pos], &a[low]);
  return pivot_pos;
}
