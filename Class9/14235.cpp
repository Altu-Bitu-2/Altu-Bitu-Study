#include <iostream>
#include <queue>

using namespace std;

void present(priority_queue<int> &pq) {
    if (!pq.empty()) { //줄 선물이 있다면
        cout << pq.top() << '\n'; //가장 value가 큰 값 출력
        pq.pop(); //해당 선물 제거
    } else {
        cout << "-1\n";
    }
}

int main() {
    int n, a;
    cin >> n;
    priority_queue<int> pq; //우선순위 큐 이용
    while (n--) {
        cin >> a;
        if (a == 0) { //아이들을 만난 것이라면
            present(pq);
        } else { //거점지라면
            for (int i = 0; i < a; i++) {
                int input;
                cin >> input;
                pq.push(input); //우선순위 큐에 선물 push하기
            }
        }
    }
    return 0;
}