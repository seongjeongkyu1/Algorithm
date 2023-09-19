#include <iostream>
using namespace std;
#include <stdio.h>
#define MAX_SIZE 1000

void selectionSort(int a[], int n);
void swap(int &a, int &b);
int temp;

int main() {
  int numTestCases;
  // scanf("%d", &numTestCases);
  cin >> numTestCases;
  for (int i = 0; i < numTestCases; ++i) {
    int num;
    int a[MAX_SIZE];
    // scanf("%d", &num);
    cin >> num;
    for (int j = 0; j < num; j++) scanf("%d", &a[j]);
    selectionSort(a, num);
  }
  return 0;
}

void swap(int &a, int &b) {
  temp = a;
  a = b;
  b = temp;
}

/* Selection Sort 함수 */
void selectionSort(int a[], int n) {
  int countCmpOps = 0;  // 비교 연산자 실행 횟수
  int countSwaps = 0;   // swap 함수 실행 횟수
  // selection sort 알고리즘 구현
  for (int i = 0; i < n - 1; i++) {
    int jMin = i;
    for (int j = i + 1; j < n; j++) {
      countCmpOps++;
      if (a[jMin] > a[j]) {
        jMin = j;
      }
    }
    if (jMin != i) {
      countSwaps++;
      swap(a[jMin], a[i]);
    }
  }

  // printf("%d %d", countCmpOps, countSwaps);
  cout << countCmpOps << " " << countSwaps << endl;
}