#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n, p;
    cin >> n >> p;
    int count = 0;
    stack<int> st[n];
    while (n--) {
        int x, y;
        cin >> x >> y;
        while (true) {
            if (st[x].empty()) { //누른게 없으면
                st[x].push(y); //현재 줄에 프렛을 push한다.
                count++;
            } else if (st[x].top() < y) { //누른게 있고, 현재 누른 프렛이 더 큰 경우
                st[x].push(y); //현재 줄에 프렛을 push한다.
                count++;
                break;
            } else if (st[x].top() > y) { //누른게 있고, 현재 누른 프렛이 더 작은 경우
                st[x].pop(); //삭제
                count++;
            } else { //누른게 있고, 현재 누른 프렛과 같은 경우
                break;
            }
        }

    }
    cout << count;
    return 0;
}