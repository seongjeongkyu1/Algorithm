#include <iostream>
#include <vector>
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
    for (int i = 0; i < MAX; i++){
        visited[i] = false;
        v[i].clear();
    }
}

int DFS(int x){
    if(visited[x]) { 
        return 0; 
    }
    visited[x] = true;
    int cnt = 1;

    for(int i = 0 ; i < v[x].size() ; i++){
        int next = v[x][i];
        if(!visited[next]){
            cnt += DFS(next);
        }
    }

    return cnt;
}

int main(){
    FastIO();

    int testCase;
    cin >> testCase;
    for (int t = 0; t < testCase; t++){
        Reset();
        int n, cnt = 0;
        vector<int> rel;
        cin >> n;

        for (int i = 0; i < n; i++){
            int num, m;
            cin >> num >> m;
            for (int j = 0; j < m; j++){
                int input;
                cin >> input;
                v[num].push_back(input);
            }
        }

        for (int i = 1; i <= n; i++){
            if (!visited[i]){
                int a = DFS(i);
                rel.push_back(a);
                cnt++;
            }
        }

        sort(rel.begin(), rel.end());
        cout << cnt << ' ';
        for (auto it : rel){
            cout << it << ' ';
        }
        cout << '\n';
    }

    return 0;
}