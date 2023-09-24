#include <stdio.h>

#include <iostream>
using namespace std;
#define MAX_SIZE 1000

void insertionSort(int a[], int n);
void swap(int &a, int &b);
int temp;

int main() {
  int numTestCases;
  cin >> numTestCases;
  for (int i = 0; i < numTestCases; ++i) {
    int num;
    int a[MAX_SIZE];
    cin >> num;
    for (int j = 0; j < num; j++) scanf("%d", &a[j]);
    insertionSort(a, num);
  }
  return 0;
}

void swap(int &a, int &b) {
  temp = a;
  a = b;
  b = temp;
}

/* Insertion Sort 함수 */
void insertionSort(int a[], int n) {
  int countCmpOps = 0;  // 비교 연산자 실행 횟수
  int countSwaps = 0;   // swap 함수 실행 횟수
  // insertion sort 알고리즘 구현
  for (int i = 1; i < n; i++) {
    for (int j = i; j > 0; j--) {
      countCmpOps++;
      if (a[j - 1] > a[j]) {
        swap(a[j - 1], a[j]);
        countSwaps++;
      } else
        break;
    }
  }
  cout << countCmpOps << ' ' << countSwaps << endl;
}