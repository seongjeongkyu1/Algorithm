#include <iostream>
using namespace std;

int factorial(int n);
int main() {
  int testNum;
  cin >> testNum;
  for (int i = 0; i < testNum; i++) {
    int num;
    cin >> num;
    cout << factorial(num) % 1000 << endl;
  }
}
int factorial(int n) {
  if (n <= 1)
    return 1;
  else {
    int res = factorial(n - 1) * n;
    while (!(res % 10)) res /= 10;
    return res % 10000;
  }
}