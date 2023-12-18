#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Edge {
  int u, v, weight;
};

int findParent(vector<int>& parent, int node) {
  if (parent[node] == node) return node;
  return parent[node] = findParent(parent, parent[node]);
}

void unionNodes(vector<int>& parent, int u, int v) {
  int parentU = findParent(parent, u);
  int parentV = findParent(parent, v);
  parent[parentU] = parentV;
}

int kruskal(vector<Edge>& edges, int n) {
  sort(edges.begin(), edges.end(),
       [](const Edge& a, const Edge& b) { return a.weight < b.weight; });

  vector<int> parent(n + 1);
  for (int i = 1; i <= n; i++) {
    parent[i] = i;
  }

  int totalWeight = 0;
  for (const auto& edge : edges) {
    int u = edge.u;
    int v = edge.v;
    int weight = edge.weight;

    if (findParent(parent, u) != findParent(parent, v)) {
      unionNodes(parent, u, v);
      totalWeight += weight;
    }
  }

  return totalWeight;
}

int main() {
  int testNum;
  cin >> testNum;

  for (int i = 0; i < testNum; i++) {
    int n;
    cin >> n;
    vector<Edge> edges;

    for (int i = 1; i <= n; i++) {
      int k, m;
      cin >> k >> m;

      for (int j = 0; j < m; j++) {
        int v, w;
        cin >> v >> w;
        edges.push_back({k, v, w});
      }
    }

    int totalWeight = kruskal(edges, n);

    cout << totalWeight << endl;
  }

  return 0;
}
