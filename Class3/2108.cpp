#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

bool cmp(const pair<int, int> &p1, const pair<int, int> &p2) {
    if (p1.second == p2.second) { //빈도수가 같으면
        return p1.first < p2.first;
    }
    return p1.second > p2.second; //빈도수 큰 순서대로
}

int main() {
    int n, input;
    cin >> n;
    vector<int> v;
    map<int, int> m;
    double sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> input;
        v.push_back(input);
        m[input]++;
        sum += input;
    }
    vector<pair<int, int>> p(m.begin(), m.end()); //map->vector pair에 저장
    sort(v.begin(), v.end()); //벡터 정렬
    sort(p.begin(), p.end(), cmp); //vector pair도 정렬


    cout << floor((sum / n) + 0.5) << '\n';    //산술평균 (-0 되는 것 방지 위해 0.5 더한 후 내림)
    cout << v[n / 2] << '\n';   //중앙값
    if (p[0].second == p[1].second) {   //최빈값이 두개인 경우
        cout << p[1].first << '\n'; //두번째 값 출력
    } else {
        cout << p[0].first << '\n';
    }
    cout << v[n - 1] - v[0] << '\n'; // 범위
    return 0;
}