#include <stdio.h>

#include <iostream>
using namespace std;

#define MAX_SIZE 1000
void bubbleSort(int a[], int n);
void bubbleSortImproved1(int a[], int n);
void bubbleSortImproved2(int a[], int n);
void copyArray(int a[], int b[], int n);
void swap(int &a, int &b);
int temp;

int main() {
  int numTestCases;
  cin >> numTestCases;
  for (int i = 0; i < numTestCases; ++i) {
    int num;
    int a[MAX_SIZE], b[MAX_SIZE];
    cin >> num;
    for (int j = 0; j < num; j++) scanf("%d", &b[j]);
    copyArray(a, b, num);
    bubbleSort(a, num);
    copyArray(a, b, num);
    bubbleSortImproved1(a, num);
    copyArray(a, b, num);
    bubbleSortImproved2(a, num);
    printf("\n");
  }
  return 0;
}

void swap(int &a, int &b) {
  temp = a;
  a = b;
  b = temp;
}

/* BubbleSort 함수 */
void bubbleSort(int a[], int n) {
  int countCmpOps = 0;  // 비교 연산자 실행 횟수
  int countSwaps = 0;   // swap 함수 실행 횟수
  // bubble sort 알고리즘 구현
  for (int pass = 1; pass < n; pass++) {
    for (int i = 1; i <= n - pass; i++) {
      countCmpOps++;
      if (a[i - 1] > a[i]) {
        countSwaps++;
        swap(a[i - 1], a[i]);
      }
    }
  }
  cout << countCmpOps << " " << countSwaps << " ";
}

/* BubbleSort 함수 - Improved Version 1 */
void bubbleSortImproved1(int a[], int n) {
  int countCmpOps = 0;  // 비교 연산자 실행 횟수
  int countSwaps = 0;   // swap 함수 실행 횟수
  // bubble sort의 개선된 알고리즘 (1) 구현
  for (int pass = 1; pass < n; pass++) {
    bool swapped = false;
    for (int i = 1; i <= n - pass; i++) {
      countCmpOps++;
      if (a[i - 1] > a[i]) {
        countSwaps++;
        swapped = true;
        swap(a[i - 1], a[i]);
      }
    }
    if (swapped == false) break;
  }

  cout << countCmpOps << " " << countSwaps << " ";
}
/* BubbleSort 함수 - Improved Version 2 */
void bubbleSortImproved2(int a[], int n) {
  int countCmpOps = 0;  // 비교 연산자 실행 횟수
  int countSwaps = 0;   // swap 함수 실행 횟수
  // bubble sort의 개선된 알고리즘 (2) 구현
  int lastSwapedPos = n;

  while (lastSwapedPos > 0) {
    int swappedPos = 0;
    for (int i = 1; i < lastSwapedPos; i++) {
      countCmpOps++;
      if (a[i - 1] > a[i]) {
        swap(a[i - 1], a[i]);
        countSwaps++;
        swappedPos = i;
      }
    }
    lastSwapedPos = swappedPos;
  }
  cout << countCmpOps << " " << countSwaps;
}
void copyArray(int a[], int b[], int n) {
  for (int i = 0; i < n; i++) a[i] = b[i];
}