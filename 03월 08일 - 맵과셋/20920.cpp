#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(const pair<string, int> &p1, const pair<string, int> &p2) {
    if (p1.second == p2.second) { //개수가 같으면
        if (p1.first.size() == p2.first.size()) { //개수가 같고 길이가 같으면 사전 순서대로
            return p1.first < p2.first;
        }
        //개수는 같고 길이가 다르면 길이가 긴 순서대로
        return p1.first.size() > p2.first.size();
    }
    //개수가 다르면 개수가 큰 순서대로
    return p1.second > p2.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    map<string, int> words;
    vector<pair<string, int>> v;
    string input;
    for (int i = 0; i < n; i++) {
        cin >> input;
        if (input.size() >= m) { //input 단어 길이가 m이상일 때
            words[input]++; //해당 글자를 key로 하는 개수 증가
        }
    }
    //sort를 위해 vector pair에 저장
    for (auto iter = words.begin(); iter != words.end(); iter++) {
        v.push_back(make_pair(iter->first, iter->second));
    }
    //조건에 따라 sort
    sort(v.begin(), v.end(), cmp);

    //출력
    for (auto iter = v.begin(); iter != v.end(); iter++) {
        cout << iter->first <<  '\n';
    }
    return 0;
}