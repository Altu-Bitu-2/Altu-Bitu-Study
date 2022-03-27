#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string n1, n2;
    cin >> n1 >> n2;

    int n1_len;
    int n2_len;
    n1_len = n1.length();
    n2_len = n2.length();
    string zero;

    if (n1_len > n2_len) {
        for (int i = 0; i < n1_len - n2_len; i++) { //길이 차이만큼 0을 붙여줌
            zero += '0';
        }
        n2 = zero + n2;
    } else if (n1_len < n2_len) {
        for (int i = 0; i < n2_len - n1_len; i++) { //길이 차이만큼 0을 붙여줌
            zero += '0';
        }
        n1 = zero + n1;
    }

    reverse(n1.begin(), n1.end());
    reverse(n2.begin(), n2.end()); //두 숫자 모두 뒤집어서 계산하기 편하게 함

    int up; //올릴 수
    string answer; //계산한 값
    for (int i = 0; i < max(n1_len, n2_len); ++i) { //가장 긴 숫자의 길이만큼 반복
        int n1_num = n1[i] - '0'; //숫자로 변환
        int n2_num = n2[i] - '0';
        int sum = n1_num + n2_num + up; //각 자리의 숫자의 합 + 올릴 수
        if (sum > 9) { //각 자리수 합이 9보다 크면 올려야하므로
            up = 1; //올릴 수는 1
            sum -= 10; //10을 빼줘야 남은 수가 해당 자리의 값이 됨
        } else {
            up = 0; //올릴 수가 없으므로 0
        }
        answer += to_string(sum); //string형태로 추가해줌
    }
    if (up == 1) { //마지막 up이 1이면 하나 더 올려줘야하므로
        answer += '1'; // 1추가
    }
    reverse(answer.begin(), answer.end()); //다시 거꾸로 돌려서 답 출력
    cout << answer << '\n';


    return 0;
}
