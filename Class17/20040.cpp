#include <iostream>
#include <vector>

using namespace std;

vector<int> parent; //부모 벡터 선언

//Find 연산
int findParent(int node) {
    if (parent[node] < 0) { //값이 음수면 루트 정점
        return node; //루트 리턴
    }
    return parent[node] = findParent(parent[node]); //그래프를 압축해 루트 정점 찾기
}

//Union 연산
bool unionInput(int x, int y) {
    int xp = findParent(x); //find 연산 -> 정점 찾기
    int yp = findParent(y); //find 연산 -> 정점 찾기

    if (xp == yp) { //이미 같은 집합에 있는 경우
        return false; //false 리턴
    }
    if (parent[xp] < parent[yp]) { //새로운 루트 xp
        parent[xp] += parent[yp]; //yp 정점을 xp에 연결
        parent[yp] = xp; //결합
    } else { //새로운 루트 yp
        parent[yp] += parent[xp]; //xp 정점을 yp에 연결
        parent[xp] = yp; //결합
    }
    return true; //true 리턴
}

/**
 * [사이클 게임]
 *
 * 사이클이 발생한 순간 = 같은 집합에 있는 원소 두 개를 유니온하려 할 때
 * unionInput 함수의 반환형을 bool로 선언하여 cycle이 생성되는 순간 발견하기
 */

int main() {
    int n, m, x, y; //점의 개수, 진행된 차례의 수, i번째 차례에 해당 플레이어가 선택한 두 점의 번호

    //입력
    cin >> n >> m; //입력받기
    parent.assign(n, -1); //부모 배열 크기 선언, -1로 초기화
    for (int i = 0; i점 < m; i++) { //차례의 수만큼 반복하면서
        cin >> x >> y; //플레이어가 선택한 점 입력받기

        //연산 & 출력
        if (!unionInput(x, y)) { //사이클이 생성됨
            cout << i + 1; //차례의 번호 출력
            return 0; //리턴
        }
    }
    cout << 0; //종료되지 않은 경우 0 출력
    return 0; //리턴
}