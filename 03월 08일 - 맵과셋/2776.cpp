#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //입력
    int t;
    cin >> t;

    while (t--) {
        int n, m, one, two;
        set<int> s;
        cin >> n;

        // set에 입력값 저장, 중복 제거
        for (int i = 0; i < n; i++) {
            cin >> one;
            s.insert(one);
        }
        cin >> m;
        //해당 셋에 있는 지 검사
        for (int i = 0; i < m; i++) {
            cin >> two;
            if (s.find(two) != s.end())
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
    }
    return 0;
}