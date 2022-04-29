#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<vector<int>> v;
vector<int> parent;
vector<bool> visited;

void bfs(int n) {
    queue<int> que;
    que.push(n); //큐에 푸시해줌
    while (!que.empty()) { //큐가 비어있지 않은 동안
        visited[n] = true; //방문 체크
        int curr = que.front(); //현재 노드 저장
        que.pop();
        for (int next = 0; next < v[curr].size(); next++) { //curr번째 배열의 크기만큼 반복하면서
            if (visited[v[curr][next]]) { //방문체크가 되어있으면 계속
                continue;
            } else { //방문체크가 되어있지 않으면
                parent[v[curr][next]] = curr; //현재 노드가 부모
                visited[v[curr][next]] = true; //방문체크
                que.push(v[curr][next]); //현재 노드를 큐에 푸시해줌
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    v.assign(100001, vector<int> (10001, 0));
    visited.assign(100001, false);
    parent.assign(100001, 0);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    bfs(1);
    for (int i = 2; i <= n; i++) {
        cout << parent[i] << "\n";
    }

    return 0;
}