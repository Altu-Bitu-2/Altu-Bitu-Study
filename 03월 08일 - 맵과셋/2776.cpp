#include <iostream>
#include <unordered_map> //정렬되지 않은 컨테이너

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //입력
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n;
        unordered_map<int, bool> numbers;
        for (int i = 0; i < n; i++) {
            int one;
            cin >> one;
            numbers[one] = true;
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            int two;
            cin >> two;
            if (numbers[two]) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        }
    }
    return 0;
}