#include <iostream>
#include <vector>

using namespace std;

int steal(int n, int m, int k, vector<int> &house) {
    //윈도우 초기화
    int money = 0;
    for (int i = 0; i < m; i++) { //훔칠 집 개수만큼 반복하면서
        money += house[i]; //돈을 추가함
    }
    int ans = money < k; //훔쳐야 하는 집 초기화

    if (n == m) { //훔칠 수 있는 경우 딱 1개인 경우
        return ans; //답 리턴
    }
    for (int i = m; i < n + m - 1; i++) { //i : m부터 n-1개 반복
        money -= house[i - m]; //전체 돈에서 가장 왼쪽 윈도우를 빼줌
        money += house[i % n]; //전체 돈에서 가장 오른쪽 윈도우를 더해줌
        if (money < k) { //최소 돈의 양보다 작으면
            ans++; //답 추가
        }
    }
    return ans; //답 리턴
}

/**
 * [도둑]
 *
 * 1. 연속해서 훔쳐야 할 집이 m으로 고정됐기 때문에 슬라이딩 윈도우
 * 2. 직선이 아니라 원 형태의 배열! 모듈러 연산을 통해 윈도우의 양 끝 위치 조절하기
 * !주의! 마을에 있는 집의 개수와 도둑이 훔칠 집의 개수가 같을 때(n==m) 도둑이 훔칠 수 있는 경우의 수 1개!
 *    => 예를 들어, n = m = 3, k = 4, house = [1, 1, 1] 일 때, 실제 방법의 수는 1번, 2번, 3번 집을 택하는 경우밖에 없지만
 *       예외 처리를 안해줄 경우, 원형으로 돌며 3을 출력하게 됨!
 */

int main() {
    int t, n, m, k; //테스트개수, 마을 집의 개수, 돈을 훔칠 연속된 집의 개수, 최소 돈의 양

    cin >> t; //테스트케이스 입력받기
    while (t--) { //테스트케이스 반복 실행
        //입력
        cin >> n >> m >> k; //마을 집의 개수, 돈을 훔칠 연속된 집의 개수, 최소 돈의 양 입력
        vector<int> house(n, 0);//집마다 보관하고 있는 돈을 저장할 벡터 선언
        for (int i = 0; i < n; i++) { //집 개수만큼 반복하면서
            cin >> house[i]; //돈 저장
        }

        //연산 & 출력
        cout << steal(n, m, k, house) << '\n';
    }
    return 0; //리턴
}