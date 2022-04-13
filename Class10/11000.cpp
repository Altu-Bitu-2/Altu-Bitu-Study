#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> lec;
    priority_queue<int, vector<int>, greater<>> pq; //우선순위큐를 이용해 강의 시간 저장

    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end; //시작시간, 끝시간 입력받고
        lec.emplace_back(start, end); //lec벡터에 쌍으로 저장
    }

    sort(lec.begin(), lec.end()); //정렬

    pq.push(lec[0].second); //끝시간을 큐에 푸시해줌

    for (int i = 1; i < n; i++) { //전체 lec벡터를 돌면서
        if (pq.top() <= lec[i].first) { //끝나는 시간이 가장 빠른 수업보다 시작하는 시간이 늦으면
            pq.pop(); //같은 강의실을 사용할 수 있으므로 pop
            pq.push(lec[i].second); //i번째 끝시간을 push해줌
        }
        else{
            pq.push(lec[i].second);//끝나는 시간 push
        }
    }

    cout << pq.size() << '\n'; //pq에 남아있는 개수가 강의실의 개수
    return 0;
}