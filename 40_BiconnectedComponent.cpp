#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#define MAX 1001

using namespace std;

void FastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

vector<vector<pair<int, int>>> bcc;
vector<int> v[MAX];
set<int> cutPoint;
stack<pair<int, int>> s;
int visited[MAX];
int cnt = 0;

void Reset(){
    for (int i = 0; i < MAX; i++){
        visited[i] = -1;
        v[i].clear();
    }
    cutPoint.clear();
    bcc.clear();
    cnt = 0;

    while(!s.empty()){
        s.pop();
    }
}

int DFS(int x, bool isRoot){
    visited[x] = ++cnt;
    int temp = visited[x];
    int childCnt = 0;

    for(int i = 0 ; i < v[x].size() ; i++){
        int next = v[x][i];

        if(visited[x] > visited[next]){
            s.push({x, next});
        }

        if(visited[next] == -1){
            childCnt++;
            int subTree = DFS(next, false);
            if(!isRoot && subTree >= visited[x]){
                cutPoint.insert(x);
            }
            temp = min(temp, subTree);

            if(subTree >= visited[x]){
                vector<pair<int, int>> edge;
                while(!s.empty() && (s.top().first != x && s.top().second != subTree) ){
                    edge.push_back(s.top());
                    s.pop();
                }
                edge.push_back(s.top());
                s.pop();
                bcc.push_back(edge);
            }
        }
        else{
            temp = min(temp, visited[next]);
        }
    }

    if(isRoot && childCnt >= 2){
        cutPoint.insert(x);
    }

    return temp;
}

int main()
{
    FastIO();

    int testCase;
    cin >> testCase;
    for (int t = 0; t < testCase; t++){
        Reset();
        int n;
        cin >> n;

        for (int i = 0; i < n; i++){
            int num, m;
            cin >> num >> m;
            for (int j = 0; j < m; j++){
                int input;
                cin >> input;
                v[num].push_back(input);
            }
            sort(v[num].begin(), v[num].end());
        }

        for (int i = 1; i <= n; i++){
            if (visited[i] == -1){
                DFS(i, true);
            }
        }

        cout << bcc.size() << '\n';
        cout << cutPoint.size() << ' ';

        if(cutPoint.size() != 0){
            for (auto it : cutPoint){
                cout << it << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}