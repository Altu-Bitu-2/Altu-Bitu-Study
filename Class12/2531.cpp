#include <iostream>
#include <vector>

using namespace std;

int chooseSushi(int n, int d, int k, int c, vector<int> &belt) {
    vector<int> sushi(d + 1, 0); //초밥 먹은 개수

    //쿠폰으로 먹은 초밥
    int section_sushi = 1;
    sushi[c]++; //먹은 초밥 수 증가(쿠폰 초밥은 항상 먹게됨)

    //윈도우 초기화
    for (int i = 0; i < k; i++) { //연속해서 먹는 접시의 수만큼 반복
        if (!sushi[belt[i]]) { //해당 벨트의 초밥을 먹지 않았다면
            section_sushi++; //먹은 초밥 증가
        }
        sushi[belt[i]]++;//먹은 초밥 수 증가
    }

    int ans = section_sushi; //최대 먹은 초밥 개수
    for (int i = k; i < n + k; i++) { //슬라이딩 윈도우
        sushi[belt[i - k]]--; //윈도우에서 제외되는 값
        if (!sushi[belt[i - k]]) { //먹은 초밥 개수가 없다면
            section_sushi--; //개수 감소
        }
        if (!sushi[belt[i % n]]) { //먹은 초밥이 아니라면
            section_sushi++; //개수 증가
        }
        sushi[belt[i % n]]++; //윈도우에 추가되는 값
        ans = max(ans, section_sushi); //최대 먹은 초밥 개수 갱신
    }
    return ans; //개수 리턴
}

/**
 * [회전 초밥]
 *
 * 1. 연속해서 먹어야 할 접시가 k로 고정됐기 때문에 슬라이딩 윈도우
 * 2. 직선이 아니라 원 형태의 배열! 모듈러 연산을 통해 윈도우의 양 끝 위치 조절하기
 * 3. 쿠폰으로 먹은 초밥을 먼저 고려해놓기
 * 4. 초밥의 종류가 최대 3000개로 많지 않음. 각 종류별 먹은 초밥의 개수를 세어주기
 */

int main() {
    int n, d, k, c; //접시의 수, 초밥의 가짓수, 연속해서 먹는 접시의 수, 쿠폰 번호

    //입력
    cin >> n >> d >> k >> c; //입력받기
    vector<int> belt(n, 0); //벨트 벡터 선언 (크기 n)
    for (int i = 0; i < n; i++) { //n만큼 반복해서
        cin >> belt[i]; //벨트에 종류 저장
    }

    //연산 & 출력
    cout << chooseSushi(n, d, k, c, belt); //함수 호출,출력
    return 0; //리턴
}