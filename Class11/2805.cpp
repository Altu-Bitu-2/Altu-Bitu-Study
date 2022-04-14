#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void binarySearch(vector<long long> tree, int n, long long m) {
    long long start = 0;
    long long mid;
    long long answer = 0;
    long long end = tree[n - 1];

    while (start <= end) {
        long long sum = 0;
        mid = (start + end) / 2;
        for (int i = 0; i < n; i++) {
            if (tree[i] > mid) { //현재 중간 값보다 나무 길이가 길면
                sum += tree[i] - mid; //나무를 잘라 추가함
            }
        }
        if (sum >= m) { //나무가 m보다 크거나 같으면
            if (answer < mid) {
                answer = mid;
            }
            start = mid + 1; //다음값 탐색
        } else { //나무가 m보다 작으면
            end = mid - 1; //mid의 앞 값 탐색
        }
    }
    cout << answer;
}

int main() {
    int n;
    long long m, input;
    cin >> n >> m;
    vector<long long> tree;
    for (int i = 0; i < n; i++) {
        cin >> input;
        tree.push_back(input);
    }
    sort(tree.begin(), tree.end()); //이분탐색을 위해 정렬

    binarySearch(tree, n, m); //이분 탐색
    return 0;
}