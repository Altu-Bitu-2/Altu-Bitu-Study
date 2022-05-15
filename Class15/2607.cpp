#include <iostream>
#include <vector>

using namespace std;

bool isSimilar(vector<int> &first, vector<int> &compare) {
//    int zero_cnt = 0;
    int one_cnt = 0;
    int more_cnt = 0;
    for (int i = 0; i < 26; i++) { //모든 알파벳 비교하면서
//        if (abs(first[i] - compare[i]) == 0) { //개수 차이가 0이면 같은 알파벳 개수가 동일
//            zero_cnt++;
//        }
        if (abs(first[i] - compare[i]) == 1) { //알파벳 개수가 1차이면 비슷한 단어일 가능성
            one_cnt++;
        }
        if (abs(first[i] - compare[i]) > 1) { //알파벳 개수가 2이상 차이나면
            more_cnt++;
        }
    }
    if (one_cnt > 1 || more_cnt > 0) { //하나의 문자 차이로 해결되지 않는 경우면
        return false;
    }
    return true;
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
        if (isSimilar(first, compare)) {
            cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}