#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> weight(n);
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    sort(weight.begin(), weight.end()); //추 무게가 가벼운 순서대로 정렬

    int min_weight = 1; //최소 무게 1부터 시작
    for (int i = 0; i < n; i++) { //입력받은 무게 추를 돌면서
        if (min_weight < weight[i]) { //최소 무게가 현재 추의 무게보다 작으면
            break; //측정 불가
        }
        min_weight += weight[i]; //최소 무게에 현재 추의 무게 추가
    }
    cout << min_weight << '\n';
    return 0;
}