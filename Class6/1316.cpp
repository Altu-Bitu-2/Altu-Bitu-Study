#include <iostream>
#include <vector>

using namespace std;

int checkWord(string str) {
    vector<bool> alpha(26, false);
    int count = 0; //그룹단어가 아닌 단어의 개수
    for (int i = 0; i < str.length(); i++) {
        if (!alpha[str[i] - 'a']) { //해당 알파벳이 처음 등장한 경우
            alpha[str[i] - 'a'] = true; //true로 바꿔줌
        } else { //해당 알파벳이 이미 등장한 경우 (이미 true)
            if (str[i] != str[i - 1]) { //해당 알파벳과 이전 알파벳이 다르면
                count++; //그룹단어가 아니므로 카운트 증가
                break; //더이상 반복할 필요가 없으므로 break
            }
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    int total = n; //전체 단어 개수
    string input;
    while (n--) {
        cin >> input;
        total -= checkWord(input); //전체 단어 개수에서 그룹단어가 아닌 개수를 빼줌
    }
    cout << total << '\n';
    return 0;
}