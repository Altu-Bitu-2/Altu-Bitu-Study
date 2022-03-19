#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
vector<bool> is_prime(1000001, true);

//소수 검사
void isPrime() {
    //0과 1은 소수가 아니므로 false
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= 1000000; i++) {
        if (is_prime[i]) { // 소수라면
            for (int j = i * i; j <= 1000000; j += i) { //소수의 배수들은 모두 소수가 아니므로 false
                is_prime[j] = false;
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    isPrime(); //소수 검사
    bool checkAnswer = false; //두 소수의 덧셈으로 나타낼 수 있는지 확인하기 위함
    while (true) {
        cin >> n;
        if (n == 0) break;
        for (int i = 3; i < n; i += 2) { //첫번째 소수인 3부터 검사, 홀수만 검사하도록 2씩 더해줌
            if (is_prime[i] && is_prime[n - i]) { //두 숫자 모두 소수이면
                cout << n << " = " << i << " + " << n - i << '\n';
                checkAnswer = true; //
                break;
            }
        }
        if (!checkAnswer) { // 두 소수로 나타낼 수 없는 경우
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }

    return 0;
}