#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int check(vector<pair<int, int>> v, int n){
    int count = 1;
    int standard = v[0].second;
    for (int i = 1; i < n; i++) {
        if (v[i].second < std){
            count++;
            standard = v[i].second;
        }
    }
    return count;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i].first >> v[i].second;
        }
        sort(v.begin(), v.end());
        cout << check(v, n) << '\n';
    }
}