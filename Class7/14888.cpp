#include <iostream>
#include <vector>

using namespace std;
const int INF_MAX = 1e9; //최대값 상수로 저장
const int SIZE = 11; //크기11을 상수로 저장

int n;
vector<int> num(SIZE + 1); //num벡터 선언 (크기 12)
vector<int> expression(4); //0: +, 1: -, 2: *, 3: / //연산자 벡터 선언
int max_value = -INF_MAX, min_value = INF_MAX; //최대, 최소값 저장할 변수 선언

void backtracking(int cnt, int sum) { //cnt: 수 인덱스, sum: 연산 결과
    if (cnt == n - 1) { //연산 모두 완료했다면 (기저조건)
        max_value = max(max_value, sum); //현재 합과 이전 최댓값 중 더 큰값을 최댓값에 새로 저장
        min_value = min(min_value, sum); //현재 합과 이전 최솟값 중 더 작은 값을 최솟값에 새로 저장
        return;//리턴
    }
    for (int i = 0; i < 4; i++) { //연산자 검사
        if (expression[i]) { //진행
            expression[i]--;//연산자 사용하므로 개수 하나 줄임
            int new_sum = 0; //합 0으로 초기화하여 선언
            switch (i) { //연산자 종류에 따라
                case 0: //덧셈
                    new_sum = sum + num[cnt + 1]; //기존 합에 더해줌
                    break; //switch문 종료
                case 1: //뺄셈
                    new_sum = sum - num[cnt + 1]; //기존 합에서 빼줌
                    break;//switch문 종료
                case 2: //곱셈
                    new_sum = sum * num[cnt + 1]; //기존 합에 곱함
                    break;//switch문 종료
                case 3: //나눗셈
                    new_sum = sum / num[cnt + 1];  //기존 합에서 나눗셈
                    break;//switch문 종료
            }
            backtracking(cnt + 1, new_sum); //다음 인덱스 탐색
            expression[i]++; //연산자 개수 복귀
        }
    }
}

/**
 * 연산자 모두 돌려보면서 배치한 후, 각 연산자에 따른 값 계산
 */

int main() {
    //입력
    cin >> n; //입력받기
    for (int i = 0; i < n; i++) { //반복문 돌면서
        cin >> num[i]; //num배열에 입력받기
    }
    for (int i = 0; i < 4; i++) { //반복문 돌려서
        cin >> expression[i]; //연산자 개수 배열에 입력받기
    }

    //연산
    backtracking(0, num[0]); //백트래킹 함수에서 연산하기

    //출력
    cout << max_value << '\n' << min_value; //최댓값, 최솟값 출력
    return 0; //리턴
}