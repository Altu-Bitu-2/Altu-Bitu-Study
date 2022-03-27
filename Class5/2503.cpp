#include <iostream>
#include <vector>
#include <string>

using namespace std;
const int MAX = 1001;
vector<bool> correct_numbers(MAX, true); //전체 배열을 true로 설정

void check(int i, int number, int strike, int ball) {
    string check_num = to_string(number); //질문하는 숫자
    string original_num = to_string(i); //찾아야 하는 숫자
    int strike_cnt = 0;
    int ball_cnt = 0;
    for (int a = 0; a < 3; a++) {
        if (original_num[a] == '0') { //자리에 0이 있으면 false
            correct_numbers[i] = false;
            return;
        }

        for (int b = 0; b < 3; b++) {
            if (a!=b && original_num[a] == original_num[b]) { //숫자가 서로 같은 경우는 제외
                correct_numbers[i] = false;
                return;
            }
            if (a == b && original_num[b] == check_num[a]) { //자리랑 숫자 모두 같을 때
                strike_cnt++;
            }
            if (a != b && original_num[b] == check_num[a]) {//자리는 다르지만 같은 숫자가 존재할 때
                ball_cnt++;
            }
        }
    }
    if (strike_cnt != strike || ball_cnt != ball) { //strike, ball 모두 개수가 맞으면 맞는 숫자임
        correct_numbers[i] = false;
        return;
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int number, strike, ball;
        cin >> number >> strike >> ball;
        for (int i = 123; i < 988; i++) {
            if (correct_numbers[i]) { //true인 숫자만 검사
                check(i, number, strike, ball);
            }
        }
    }

    int count = 0;
    for (int k = 123; k < 988; k++) { //true인 숫자들만 count증가, 출력
        if (correct_numbers[k]) {
            count++;
        }
    }
    cout << count << '\n';
    return 0;
}
