#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int g;
    cin >> g;
    int recent = 1; //현재 몸무게
    int past = 1;   //과거의 몸무게
    vector<int> ans;
    while (past <= recent) { //현재 몸무게가 과거 몸무게와 같아질 때까지
        int new_g = recent * recent - past * past; //현재몸무게의 제곱 - 기억하는 몸무게의 제곱 = G
        if (g < new_g) { //계산 값이 g보다 크면 과거 기억하던 몸무게를 증가시킨다
            past++;
        }
        if (g > new_g) {
            recent++;
        }
        if (g == new_g) { //같으면 현재 몸무게 추가
            ans.push_back(recent);
            past++;
        }
        if (recent - past == 1) { //최소 1키로는 빠졌다고 봐야하므로(?) 이 경우가 마지막 경우가 됨
            break;
        }
    }
    if (ans.empty()) {
        cout << -1 << "\n";
    }
    sort(ans.begin(), ans.end());
    for (auto i: ans) {
        cout << i << '\n';
    }
    return 0;
}