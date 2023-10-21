#include <algorithm>
#include <iostream>
using namespace std;

void findNextPermutation(string &str, int num);
void swap(int *a, int *b);

int main() {
  int testNum;
  cin >> testNum;
  for (int i = 0; i < testNum; i++) {
    int num;
    string str;
    cin >> num >> str;
    findNextPermutation(str, num);
  }
}

void findNextPermutation(string &str, int num) {
  int i = num - 2;
  if (i >= 0 && int(str[i]) >= int(str[i + 1])) {
    // cout << int(str[i]) << str[i] << int(str[i + 1]) << str[i + 1] << endl;
    findNextPermutation(str, num - 1);
    return;
  }
  if (i >= 0) {
    int j = num;
    while (j >= 0 && int(str[j] <= int(str[i]))) j--;
    swap(str[i], str[j]);
    // cout << str << endl;
  }
  reverse(str.begin() + i + 1, str.end());
  cout << str << endl;
}
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
