#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    queue<int> q;
    for (int i = 1; i <= n; i++) { //큐에 숫자 넣기
        q.push(i);
    }

    cout << "<";
    while (!q.empty()) { //큐가 비지 않을때까지 반복
        for (int i = 1; i <= k - 1; i++) { //k번째 출력하기 위해서 k직전까지 반복
            q.push(q.front()); //front 카드를 맨 뒤에 push
            q.pop(); //front를 pop해서 삭제
        }
        cout << q.front(); //k번째 숫자 출력
        q.pop();
        if (q.size() != 0) {
            cout << ", ";
        } else {
            cout << ">\n";
        }

    }

    return 0;
}