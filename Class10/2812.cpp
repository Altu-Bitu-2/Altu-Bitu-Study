#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> num(n, 0); //입력 배열
    vector<int> arr; //정답 배열

    string input; //n자리 숫자
    cin >> input;

    for (int i = 0; i < n; i++) {
        num[i] = input[i] - '0'; //문자를 숫자로 변경하여 저장
    }
    for (int i = 0; i < n; i++) { //n자리 수를 돌면서
        while (k != 0 && !arr.empty() && arr.back() < num[i]) { //k가 0이 아니면서, 정답배열이 비어있지 않고, 현재 num값이 더 큰 경우에는
            arr.pop_back(); //마지막 수를 삭제
            k--; //개수 감소
        }
        arr.push_back(num[i]); //현재 숫자정답 배열에 push해주기
    }
    while (k--) { //k가 여전히 0이 아니라면
        arr.pop_back();
    }
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
    }
    return 0;
}