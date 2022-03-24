#include <iostream>
#include <vector>
#include <string>

using namespace std;
const int MAX = 1001;

int check(int number, int strike, int ball) {
    string check_num = to_string(number);
    int strike_cnt = 0;
    int ball_cnt = 0;
    vector<bool> correct_numbers(MAX, false);

    for (int i = 123; i < 988; i++) {
        string original_num = to_string(i);
        for (int a = 0; a < 3; a++) {
            if (original_num[a] == '0') { //자리에 0이 있으면 false
                correct_numbers[i] = false;
            }
            if (original_num[a] == check_num[a]) { //자리랑 숫자 모두 같을 때
                strike_cnt++;
            }
            for (int b = 0; b < 3; b++) {
                if (a != b && original_num[b] == check_num[a]) {//자리는 다르지만 같은 숫자가 존재할 때
                    ball_cnt++;
                }
            }

        }
        if (strike_cnt == strike && ball_cnt == ball) {
            correct_numbers[i] = true;
        }
    }

    int count = 0;
    for (int i = 0; i < MAX; i++) {
        if (correct_numbers[i]) {
            count++;
            cout << i << '\n';
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int number, strike, ball;
        cin >> number >> strike >> ball;
        cout << check(number, strike, ball);
    }
    return 0;
}
