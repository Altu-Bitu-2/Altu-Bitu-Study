#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, char> ci; //구조체 선언

//특정 화살표에서 시작한 행운의 바퀴 리턴
string arrowStartWheel(int arrow_point, int n, vector<char> &wheel) {
    string ans = ""; //정답 string 초기화
    int start = arrow_point; //시작지점은 arrow_point부터
    do { //do-while문 실행
        ans += wheel[arrow_point]; //화살표가 가리키는 바퀴의 글자를 추가함
        arrow_point = (arrow_point + 1) % n; //화살표가 가리키는 곳 업데이트
    } while (arrow_point != start); //화살표가 start와 같지 않을때까지 반복
    return ans; //정답 리턴
}

//행운의 바퀴 구하는 함수
string makeWheel(int n, vector<ci> &record) {
    vector<char> wheel(n, '?'); //바퀴의 상태
    vector<bool> is_available(26, false); //알파벳 중복 체크

    int idx = 0; //화살표가 가리키는 인덱스
    for (int i = 0; i < record.size(); i++) { //record 벡터의 크기만큼 반복
        int rot = record[i].first; //record의 i번째 원소의 first(글자가 변경된 횟수)
        char alpha = record[i].second; //record의 i번째 원소의 second(가리키던 글자)
        idx = (idx - rot % n + n) % n; //idx값 계산
        if (wheel[idx] == alpha) { //가리키던 글자와 바퀴의 idx번째 글자가 같으면
            continue; //다음 코드 실행
        }
        if (wheel[idx] != '?' || is_available[alpha - 'A']) { //바퀴의 idx번째 글자가 ?가 아니거나 가리키던 글자가 true이면
            return "!"; //!를 리턴
        }
        wheel[idx] = alpha; //wheel idx를 변경
        is_available[alpha - 'A'] = true; //true로 변경
    }
    return arrowStartWheel(idx, n, wheel);
}

/**
 * [행운의 바퀴]
 *
 * 바퀴가 돌아갈 필요 X
 * 화살표가 가르키는 인덱스를 회전 정보에 따라 바꿔줌
 *
 * 1. 화살표가 가르키는 칸이 결정되지 않았으면 알파벳을 바퀴에 적는다.
 * 2. 이미 알파벳이 써 있는 경우, 같은 알파벳이 아닌 경우 조건에 해당하는 바퀴 만들 수 없다.
 * 3. 바퀴에 쓰여있는 알파벳은 중복되지 않으므로 동일한 알파벳이 여러 자리에 있을 수 없다.
 */

int main() {
    int n, k; //바퀴의 칸 수, 상덕이가 바퀴를 돌리는 횟수

    //입력
    cin >> n >> k;
    vector<ci> record(k, {0, 0}); //바퀴 회전 기록
    for (int i = 0; i < k; i++) { //k-1까지 반복해서
        cin >> record[i].first >> record[i].second; //record벡터에 쌍으로 저장
    }

    //연산 & 출력
    cout << makeWheel(n, record);
    return 0; //리턴
}