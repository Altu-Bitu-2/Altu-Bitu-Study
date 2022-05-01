#include <iostream>
#include <vector>

using namespace std;

vector<int> possibleWeight(int left, int right, int g) {
    vector<int> ans; //답을 저장할 벡터 선언
    while (left < right) { //left가 right보다 작은 동안
        int diff = right * right - left * left; //차이 계산값 저장

        if (diff <= g) { //계산한 값이 g보다 작거나 같은 경우
            if (diff == g) { //같으면
                ans.push_back(right); //현재 몸무게를 답에 추가
            }
            right++; //현재몸무게 증가
        } else { //같지 않으면
            left++; //과거 몸무게 증가
        }
    }
    return ans; //답 벡터 리턴
}

/**
 * [다이어트]
 *
 * left: 성원이가 기억하고 있던 몸무게
 * right: 성원이의 현재 몸무게
 *
 * 같은 위치에서 시작해서 점점 증가하는 투 포인터로 풀이
 * 대신, left ~ right를 모두 고려하는 것이 아니라 left, right 포인터 값 자체만 고려
 *
 * !주의! 몸무게의 범위가 딱히 정해져 있지 않으므로, 종료 조건을 잘 세우는 것이 중요!
 *       -> 두 몸무게가 같아지는 순간 종료!
 *       -> left가 right와 같은 값을 가진다면, 직전 상황은 두 몸무게가 1차이 나는 상황
 *       -> 이때 몸무게 차이가 g 이상이었다는 것은 이후로 나올 수 있는 차이는 무조건 g이상이 된다. (제곱수의 간격은 수가 커질수록 늘어나기 때문)
 */

int main() {
    int g; //증가한 몸무게

    //입력
    cin >> g;

    //연산
    vector<int> ans = possibleWeight(1, 2, g);

    //출력
    if (!ans.size()) { //벡터가 비어있으면
        cout << "-1"; //-1출력
        return 0; //리턴
    }
    for (int i = 0; i < ans.size(); i++) { //벡터 반복해서
        cout << ans[i] << '\n'; //몸무게 출력
    }
    return 0; //리턴
}