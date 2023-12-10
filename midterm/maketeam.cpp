#include <iostream>
#include <vector>
using namespace std;

int main() {
  int testNum;
  cin >> testNum;

  for (int i = 0; i < testNum; i++) {
    int size, data;
    cin >> size;

    vector<int> team(size, 0);
    vector<int> visited(size, 0);
    vector<int> v;
    for (int i = 0; i < size; i++) {
      cin >> data;
      v.push_back(data);
    }
    for (int std_num = 0; std_num < size; std_num++) {
      int near_num = v[std_num] - 1;
      team[near_num] = std_num;
    }
    int teamNum = 0;
    for (int i = 0; i < size; i++) {
      if (!visited[i]) {
        visited[i] = 1;
        teamNum++;
        int near = team[i];
        while (!visited[near]) {
          visited[near] = 1;
          near = team[near];
        }
      }
    }
    cout << teamNum << endl;
  }
}