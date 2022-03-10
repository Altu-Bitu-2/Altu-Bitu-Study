#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int cal(vector<int> &a, vector<int>&b, int n){
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i] * b[i];
    }
    return sum;
}
int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    cout << cal(a, b, n) << "\n";
    return 0;
}