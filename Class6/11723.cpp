#include <iostream>
#include <vector>

using namespace std;
vector<bool> arr(21, false);

void calc(string &command) {
    int n;
    if (command == "add") {
        cin >> n;
        arr[n] = true; //추가하면 true로 변경
    }
    if (command == "remove") {
        cin >> n;
        arr[n] = false; //삭제하면 false로 변경
    }
    if (command == "check") {
        cin >> n;
        if (arr[n]) cout << "1\n"; //true라면 1 출력
        else cout << "0\n"; //false라면 0 출력
    }
    if (command == "toggle") {
        cin >> n;
        if (arr[n]) { //true라면
            arr[n] = false; //false로 변경
        } else {
            arr[n] = true;
        }
    }
    if (command == "all") {
        fill(arr.begin(), arr.end(), true); //arr 전체를 true로 변경
    }
    if (command == "empty") {
        fill(arr.begin(), arr.end(), false); //arr전체를 false로 변경

    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int m;
    cin >> m;
    string command;
    while (m--) {
        cin >> command;
        calc(command);
    }
    return 0;
}