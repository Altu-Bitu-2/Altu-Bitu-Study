#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    //최대힙, 최소힙 선언
    priority_queue<pair<int, int>, vector<pair<int, int>>> max_heap;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> min_heap;
    int t, k, n;
    char c;
    cin >> t;
    while (t--) { //테스트케이스만큼 반복
        cin >> k;
        vector<int> check(1000001, 0); //추가된 숫자인지 확인하는 벡터 선언
        for (int i = 0; i < k; i++) {
            cin >> c >> n;
            if (c == 'I') { //최대힙, 최소힙 모두 추가
                max_heap.push(make_pair(n, i)); //정수 n과 순서 i를 함께 저장
                min_heap.push(make_pair(n, i));
                check[i]++; //추가될때마다 1씩 증가
            } else if (c == 'D' && n == 1) { //삭제연산 + 1이면 최대힙
                while (!max_heap.empty() && check[max_heap.top().second] == 0) { //힙이 비어있지 않으면서 개수가 0인 수가 없을때까지
                    max_heap.pop(); //제거
                }
                if (!max_heap.empty()) { //힙이 비어있지 않으면
                    check[max_heap.top().second]--; //개수 차감 후 pop
                    max_heap.pop();
                }
            } else if (c == 'D' && n == -1) {
                while (!min_heap.empty() && check[min_heap.top().second] == 0) { //힙이 비어있지 않으면서 개수가 0인 수가 없을때까지
                    min_heap.pop(); //제거
                }
                if (!min_heap.empty()) {
                    check[min_heap.top().second]--; //개수 차감 후 pop
                    min_heap.pop();
                }
            }
        }
        while (!max_heap.empty() && check[max_heap.top().second] == 0) {
            max_heap.pop();
        }
        while (!min_heap.empty() && check[min_heap.top().second] == 0) {
            min_heap.pop();
        }
        if (max_heap.empty() || min_heap.empty()) {
            cout << "EMPTY\n";
        } else {
            cout << max_heap.top().first << " " << min_heap.top().first << "\n";
        }
    }

    return 0;
}