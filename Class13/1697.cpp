#include <iostream>
#include <queue>

using namespace std;
const int MAX = 100001;

int bfs(int n, int k) {
    vector<bool> visited(MAX, 0);
    queue<pair<int, int>> que;
    que.push({n, 0}); //위치랑 시간을 함께 큐에 저장, 시간은 0으로 초기화
    visited[n] = true; //시작 지점 방문체크
    while (!que.empty()) {
        int place = que.front().first; //현재위치
        int time = que.front().second; //현재 시간
        que.pop();
        if (place == k) { //현재 위치가 도달 지점이라면 바로 시간 출력
            return time;
        }
        if (place + 1 < MAX && !visited[place + 1]) { //현재 위치+1 위치가 범위 안이면서 방문하지 않았으면
            visited[place + 1] = true;
            que.push({place + 1, time + 1}); //현재위치 + 1, 시간을 큐에 넣어줌
        }
        if (place - 1 >= 0 && place - 1 < MAX && !visited[place - 1]) {//.현재 위치-1 위치가 범위 안이면서 방문하지 않았으면
            visited[place - 1] = true;
            que.push({place - 1, time + 1});
        }
        if (place * 2 < MAX && place * 2 >= 0 && !visited[place * 2]) {//현재 위치*2 위치가 범위 안이면서 방문하지 않았으면
            visited[place * 2] = true;
            que.push({place * 2, time + 1});
        }
    }

}

int main() {
    int n, k;
    cin >> n >> k;
    cout << bfs(n, k) << '\n';

    return 0;
}