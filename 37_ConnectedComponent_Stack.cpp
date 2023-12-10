#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define MAX 1001

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vector<int> v[MAX];
bool visited[MAX];

void Reset(){
    for(int i = 0 ; i < MAX ; i++){
        visited[i] = false;
        v[i].clear();
    }
}

int DFS(int x, int cnt){
    stack<int> s;
    visited[x] = true;
    s.push(x);
    cnt++;

    while (!s.empty()){
        int curr = s.top();
        s.pop();

        for(int i = 0 ; i < v[curr].size() ; i++){
            int next = v[curr][i];
            if(!visited[next]){
                visited[next] = true;
                cnt++;
                s.push(next);
            }
        }
    }
    return cnt;
}

int main() {
    FastIO();

    int testCase;
    cin >> testCase;
    for(int t = 0 ; t < testCase ; t++){
        Reset();
        int n, cnt = 0;
        vector<int> rel;
        cin >> n;

        for(int i = 0 ; i < n ; i++){
            int num, m;
            cin >> num >> m;
            for(int j = 0 ; j < m ; j++){
                int input;
                cin >> input;
                v[num].push_back(input);
            }
        }

        for(int i = 1 ; i <= n ; i++){
            if(!visited[i]){
                int a = DFS(i, 0);
                rel.push_back(a);
                cnt++;
            }
        }
        sort(rel.begin(), rel.end());
        cout << cnt << ' ';
        for(auto it : rel){
            cout << it << ' ';
        }
        cout << '\n';
    }

    return 0;
}