#include <stdio.h>

#include <iostream>
using namespace std;
#define MAX_SIZE 1000

void ShellSort(int a[], int n);
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
    ShellSort(a, num);
  }
  return 0;
}

void swap(int &a, int &b) {
  temp = a;
  a = b;
  b = temp;
}

/* Shell Sort 함수 */
void ShellSort(int a[], int n) {
  int countCmpOps = 0;  // 비교 연산자 실행 횟수
  int countSwaps = 0;   // swap 함수 실행 횟수

  // Shell sort 알고리즘 구현
  int shrinkRatio = 2;
  int gap = n / shrinkRatio;
  while (gap > 0) {
    for (int i = gap; i < n; i++) {
      int tmp = a[i];
      for (int j = i; j >= gap; j -= gap) {
        countCmpOps++;
        if ((a[j - gap] > tmp)) {
          swap(a[j - gap], a[j]);
          countSwaps++;
        } else {
          break;
        }
      }
    }
    gap /= shrinkRatio;
  }
  cout << countCmpOps << " " << countSwaps << endl;
}