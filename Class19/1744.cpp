#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int tieNumber(vector<int> &arr) {
    int total = 0; //전체 합 초기화
    int size = arr.size(); //배열 크기
    for (int i = 0; i < size - 1; i += 2) {
        total += arr[i] * arr[i + 1]; //인접한 두 수를 곱해 더해줌
    }
    //하나 남은 수 더해줌
    if (size % 2) {
        total += arr[size - 1];
    }
    return total; //전체 합 리턴
}

/**
 * [수 묶기]
 *
 * 1. 양수는 양수끼리, 음수는 음수끼리 곱해야 큰 수를 만들 수 있다.
 * 2. 절댓값이 큰 것끼리 곱해야 더 큰 수를 만들 수 있다.
 *     ex) 1, 2, 3, 4 => 4 * 1 + 3 * 2 = 10
 *                    => 4 * 3 + 2 * 1 = 14
 * 3. 1은 곱하는 것보다 더해야 큰 수를 만들 수 있다. (x * 1 = x < x + 1)
 */
int main() {
    int n, x, cnt1 = 0; //수열의 크기, 각 수, 0의 개수

    //입력
    cin >> n; //수열의 크기 입력
    vector<int> arr_pos, arr_neg; //양수 음수 배열 선언
    while (n--) { //수열 크기 만큼 반복하면서
        cin >> x;  //각 수를 입력받기
        if (x > 1) { //수가 1보다 크면
            arr_pos.push_back(x); //양수 배열에 저장
        } else if (x < 1) { //1보다 작으면
            arr_neg.push_back(x); //음수 배열에 저장
        } else { //0이면
            cnt1++; //개수 증가
        }
    }

    //절댓값이 큰 순으로 정렬
    sort(arr_pos.begin(), arr_pos.end(), greater<>());
    sort(arr_neg.begin(), arr_neg.end());

    //연산 & 출력
    cout << cnt1 + tieNumber(arr_pos) + tieNumber(arr_neg);
    return 0;
}