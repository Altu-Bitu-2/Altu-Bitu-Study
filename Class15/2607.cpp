#include <iostream>
#include <vector>

using namespace std;

bool isSimilar(vector<int> &first, vector<int> &compare) {
    int one_cnt = 0;
    int first_len = 0;
    int compare_len = 0;
    for (int i = 0; i < 26; i++) { //모든 알파벳 비교하면서
        if (first[i] != 0) { //길이 구하기
            first_len++;
        }
        if (compare[i] != 0) {
            compare_len++;
        }
        if (abs(first[i] - compare[i]) == 1) { //알파벳 개수가 1차이면 비슷한 단어일 가능성
            one_cnt++;
        }
        if (abs(first[i] - compare[i]) > 1) { //알파벳 개수가 2이상 차이나면 만족하지 않음
            return false;
        }
    }
    if ((first_len == compare_len && one_cnt == 2) || one_cnt <= 1) { //한 문자가 다른 문자로 대치 가능하거나 단어 한개를 추가/삭제하는 것이 가능하면
        return true; //true리턴
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<int> first(26, 0); //26개 알파벳 개수 담을 벡터
    string first_word; //첫번째 단어
    cin >> first_word;
    for (int i = 0; i < first_word.size(); i++) {
        first[first_word[i] - 'A']++; //알파벳 개수 추가
    }
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        string compare_word;
        cin >> compare_word; //비교할 단어
        vector<int> compare(26, 0);
        for (int j = 0; j < compare_word.size(); j++) {
            compare[compare_word[j] - 'A']++;
        }
        cout << compare_word << ' ';
        if (isSimilar(first, compare)) {
            cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}