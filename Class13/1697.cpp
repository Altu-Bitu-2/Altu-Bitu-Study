#include <iostream>
#include <queue>

using namespace std;
const int MAX = 100001;

int bfs(int n, int k) {
    vector<int> visited(MAX, 0);
    queue<int> que;
//    que.push(); //위치랑 시간을 함께 큐에 저장, 시간은 0으로 초기화
    que.push(n); //처음 위치 큐에 저장
    visited[n] = 1; //시작 지점 방문체크
    while (!que.empty()) {
        int place = que.front(); //현재위치
        que.pop();
        if (place == k) { //현재 위치가 도달 지점이라면 바로 시간 출력
            return visited[place] - 1; //초기화 1로 했으므로
        }
        if (place + 1 < MAX && !visited[place + 1]) { //현재 위치+1 위치가 범위 안이면서 방문하지 않았으면
            visited[place + 1] = visited[place] + 1; //이전 방문한 정점의 시간에 +1
            que.push(place + 1); //현재위치 + 1, 시간을 큐에 넣어줌
        }
        if (place - 1 >= 0 && place - 1 < MAX && !visited[place - 1]) {//.현재 위치-1 위치가 범위 안이면서 방문하지 않았으면
            visited[place - 1] = visited[place] + 1;
            que.push(place - 1);
        }
        if (place * 2 < MAX && place * 2 >= 0 && !visited[place * 2]) {//현재 위치*2 위치가 범위 안이면서 방문하지 않았으면
            visited[place * 2] = visited[place] + 1;
            que.push(place * 2);
        }
    }

}

int main() {
    int n, k;
    cin >> n >> k;
    cout << bfs(n, k) << '\n';

    return 0;
}