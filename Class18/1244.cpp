#include <iostream>
#include <vector>

using namespace std;

//남학생의 스위치 바꾸기
vector<int> changeSwitchBoy(int n, int number, vector<int> switches) {
    for (int i = number; i <= n; i += number) { //배수에 있는 스위치 바꾸기
        switches[i] = !switches[i]; //스위치 상태 변경
    }
    return switches; //스위치 리턴
}

//여학생의 스위치 바꾸기
vector<int> changeSwitchGirl(int n, int number, vector<int> switches) {
    switches[number] = !switches[number]; //스위치 변경
    for (int i = 1; i < number; i++) { //좌우 대칭 검사, 반복하면서
        if ((number + i > n) || (switches[number - i] != switches[number + i])) { //스위치 범위 넘어가거나 좌우 대칭이 아니면
            break;
        }
        switches[number - i] = !switches[number - i]; //스위치 변경
        switches[number + i] = !switches[number + i]; //스위치 변경
    }
    return switches;
}

/**
 * [스위치 켜고 끄기]
 *
 * 남학생 -> 해당 번호의 배수에 해당하는 스위치 상태 바꾸기
 * 여학생 -> 해당 번호를 중심으로 좌우 대칭이면서 가장 많은 스위치 포함하는 구간의 상태 모두 바꾸기
 *
 * 좌우 대칭 검사 시, 스위치 범위 주의 (주어진 스위치 범위 넘어가지 않도록)
 * 스위치 20개씩 출력하는 부분 주의
 */
int main() {
    int n, m; //스위치 개수, 학생수
    int student, number; //성별, 받은 수

    //입력
    cin >> n; //스위치 개수 입력
    vector<int> switches(n + 1, 0); //스위치 벡터 0으로 초기화
    for (int i = 1; i <= n; i++) { //스위치 개수만큼 반복하면서
        cin >> switches[i]; //스위치 상태 입력받기
    }

    //입력 & 연산
    cin >> m; //학생 수 입력받기
    while (m--) {  //학생 수만큼 반복
        cin >> student >> number; //성별, 학생이 받은 수 입력
        if (student == 1) { //남자
            switches = changeSwitchBoy(n, number, switches);
        } else {//여자
            switches = changeSwitchGirl(n, number, switches);
        }
    }

    //출력
    for (int i = 1; i <= n; i++) {
        cout << switches[i] << ' ';
        if (i % 20 == 0) {
            cout << '\n';
        }
    }
    return 0;
}