#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

#define MAX 1001

vector<int> v[MAX];
bool visited[MAX];
int dfs(int start);

int main() {
  int testNum;
  cin >> testNum;
  for (int i = 0; i < testNum; i++) {
    for (int j = 0; j < MAX; j++) {
      visited[j] = false;
      v[j].clear();
    }
    int num, cnt = 0;
    vector<int> answer;
    cin >> num;

    for (int j = 0; j < num; j++) {
      int n, m;
      cin >> n >> m;
      for (int k = 0; k < m; k++) {
        int data;
        cin >> data;
        v[n].push_back(data);
      }
    }
    for (int j = 1; j <= num; j++) {
      if (!visited[j]) {
        int a = dfs(j);
        answer.push_back(a);
        cnt++;
      }
    }
    sort(answer.begin(), answer.end());
    cout << cnt << " ";
    for (int j = 0; j < answer.size(); j++) {
      cout << answer[j] << " ";
    }
    cout << endl;
  }
}

int dfs(int start) {
  visited[start] = true;
  int count = 1;
  for (int i = 0; i < v[start].size(); i++) {
    int next = v[start][i];
    if (!visited[next]) {
      count += dfs(next);
    }
  }
  return count;
}