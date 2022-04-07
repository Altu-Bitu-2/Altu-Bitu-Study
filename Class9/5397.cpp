#include <iostream>
#include <deque>

using namespace std;

string password(string &s) {
    string answer;
    deque<char> left;
    deque<char> right;
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] == '<') { //왼쪽으로 커서가 이동해야한다면
            if (!left.empty()) { //오른쪽 배열이 비어있지 않다면
                right.push_front(left.back()); //왼쪽 맨 마지막 문자를 오른쪽으로 옮겨줌
                left.pop_back();
            }
        } else if (s[i] == '>') {// 오른쪽으로 커서가 이동해야 한다면
            if (!right.empty()) {//오른쪽이 비어있지 않다면
                left.push_back(right.front());
                right.pop_front();
            }
        } else if (s[i] == '-') {//백스페이스라면
            if (!left.empty()) {//왼쪽이 비어있지 않다면
                left.pop_back(); //left의 마지막 원소를 pop하여 삭제
            }
        } else {
            left.push_back(s[i]); //그외는 왼쪽에다가 추가
        }
    }
    while (!left.empty()) { //왼쪽이 비어있지 않다면
//        cout << left.front(); //왼쪽 첫번째 원소 출력
//        left.pop_front(); //첫 원소 제거
        answer += left.front();
        left.pop_front();
    }
    while (!right.empty()) { //오른쪽이 비어있지 않다면
//        cout << right.front(); //오른쪽 맨 첫 원소를 출력
//        right.pop_front(); //첫 원소 제거
        answer += right.front();
        right.pop_front();
    }

    return answer;
}

int main() {
    int t;
    string str;

    cin >> t;
    while (t--) {
        cin >> str;
        cout << password(str) << '\n';
    }
    return 0;
}