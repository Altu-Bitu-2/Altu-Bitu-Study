#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;

//주어진 정점을 지웠을 때의 리프 노드의 수
int eraseLeafCnt(int node, int &erase_node) {
    if (node == erase_node) { //지울 노드가 현재 노드라면
        return 0; //0 리턴
    }
    if (tree[node].empty() || (tree[node].size() == 1 && tree[node][0] == erase_node)) { //트리 비었거나 트리가 1개인데 지울 노드와 같다면
        return 1; //1 리턴
    }
    int cnt = 0; //카운트 0으로 초기화
    for (int i = 0; i < tree[node].size(); i++) { //트리 크기만큼 반복하면서
        cnt += eraseLeafCnt(tree[node][i], erase_node); //지울 노드 카운트 추가(재귀)
    }
    return cnt; //개수 리턴
}

/**
 * [트리]
 *
 * 기존 리프 노드 개수를 세는 dfs 탐색에서 지우는 정점을 만나면 더 이상 탐색하지 않고 0을 리턴
 *
 * !주의! 지우는 정점이 해당 부모 노드의 유일한 자식 노드였을 경우, 해당 정점을 지우면 부모 노드가 리프 노드가 돼서 개수가 1 증가함을 주의
 * !주의! 루트 노드가 항상 0이 아님을 주의
 */

int main() {
    int n, par, root, erase_node; //노드의 개수, 부모, 노드, 지울 노드 번호

    //입력
    cin >> n;// 노드 개수 입력
    tree.assign(n, vector<int>(0)); //트리 크기 선언
    for (int i = 0; i < n; i++) { //노드 개수만큼 반복
        cin >> par; //부모 노드 입력
        if (par == -1) { //부모가 없다면(루트)
            root = i; //i가 루트랑 동일
            continue; //진행
        }
        tree[par].push_back(i); //부모 노드에 i 추가
    }
    cin >> erase_node; //지울 노드 입력

    //연산 & 출력
    cout << eraseLeafCnt(root, erase_node);
    return 0;
}