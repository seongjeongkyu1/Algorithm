#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int prim(vector<vector<pair<int, int>>>& graph, int start_node);

int main() {
  int testNum;
  cin >> testNum;

  for (int i = 0; i < testNum; i++) {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> graph(n + 1);

    for (int i = 1; i <= n; i++) {
      int k, m;
      cin >> k >> m;

      for (int j = 0; j < m; j++) {
        int v, w;
        cin >> v >> w;
        graph[k].push_back({v, w});
      }
    }

    int start_node = 1;
    int total_weight = prim(graph, start_node);

    cout << total_weight << endl;
  }

  return 0;
}

int prim(vector<vector<pair<int, int>>>& graph, int start_node) {
  int n = graph.size() + 1;
  vector<bool> visited(n + 1, false);
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;

  visited[start_node] = true;

  for (auto edge : graph[start_node]) {
    pq.push({edge.second, edge.first});
  }

  int total_weight = 0;

  while (!pq.empty()) {
    pair<int, int> edge = pq.top();
    pq.pop();

    int weight = edge.first;
    int node = edge.second;

    if (!visited[node]) {
      visited[node] = true;
      total_weight += weight;

      for (auto edge : graph[node]) {
        pq.push({edge.second, edge.first});
      }
    }
  }

  return total_weight;
}