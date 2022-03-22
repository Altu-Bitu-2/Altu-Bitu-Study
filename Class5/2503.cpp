#include <iostream>
#include <vector>
#include <string>

using namespace std;

int check(int a, int b, int c) {
    string s;
    s = to_string(a);
    for (int i = 0; i < 3; i++) { //0은 제외
        if (s[i] == '0') {
            return 0; //false
        }
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int number, strike, ball;
        cin >> number >> strike >> ball;
        check(number, strike, ball);
    }
    return 0;
}