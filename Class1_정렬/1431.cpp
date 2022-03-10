#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int sumDigit(string str) {
    int sum = 0;
    for (int i = 0; i < str.length(); i++) {
        if ((str[i] - '0' >= 0) && (str[i] - '0' <= 9)) {
            sum += str[i] - '0';

        }
    }
    return sum;
}

bool cmp(string a, string b) {
    if (a.length() != b.length()) {
        return a.length() < b.length();
    }
    if (sumDigit(a) != sumDigit(b)) {
        return sumDigit(a) < sumDigit(b);
    }
    return a < b;

}

int main() {
    int n;
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), cmp);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << '\n';
    }
}

