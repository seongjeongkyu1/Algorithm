#include <algorithm>
#include <iostream>
#include <set>
#include <stack>
#include <vector>
#define MAX 1001

using namespace std;

vector<vector<int>> graph;
vector<int> visited;
vector<int> low;
set<int> cutPoints;
vector<vector<pair<int, int>>> biconnectedComponents;
stack<pair<int, int>> st;
int cnt = 0;

void dfs(int node, int parent) {
  visited[node] = cnt++;
  low[node] = visited[node];

  int childCount = 0;
  bool isCutPoint = false;

  for (int next : graph[node]) {
    if (next == parent) continue;

    if (visited[next] == -1) {
      st.push({node, next});
      childCount++;

      dfs(next, node);

      if (low[next] >= visited[node]) {
        isCutPoint = true;
        vector<pair<int, int>> edges;
        while (st.top() != make_pair(node, next)) {
          edges.push_back(st.top());
          st.pop();
        }
        edges.push_back(st.top());
        st.pop();
        biconnectedComponents.push_back(edges);
      }

      low[node] = min(low[node], low[next]);
    } else {
      low[node] = min(low[node], visited[next]);
      if (visited[next] < visited[node]) {
        st.push({node, next});
      }
    }
  }

  if (parent == -1 && childCount >= 2) {
    cutPoints.insert(node);
  } else if (parent != -1 && isCutPoint) {
    cutPoints.insert(node);
  }
}

void findBiconnectedComponents(int n) {
  visited.assign(n + 1, -1);
  low.assign(n + 1, -1);

  for (int i = 1; i <= n; ++i) {
    if (visited[i] == -1) {
      dfs(i, -1);
    }
  }
}

int main() {
  int testNum;
  cin >> testNum;
  for (int k = 0; k < testNum; k++) {
    int n;
    cin >> n;

    // 그래프 초기화
    graph.assign(n + 1, vector<int>());
    visited.assign(n + 1, -1);
    low.assign(n + 1, -1);
    cutPoints.clear();
    biconnectedComponents.clear();
    cnt = 0;

    for (int i = 0; i < n; i++) {
      int node, m;
      cin >> node >> m;
      for (int j = 0; j < m; j++) {
        int input;
        cin >> input;
        graph[node].push_back(input);
      }
      sort(graph[node].begin(), graph[node].end());
    }

    findBiconnectedComponents(n);

    cout << biconnectedComponents.size() << endl;
    cout << cutPoints.size() << " ";

    if (cutPoints.size() != 0) {
      for (auto point : cutPoints) {
        cout << point << " ";
      }
    }
    cout << endl;
  }

  return 0;
}
