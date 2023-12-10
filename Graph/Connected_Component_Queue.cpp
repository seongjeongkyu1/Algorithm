#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 1001

int bfs(int start, int cnt);
vector<int> v[MAX];
bool visited[MAX];

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
        int a = bfs(j, 0);
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

int bfs(int start, int cnt) {
  queue<int> q;
  q.push(start);
  visited[start] = true;
  cnt++;

  while (!q.empty()) {
    int curr = q.front();
    q.pop();

    for (int i = 0; i < v[curr].size(); i++) {
      int next = v[curr][i];
      if (!visited[next]) {
        visited[next] = true;
        cnt++;
        q.push(next);
      }
    }
  }
  return cnt;
}