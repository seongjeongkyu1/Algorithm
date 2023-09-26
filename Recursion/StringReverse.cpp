#include <iostream>
#include <stack>
#include <string>
using namespace std;

string stringReverse(string s, int a, int b);
stack<char> stk;
int main() {
  int testNum;
  cin >> testNum;
  for (int i = 0; i < testNum; i++) {
    string str;
    cin >> str;
    cout << stringReverse(str, 0, str.length() - 1) << endl;
  }
}
string stringReverse(string s, int a, int b) {
  if (a < b) {
    stk.push(s[a]);
    s[a] = s[b];
    return stringReverse(s, a + 1, b - 1);
  } else if (a == b)
    return stringReverse(s, a + 1, b - 1);
  else {
    while (!stk.empty()) {
      //   cout << stk.top() << endl;
      //   cout << a << endl;
      s[a] = stk.top();
      stk.pop();
      a++;
    }
    return s;
  }
}