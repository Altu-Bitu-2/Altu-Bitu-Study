#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void binarySearch(vector<int> &l, int m, int n) {
    int start = 1; //1부터 시작
    int end = l[n - 1]; //가장 큰 수가 end가 됨
    int answer = 0; //정답
    while (start <= end) { //end가 start보다 크거나 같을 때까지
        int count = 0;
        int mid = (start + end) / 2; //중간값 정해주기
        for (int i = 0; i < n; i++) {
            count += l[i] / mid; //mid길이로 나눈 과자의 개수
        }
        if (count >= m) { //과자 개수가 m보다 크거나 같으면
            if (answer < mid) {
                answer = mid;
            }
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    cout << answer << '\n';
}

int main() {
    int m, n, input;
    cin >> m >> n;
    vector<int> l;
    for (int i = 0; i < n; i++) {
        cin >> input;
        l.push_back(input);
    }
    sort(l.begin(), l.end());
    binarySearch(l, m, n);
    return 0;
}