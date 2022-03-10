#include <iostream>
#include <vector>

using namespace std;

const int DAY = 86400;

int main() {
    //시간 초과 해결
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int h, m, s, q, curTime, x, y;
    cin >> h >> m >> s >> q; //초기 현재 시간, 쿼리 개수
    curTime = h * 3600 + m * 60 + s;
    while (q--) {
        cin >> x;
        if (x == 1) {
            cin >> y;
            curTime += y;
            curTime = curTime % DAY;
        }
        if (x == 2) {
            cin >> y;
            curTime -= y;
            curTime = curTime % DAY;
            if (curTime < 0) {
                curTime += DAY;
            }
        }
        if (x == 3) {
            cout << curTime / 3600 << " " << (curTime / 60) % 60 << " " << (curTime % 60) << "\n";
        }
    }
    return 0;
}