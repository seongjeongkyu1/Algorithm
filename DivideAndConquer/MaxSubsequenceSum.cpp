#include <algorithm>
#include <iostream>
using namespace std;

int maxSubsequenceSum(int a[], int start, int end);

int main() {
  int testNum;
  cin >> testNum;

  for (int i = 0; i < testNum; i++) {
    int a[100], sz;
    cin >> sz;
    for (int i = 0; i < sz; i++) {
      cin >> a[i];
    }
    cout << maxSubsequenceSum(a, 0, sz - 1) << endl;
  }
}

int maxSubsequenceSum(int a[], int start, int end) {
  if (start == end) return a[start];
  int mid = (start + end) / 2;
  int sum = 0;
  int left = -1000, right = -1000;
  int rec;

  for (int i = mid + 1; i <= end; i++) {
    sum += a[i];
    right = max(right, sum);
  }
  sum = 0;
  for (int i = mid; i >= start; i--) {
    sum += a[i];
    left = max(left, sum);
  }

  rec =
      max(maxSubsequenceSum(a, start, mid), maxSubsequenceSum(a, mid + 1, end));
  //   cout << rec << endl;
  int res = max(left + right, rec);
  return res < 0 ? 0 : res;
  cout << res << endl;
}