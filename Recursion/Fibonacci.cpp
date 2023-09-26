#include <iostream>
using namespace std;

int fibonacci(int n);
int main() {
  int testNum;
  cin >> testNum;
  for (int i = 0; i < testNum; i++) {
    int num;
    cin >> num;
    cout << fibonacci(num) << endl;
  }
}
int fibonacci(int n) {
  if (n <= 1)
    return n;
  else
    return fibonacci(n - 1) + fibonacci(n - 2);
}