#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    string input;
    map<string, int> name_ext; //이름이 key, 번호가 value

    for (int i = 0; i < n; i++) {
        cin >> input;
        //.을 찾고, 그 뒤 확장자명만 substr로 저장
        name_ext[input.substr(input.find(".") + 1, input.size())]++;
    }

    //iterator이용해서 map 반복 출력하기
    for (auto iter = name_ext.begin(); iter != name_ext.end(); iter++) {
        cout << iter->first << " " << iter->second << "\n";
    }
    cout << "\n";

    return 0;
}