#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    //최대힙, 최소힙 선언
    priority_queue<int, vector<int>> max_heap;
    priority_queue<int, vector<int>, greater<>> min_heap;
    int t, k, n;
    char c;
    cin >> t;
    while (t--) { //테스트케이스만큼 반복
        cin >> k;
        vector<bool> check(1000001, false); //추가된 숫자인지 확인하는 벡터 선언
        while (k--) {
            cin >> c >> n;
            if (c == 'I') { //최대힙, 최소힙 모두 추가
                max_heap.push(n);
                min_heap.push(n);
                check[n] = true; //추가된 수는 true로 표시
            } else if (c == 'D' && n == 1) { //삭제연산 + 1이면 최대힙
                while (!max_heap.empty() && !check[max_heap.top()]) { //힙이 비어있지 않으면서 false인 숫자가 없을때까지
                    max_heap.pop(); //제거
                }
                if (!max_heap.empty()) { //힙이 비어있지 않으면
                    check[max_heap.top()] = false; //false로 바꿔주고 pop
                    max_heap.pop();
                }
            } else if (c == 'D' && n == -1) {
                while (!min_heap.empty() && !check[min_heap.top()]) { //힙이 비어있지 않으면서 false인 숫자가 없을때까지
                    min_heap.pop(); //제거
                }
                if (!min_heap.empty()) {
                    check[min_heap.top()] = false; //false로 바꿔주고 pop
                    min_heap.pop();
                }
            }
        }

        if (max_heap.empty() || min_heap.empty()) {
            cout << "EMPTY\n";
        } else {
            cout << max_heap.top() << " " << min_heap.top() << "\n";
        }
    }

    return 0;
}