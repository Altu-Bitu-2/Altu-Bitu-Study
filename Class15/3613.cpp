#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void convertToC(string &s) { //C로 변경
    string res;
    for (int i = 0; i < s.size(); i++) {
        if (!isupper(s[i])) { //대문자가 아니면 결과 string에 추가
            res += s[i];
        }
        if (isupper(s[i])) { //대문자면
            res += '_'; //언더바 추가
            res += tolower(s[i]); //원래 문자 소문자로 변경해 추가
        }
    }
    cout << res;
}

void convertToJava(string &s) { //자바로 변경
    string res;
    for (int i = 0; i < s.size();) {
        if (s[i] != '_') { //언더바가 아니면
            res += s[i]; //해당 문자 추가
            i++; //다음 문자로 이동
        }
        if (s[i] == '_') { //언더바면
            res += toupper(s[i + 1]); //다음 문자를 대문자로 변경해 추가
            i = i + 2; //다음문자 건너뛰기
        }
    }
    cout << res;
}

void checkError(string &s) {
    //맨첫글자, 마지막글자가 언더바이거나, 첫번째 문자가 대문자이면 에러
    if (s[0] == '_' || s[s.size() - 1] == '_' || isupper(s[0])) {
        cout << "Error!";
        return;
    }
    //언더바 찾기
    if (find(s.begin(), s.end(), '_') != s.end()) {
        if (s.find("__") != string::npos) { //언더바가 연속되면 에러
            cout << "Error!";
            return;
        }
        for (int i=0; i<s.size();i++) { //대문자면 에러
            if (isupper(s[i])) {
                cout << "Error!";
                return;
            }
        }
        convertToJava(s);
    } else {
        convertToC(s);
    }
}

int main() {
    string s;
    cin >> s;

    checkError(s); //검증

    return 0;
}