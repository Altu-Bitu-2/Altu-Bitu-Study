#include <iostream>
#include <string>

using namespace std;

int gcd(int a, int b) { //최대공약수를 구하는 함수
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    string s;
    int n, m;
    int index;
    int gcd_num;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ':') { //:인 문자의 인덱스를 저장해줌
            index = i;
        }
    }
    n = stoi(s.substr(0, index)); //substr를 이용해 앞 숫자 저장
    m = stoi(s.substr(index + 1, s.length() - index)); //뒷 숫자 저장
    gcd_num = gcd(n, m); //두 숫자의 최대공약수 구하기
    cout << n / gcd_num << ':' << m / gcd_num << '\n'; //출력 시 원래 숫자를 최대공약수로 나눠줌
    return 0;
}