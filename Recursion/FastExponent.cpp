#include <iostream>
using namespace std;

int fastExponentiation(int a, int b);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int numTestCases;
  cin >> numTestCases;
  for (int i = 0; i < numTestCases; i++) {
    int a, b;
    cin >> a >> b;
    cout << fastExponentiation(a, b) << endl;
  }
}

int fastExponentiation(int a, int b) {
  int num;
  if (b == 0)
    return 1;
  else if (b % 2 != 1) {
    num = fastExponentiation(a, b / 2);
    return num * num % 1000;
  } else {
    num = fastExponentiation(a, (b - 1) / 2);
    return a * num * num % 1000;
  }
}