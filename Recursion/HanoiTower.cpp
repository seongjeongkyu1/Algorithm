#include <cmath>
#include <iostream>
using namespace std;

void hanoi(int n, int a, int b, int c);
unsigned long long int k;

int main() {
  int testNum;
  cin >> testNum;

  for (int i = 0; i < testNum; i++) {
    int n;
    cin >> n >> k;
    hanoi(n, 1, 2, 3);
  }
  return 0;
}

void hanoi(int n, int a, int b, int c) {
  unsigned long long int tmp = pow(2, (n - 1));
  if (k == tmp) {
    cout << a << " " << c << endl;
    return;
  } else if (tmp > k) {
    hanoi(n - 1, a, c, b);
  } else {
    k -= tmp;
    hanoi(n - 1, b, a, c);
  }
}