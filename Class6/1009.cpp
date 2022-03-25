#include <iostream>
#include <cmath>

using namespace std;

void calc(int a, int b) {
    int check = a % 10; //밑은 일의자리만 따지면 되므로 10으로 나눈 나머지를 저장
    int upper = b % 4; //지수는 4번 곱할때마다 일의자리가 반복되므로 4로 나눈 나머지를 저장
    if (upper == 0) { //지수가 0이 되면 계산 값이 1이 되므로, 지수를 4로 저장
        upper = 4;
    }
    if (check == 0) { //밑이 10으로 나누어지면 무조건 10이 됨
        cout << 10 << '\n';
    } else {
        int calc_result = pow(check, upper); //거듭제곱 계산
        cout << calc_result % 10 << '\n'; //거듭제곱을 10으로 나눈 나머지가 일의자리임
    }
}


int main() {
    int t, a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        calc(a, b);
    }
    return 0;
}