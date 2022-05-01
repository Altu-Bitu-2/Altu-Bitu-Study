#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfs(vector<vector<int>> &people, vector<int> &init, int n) {
    vector<int> rest(n + 1, 0); //각 사람이 루머를 믿기 위해 필요한 최소 주변인 수
    vector<int> ans(n + 1, -1); //몇 분 후에 믿는지
    queue<int> q; //큐 선언

    //시작 정점 초기화
    for (int i = 0; i < init.size(); i++) {
        ans[init[i]] = 0; //시간 초기화
        q.push(init[i]); //최초유포자 큐에 저장
    }

    //루머 믿어야 하는 주변인 수 초기화
    for (int i = 1; i <= n; i++) {
        rest[i] = (people[i].size() + 1) / 2; //최소 주변인 수 계산
    }

    while (!q.empty()) {
        int curr = q.front(); //현재 사람
        int t = ans[curr]; //루머 믿은 시간
        q.pop(); //pop해줌

        for (int i = 0; i < people[curr].size(); i++) {
            int next = people[curr][i]; //주변인
            if (ans[next] > -1) { //이미 루머를 믿는 다면
                continue;
            }
            rest[next]--; //믿는 주변인 수 감소
            if (!rest[next]) { //주변인들 중 절반 이상이 루머를 믿으면
                ans[next] = t + 1; //시간+1
                q.push(next); //다음 사람을 큐에 추가
            }
        }
    }
    return ans; //리턴
}

/**
 * [루머]
 *
 * 주변인들이 얼마나 믿는지를 배열을 통해 관리해야 함
 * 방문 체크 배열을 루머를 믿는 시간을 저장하는 배열로 대체함
 *    ans[i] = -1 일 경우, i는 루머를 믿지 않는다
 *    ans[i] = t인 경우, i는 t분 부터 루머를 믿기 시작함
 * 각자가 루머를 믿기 위해 주변인의 절반 이상이 루머를 믿어야 하므로, 각 사람이 루머를 믿기까지 루머를 믿는 주변인 몇명이 남았는지를 리스트에 기록한다.
 * 남은 사람이 0인 순간, 해당 사람은 루머를 믿기 시작
 */

int main() {
    int n, m, input; //사람 수, 주변의 번호

    //루머 퍼뜨리는 관계 입력
    cin >> n;
    vector<vector<int>> people(n + 1, vector<int>()); //사람 저장
    for (int i = 1; i <= n; i++) { //1~n까지 반복
        while (true) { //true동안 반복
            cin >> input; //입력받기
            if (!input) { //입력이 공백이면
                break; //break
            }
            people[i].push_back(input); //각 사람의 주변인 번호 저장
        }
    }

    //최초 유포자 입력
    cin >> m;
    vector<int> init(m, 0); //벡터 선언
    for (int i = 0; i < m; i++) { //m만큼 반복
        cin >> init[i]; //최초유포자 번호 저장
    }

    //연산
    vector<int> ans = bfs(people, init, n); //bfs탐색 결과 저장

    //출력
    for (int i = 1; i <= n; i++) { // 1~n까지
        cout << ans[i] << ' '; //출력
    }
    return 0;//리턴
}