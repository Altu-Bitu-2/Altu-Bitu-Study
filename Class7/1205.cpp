#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getRank(vector<int> &rank, int score, int n) {
    int new_rank = 1; //새로운 랭킹 1부터 시작
    if (n <= 0) //n이 0보다 작으면 둘째 줄 출력하지 않음
        return -1;
    if (score <= rank.back()) { // 새로운 점수가 맨 마지막 랭킹 점수보다 작으면
        return -1;
    }
    for (int i = 0; i < n; i++) {//전체 랭킹을 돌면서 확인
        if (rank[i] > score) {
            new_rank++;
        }
    }

    return new_rank;
}

int main() {
    int n, score, p; //리스트 점수의 개수, 새로운 점수, 랭킹리스트에 올라갈 수 있는 점수 개수 p
    vector<int> rank;
    cin >> n >> score >> p;
    rank.assign(p, 0);
    for (int i = 0; i < n; i++) {
        cin >> rank[i];
    }
    sort(rank.rbegin(), rank.rend()); //비오름차순으로 정렬
    if (n == 0) { //n이 0이면 새로운 점수는 무조건 1등
        cout << "1\n";
    } else {
        cout << getRank(rank, score, n) << '\n';
    }
    return 0;
}