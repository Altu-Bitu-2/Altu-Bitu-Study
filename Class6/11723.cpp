#include <iostream>
#include <vector>

using namespace std;
vector<bool> arr(21, false);

void calc(string &command) {
    int n;
    if (command == "all") {
        fill(arr.begin(), arr.end(), true); //arr 전체를 true로 변경
        return;
    }
    if (command == "empty") {
        fill(arr.begin(), arr.end(), false); //arr전체를 false로 변경
        return;
    }
    cin >> n;
    if (command == "add") {
        arr[n] = true; //추가하면 true로 변경
    }
    if (command == "remove") {
        arr[n] = false; //삭제하면 false로 변경
    }
    if (command == "check") {
        cout << arr[n] << '\n';
    }
    if (command == "toggle") {
        if (arr[n]) { //true라면
            arr[n] = false; //false로 변경
        } else {
            arr[n] = true;
        }
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