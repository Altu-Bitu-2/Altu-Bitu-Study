#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> innings; //이닝
vector<int> order(10, 0); //타순
vector<bool> check(10, false); //방문 여부 확인
int n, ans; //이닝, 점수

//각 루타마다 얻는 점수
int hitScore(int hit, vector<bool> &baseman) {
    int score = 0; //점수 초기화
    for (int i = 3; i >= 0; i--) { //각 루에 있던 선수들 한 칸씩 앞으로
        if (!baseman[i]) { //baseman이 false라면
            continue; //다음 코드로
        }
        if (i + hit >= 4) { //현재 루와 공격상태 합이 4보다 크거나 같으면(홈으로 들어가면)
            score ++; //점수 증가
        } else { //그렇지 않으면
            baseman[i + hit] = true; //루 변경
        }
        baseman[i] = false; //false로 변경
    }
    if (hit == 4) { //홈런이라면
        score++; //점수 증가
    } else {
        baseman[hit] = true; //새로운 선수들 홈에 도착
    }
    return score; //점수 리턴
}

//현재 배치의 점수
int calcScore() {
    int score = 0; //총 점수
    int idx = 1; //타순 저장된 order 인덱스 번호
    for (int i = 0; i < n; i++) { //i: 이닝
        vector<bool> baseman(4, 0); //각 루수마다 선수가 있는지
        int out = 0; //아웃 선수 카운트
        while (out < 3) { //out이 3보다 작을때까지
            int state = innings[i][order[idx++]]; //현재 선수의 공격 상태
            if (idx == 10) { //인덱스가 10이면
                idx = 1; //1로 변경
            }
            if (state == 0) { //현재 선수가 아웃이라면
                out++; //out개수 증가
            } else { //0이 아니라면
                score += hitScore(state, baseman); //점수 증가(hitScore함수 리턴값만큼)
            }
        }
    }
    return score; //점수 리턴
}

//가능한 배치 모두 구하기
void findArray(int cnt) { //cnt: 타자순서
    if (cnt == 4) { //4번 타자는 정해져 있으므로
        findArray(cnt + 1); //다음 타자 구하기
        return; //리턴
    }
    if (cnt == 10) { //9번 타자까지 정해짐 (기저조건)
        int score = calcScore(); //점수 계산
        ans = max(ans, score); //현재 점수와 이전 최대점수 중 최댓값을 ans에 저장
        return; //리턴
    }
    for (int i = 2; i <= 9; i++) { //2부터 9까지 반복하면서
        if (!check[i]) { //i의 check값이 false이면
            order[cnt] = i; //cnt번 타자: i번 선수
            check[i] = true; //i번 선수 순서 정해짐
            findArray(cnt + 1); //다음 타자
            check[i] = false; //다시 false로 복구
        }
    }
}

/**
 * 구현 + 브루트 포스, 백트래킹
 * 1. 우선 가능한 타순을 모두 구한다. (이때, 4번 타자는 항상 1번 선수여야 함) (브루트 포스, 백트래킹)
 * 2. 구한 타순에 대한 각각의 점수를 구하며 최대 점수를 갱신한다. (구현)
 */

int main() {
    //입력
    cin >> n; //이닝 수
    innings.assign(n, vector<int>(10, 0)); //이닝 이차원 벡터 크기 선언
    for (int i = 0; i < n; i++) { //n-1까지 반복
        for (int j = 1; j < 10; j++) { //1~9까지 반복
            cin >> innings[i][j]; //이닝에서 얻는 결과 입력받기
        }
    }

    //연산
    order[4] = 1; //4번 타자는 1번 선수
    check[1] = true; //1번 선수는 순서 정해짐
    findArray(1); //가능한 배치 모두 구하는 함수 호출

    //출력
    cout << ans;
    return 0; //끝
}