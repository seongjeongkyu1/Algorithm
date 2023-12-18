#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Edge {
  int node;
  int weight;
};

int dijkstra(const vector<vector<Edge>>& graph, int source) {
  int n = graph.size();
  vector<int> dist(n, INT_MAX);
  vector<int> weight(n, INT_MAX);
  weight[source] = 0;
  dist[source] = 0;

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push({0, source});

  while (!pq.empty()) {
    int u = pq.top().second;
    int d = pq.top().first;
    pq.pop();

    if (d > dist[u]) {
      continue;
    }

    for (const Edge& edge : graph[u]) {
      int v = edge.node;
      int w = edge.weight;

      if (dist[u] + w < dist[v]) {
        weight[v] = w;
        dist[v] = dist[u] + w;
        pq.push({dist[v], v});
      }
    }
  }

  int sum = 0;
  for (int i = 1; i < n;
       i++) {  // 노드 1에서 다른 모든 노드로의 최단 경로 트리의 에지 총합
    sum += weight[i];
    // cout << weight[i] << " ";
  }

  return sum;
}

int main() {
  int testNum;
  cin >> testNum;

  for (int i = 0; i < testNum; i++) {
    int n;
    cin >> n;

    vector<vector<Edge>> graph(n);

    for (int i = 0; i < n; i++) {
      int k, m;
      cin >> k >> m;

      for (int j = 0; j < m; j++) {
        int v, w;
        cin >> v >> w;
        graph[k - 1].push_back({v - 1, w});
      }
    }

    int sum = dijkstra(graph, 0);
    cout << sum << endl;
  }

  return 0;
}
