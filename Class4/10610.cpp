#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int check(string n) {
    vector<int> v;
    int sum = 0;
    bool contains_zero = false;
    for (int i = 0; i < n.length(); i++) {
        sum += n[i] - '0'; //숫자로 변환하여 총합을 구함
        v.push_back((n[i] - '0')); //벡터에 해당 숫자 저
        if (n[i] == '0') { //숫자에 무조건 0이 있어야 30의 배수일 수 있음
            contains_zero = true;
        }
    }
    if (sum % 3 == 0 && contains_zero) { //3의 배수이면서 0을 가지고 있으면
        sort(v.rbegin(), v.rend()); //큰 순서대로 정렬 후
        for (int i = 0; i < v.size(); i++) { // 출력
            cout << v[i];
        }
    } else {
        cout << -1;
    }
    return 0;
}


int main() {
    string n;
    cin >> n;
    check(n) << '\n';
    return 0;
}