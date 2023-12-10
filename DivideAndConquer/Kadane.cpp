#include <iostream>
#include <vector>
using namespace std;

int kadane(int a[], int sz, int *start, int *end);

int main() {
  int testNum;
  cin >> testNum;
  for (int i = 0; i < testNum; i++) {
    int sz, a[100];
    int start = -1;
    int end = -1;
    cin >> sz;
    for (int i = 0; i < sz; i++) {
      cin >> a[i];
    }
    cout << kadane(a, sz, &start, &end) << " " << start << " " << end << endl;
  }
}

int kadane(int a[], int sz, int *start, int *end) {
  int i, j;
  int maxSum = 0, thisSum = 0;
  for (i = 0, j = 0; j < sz; j++) {
    thisSum += a[j];
    if (thisSum > maxSum) {
      maxSum = thisSum;
      *start = i;
      *end = j;
    } else if (thisSum <= 0) {
      i = j + 1;
      thisSum = 0;
    }
  }
  return maxSum;
}