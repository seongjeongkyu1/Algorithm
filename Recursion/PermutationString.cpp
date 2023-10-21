#include <iostream>
#include <string>
using namespace std;

void PermutationString(string str, int begin, int end);
void swap(int *a, int *b);
int cnt;

int main() {
  int testNum;
  cin >> testNum;
  for (int i = 0; i < testNum; ++i) {
    string str;
    cnt = 0;
    cin >> str;
    int len = str.length();
    PermutationString(str, 0, len);
    cout << cnt << endl;
  }
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void PermutationString(string str, int begin, int end) {
  int range = end - begin;
  if (range == 1) {
    int w = 0;
    for (int i = 0; i < str.length(); i++) {
      if (i % 2 == 0)
        w += str[i] - 'a';
      else
        w -= str[i] - 'a';
    }
    if (w > 0) cnt++;

  } else {
    for (int i = 0; i < range; i++) {
      swap(str[begin], str[begin + i]);
      PermutationString(str, begin + 1, end);
      swap(str[begin], str[begin + i]);
    }
  }
}