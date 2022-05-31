#include <iostream>
#include <vector>
#include <map>

using namespace std;
const int MAX = 2e5; //친구 관계가 모두 다른 사용자로 들어왔을 때의 정점 최댓값

vector<int> parent(MAX + 1, -1); //부모 배열
map<string, int> people; //친구의 수 저장할 Map

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

/**
 * [친구 네트워크]
 *
 * 1. weighted union find -> 루트 정점에 친구의 수(집합 원소 수) 저장
 * 2. 친구 네트워크에 몇 명 있는지 구하기 -> 루트 정점의 parent값 접근
 *
 * !주의! 정점이 문자열로 들어오므로 map을 활용해 string을 int로 매핑
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, f; //테스트 케이스, 친구 관계 수
    string a, b; //친구 관계 (두개의 아이디)

    //입력
    cin >> t; //테스트케이스 입력
    while (t--) { //tc 반복
        int idx = 1; //정점과 매핑할 수
        parent.assign(MAX + 1, -1); //부모 배열 크기 선언, -1로 초기화

        cin >> f; //친구 관계 수 입력받기
        while (f--) { //반복
            cin >> a >> b; //아이디 두개 입력받기
            if (!people[a]) { //친구 배열에 a 아이디가 없으면
                people[a] = idx++; //a아이디에 매핑된 수 증가
            }
            if (!people[b]) {  //친구 배열에 b 아이디가 없으면
                people[b] = idx++;//b아이디에 매핑된 수 증가
            }

            //연산
            int x = people[a], y = people[b]; //x, y에 각 배열 저장
            unionInput(x, y); //union 연산

            //출력
            cout << -parent[findParent(x)] << '\n';
        }
    }
    return 0;
}