#include <iostream>
using namespace std;

int gcd(int a, int b);
int main() {
  int testNum;
  cin >> testNum;
  for (int i = 0; i < testNum; i++) {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
  }
}

int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}