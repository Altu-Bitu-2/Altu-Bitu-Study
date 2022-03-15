#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    string input;
    cin >> input;
    vector<char> v;
    map<char, int> m;
    for (int i = 0; i < input.length(); i++) {
        m[input[i]]++;
    }
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        if (iter->second % 2 != 0 && iter->second > 2) { //홀수개인 문자가 2개 이상이면 팰린드롬 만들기 불가능
            cout << "I'm Sorry Hansoo\n";
            break;
        }
    }


    return 0;
}