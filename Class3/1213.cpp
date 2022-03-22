#include <iostream>
#include <algorithm>

using namespace std;
char alpha[26];

int main() {
    string input;
    cin >> input;
    string answer = "";
    int odd = 0;
    int odd_alpha;
    int len = input.size();
    for (int i = 0; i < len; i++) { //alpha 배열에 개수 저장
        alpha[input[i] - 'A']++;
    }
    for (int i = 0; i < 26; i++) {
        if (alpha[i] % 2 != 0) { //홀수일때
            odd++; //홀수개 카운트
            odd_alpha = i; //홀수 인덱스 저장
        }
    }
    if (odd > 1) { //홀수개수가 2개면 팰린드롬 불가능
        cout << "I'm Sorry Hansoo\n";
    } else {
        for (int i = 0; i < 26; i++) { //짝수개씩 등장한 알파벳 answer문자열에 추가 (반만)
            for (int j = 0; j < alpha[i] / 2; j++) {
                answer += i + 'A';
            }
        }
        cout << answer;
        if (input.size() % 2 != 0) { //입력한 문자열 길이가 짝수가 아니라면
            cout << char(odd_alpha + 'A'); //홀수개 등장한 알파벳 출력
        }
        reverse(answer.begin(), answer.end()); //answer 반만 반대로 돌림
        cout << answer << '\n';


    }

    return 0;
}