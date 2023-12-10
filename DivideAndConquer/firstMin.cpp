#include <iostream>
using namespace std;

int main() {
  int testNum;
  cin >> testNum;
  for (int i = 0; i < testNum; i++) {
    int sz, cnt = 0;
    int a[1000];
    cin >> sz;
    if (sz == 1) {
      cin >> a[0];
      cout << 1 << endl;
      continue;
    }
    int sum = 0;
    for (int j = 0; j < sz; j++) {
      cin >> a[j];
    }
    int tmp = a[0];
    for (int k = 0; k < sz; k++) {
      if (tmp <= a[k]) {
        // cout << tmp << " " << a[k] << endl;
        cnt++;
        if (cnt > sum) sum = cnt;
      } else {
        tmp = a[k];
        k--;
        cnt = 0;
      }
    }
    cout << sum << endl;
  }
}