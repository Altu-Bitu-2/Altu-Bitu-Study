#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

//Find 연산
int findParent(int node) {
    if (parent[node] < 0) { //값이 음수면 루트 정
        return node; //루트 리턴
    }
    return parent[node] = findParent(parent[node]); //그래프 압축해 루트 정점 찾기
}

//Union 연산
void unionInput(int x, int y) {
    int xp = findParent(x); //find 연산 -> 정점 찾기
    int yp = findParent(y); //find 연산 -> 정점 찾기

    if (xp == yp) { //이미 같은 집합에 있는 경우
        return; //리턴
    }
    if (parent[xp] < parent[yp]) { //새로운 루트 xp
        parent[xp] += parent[yp]; //yp 정점을 xp에 연결
        parent[yp] = xp; //결합
    } else { //새로운 루트 yp
        parent[yp] += parent[xp]; //xp 정점을 yp에 연결
        parent[xp] = yp; //결합
    }
}

int liarParty(vector<int> &parties) { //거짓말 할 수 있는 파티 개수 찾기
    int cnt = 0; //개수 0으로 초기화
    for (int i = 0; i < parties.size(); i++) {//파티 개수만큼 반복
        if (findParent(parties[i]) != findParent(0)) { //find연산을 하면서 0과 같은 집합이 아니면
            cnt++; //개수 증가
        }
    }
    return cnt; //개수 리턴
}

/**
 * [거짓말]
 *
 * 1. 각 사람들은 다양한 파티를 통해 연결됐다고 할 수 있음
 * 2. 연결된 사람들은 같은 집합에 속함
 * 3. 각 집합에 속한 사람들 중 한 명이라도 진실을 안다면 그 집합의 사람들이 속한 파티에는 거짓말을 할 수 없음
 * -> 유니온 파인드로 사람들을 집합으로 묶은 뒤, 파티마다 거짓말을 할 수 있는지 확인하기
 * -> 이때, 진실을 아는 사람들의 루트 정점을 0으로 설정해서 유니온 파인드를 통해 집합으로 묶고 시작
 * -> 0과 같은 집합이 아니어야 거짓말을 할 수 있음
 *
 * !주의! 파티 정보를 입력받으며 바로 거짓말 가능 여부를 판단할 수 없음 (예제 입력 4)
 *       각 파티에서 한 사람만 저장해둔 뒤, 마지막에 거짓말 가능 여부 한 번에 판단
 */

int main() {
    int n, m; //사람 수, 파티 수

    //입력
    cin >> n >> m; //입력받기
    parent.assign(n + 1, -1); //부모 벡터 크기 선언, -1로 초기화

    int init, p; //진실을 아는 사람의 수, 번호
    cin >> init; //입력받기
    while (init--) { //진실을 아는 사람들
        cin >> p; //진실을 아는 사람의 번호
        unionInput(0, p); //유니온 연산
    }

    int cnt, first_person, person; //파티마다 오는 사람의 수, 번호
    vector<int> parties; //파티 벡터
    while (m--) { //파티의 수만큼 반복
        cin >> cnt >> first_person; //사람 수, 첫번째 사람 입력

        //연산
        parties.push_back(first_person); //파티 정보로 각 파티의 첫번째 사람만 저장
        while (--cnt) { //사람 수만큼 반복
            cin >> person; //사람 번호 입력
            unionInput(first_person, person); //유니온 연산
        }
    }

    //연산 & 출력
    cout << liarParty(parties); //파티 개수 최댓값 출력
    return 0;
}