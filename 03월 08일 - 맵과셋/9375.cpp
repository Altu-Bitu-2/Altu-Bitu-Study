#include <iostream>
#include <map>

using namespace std;

int main() {
    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;    //의상 수 입력
        string name, type;
        map<string, int> m;

        while (n--) {
            cin >> name >> type;    //의상 이름, 종류 입력
            m[type]++; //key : 의상 종류(type) 증가
        }

        int total = 1;
        for (auto iter = m.begin(); iter != m.end(); iter++) {
            //조합 개수
            total *= (iter->second+1);
        }
        cout << total - 1 <<'\n'; //아무것도 입지 않는 경우 제외
    }

    return 0;
}