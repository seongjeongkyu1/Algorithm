#include <algorithm>
#include <iostream>
using namespace std;

#define MAX_LENGTH 101

int L[MAX_LENGTH][MAX_LENGTH], S[MAX_LENGTH][MAX_LENGTH];

int LCS_DP(char s[], char t[], int m, int n);
void printLCS(char s[], char t[], int m, int n);

int main() {
  int testNum;
  cin >> testNum;
  for (int i = 0; i < testNum; i++) {
    char s[MAX_LENGTH], t[MAX_LENGTH];
    cin >> s;
    cin >> t;
    int m, n;
    for (m = 0; s[m] != 0;) m++;
    for (n = 0; t[n] != 0;) n++;
    for (int i = 0; i < MAX_LENGTH; i++) {
      for (int j = 0; j < MAX_LENGTH; j++) {
        L[i][j] = -1;
      }
    }
    cout << LCS_DP(s, t, m, n) << " ";
    printLCS(s, t, m, n);
    cout << endl;
  }
}

int LCS_DP(char s[], char t[], int m, int n) {
  for (int i = 0; i <= m; i++) L[i][0] = 0;
  for (int i = 0; i <= n; i++) L[0][i] = 0;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (s[i - 1] == t[j - 1]) {
        L[i][j] = L[i - 1][j - 1] + 1;
        S[i][j] = 0;
      } else {
        L[i][j] = max(L[i][j - 1], L[i - 1][j]);
        if (L[i][j] == L[i][j - 1]) {
          S[i][j] = 1;
        } else {
          S[i][j] = 2;
        }
      }
    }
  }
  return L[m][n];
}

void printLCS(char s[], char t[], int m, int n) {
  char arr[MAX_LENGTH] = {};
  int idx = 0;
  while (m != 0 and n != 0) {
    if (S[m][n] == 0) {
      arr[idx] = s[m - 1];
      m--;
      n--;
      idx++;
    } else if (S[m][n] == 1)
      n--;
    else if (S[m][n] == 2)
      m--;
  }
  for (int i = idx - 1; i >= 0; i--) cout << arr[i];
}