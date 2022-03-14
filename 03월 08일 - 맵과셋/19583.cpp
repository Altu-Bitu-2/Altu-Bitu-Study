#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    string s, e, q;
    map<string, int> m;
    cin >> s >> e >> q;

    //freopen("input.txt", "r", stdin);
    string time, name;
    int count = 0;
    while (cin >> time >> name) {
        //개강 총회 시작 전에 채팅 기록을 남긴 경우 1로 표기
        if (time <= s) {
            m[name] = 1;
        }
        //카운트가 1이고, 개강총회가 끝난 시간 이후부터 스트리밍이 끝난 시간 내에 기록을 남긴 경우
        if ((m[name] == 1 && time >= e && time <= q)) {
            m[name] = 2;
        }
    }
    //맵을 돌면서 카운트가 2인 개수 체크
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        if (iter->second == 2) {
            count++;
        }
    }
    cout << count << "\n";
    return 0;
}