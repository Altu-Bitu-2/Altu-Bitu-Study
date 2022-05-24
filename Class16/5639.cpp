#include <iostream>

using namespace std;

struct node_info { //구조체 선언
    int data; //원소
    node_info *left; //왼쪽 트리
    node_info *right; //오른쪽 트리
};

node_info *makeTree(node_info *node, int data) {
    if (node == NULL) { //이번 노드가 들어가게될 위치
        node = new node_info(); //동적 할당
        node->data = data; //원소 저장
        node->left = node->right = NULL; //왼쪽, 오른쪽 트리 NULL로 저장
    } else if (node->data > data) { //노드의 원소가 입력받은 원소보다 크면
        node->left = makeTree(node->left, data); //왼쪽 트리에 저장
    } else if (node->data < data) { //노드의 원소가 입력받은 원소보다 작으면
        node->right = makeTree(node->right, data); //오른쪽 트리에 저장
    }
    return node; //노드 리턴
}

//후위 순회
void postorder(node_info *node) {
    if (node == NULL) { //노드가 NULL이면
        return;//리턴
    }
    postorder(node->left); //왼쪽 트리 순회
    postorder(node->right); //오른쪽 트리 순회
    cout << node->data << '\n'; //현재 노드 원소 출력
}

/**
 * 맵과 셋 PPT 중 BST 노드 삽입 과정 참고
 *
 * [이진 검색 트리]
 *
 * 1. 포인터로 왼쪽, 오른쪽 서브트리를 가리키는 구조체 선언
 * 2. NULL 만날 때까지 조건에 따라 왼쪽 또는 오른쪽으로 이동
 * 3. 노드가 들어갈 위치를 찾으면 동적할당 후 노드 만들기
 * 4. 완성한 트리를 후위 순회
 */

int main() {
    int input; //트리 전위 순회 결과 원소

    //입력 & 연산
    node_info *root = NULL; //NULL로 초기화
    while (cin >> input) { //입력을 받는 동안
        root = makeTree(root, input); //트리를 만들어 저장
    }

    //출럭
    postorder(root); //후위순회 결과 출력
    return 0; //리턴
}