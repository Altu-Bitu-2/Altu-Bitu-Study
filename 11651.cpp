#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//주소값이 와야하는지, 아니면 a,b로 해야하는지?
bool cmp(const pair<int, int> &a, pair<int, int> &b) {
    if (a.second != b.second) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main() {
    int n, x, y;
    cin >> n;
    vector<pair<int, int>> coord;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        coord.push_back(make_pair(x, y));
    }
    sort(coord.begin(), coord.end(), cmp);
    for (int i = 0; i < n; i++) {
        cout << coord[i].first << " " << coord[i].second << '\n';
    }
    return 0;
}