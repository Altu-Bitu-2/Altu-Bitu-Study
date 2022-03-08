#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), greater<int>());

    //int 대신 long long 써야함
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] - i > 0) {
            sum += arr[i] - i;
        }
    }
    cout << sum;
}
