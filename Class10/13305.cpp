#include <iostream>
#include <vector>

using namespace std;

//범위가 int를 넘어가는 경우가 있으므로 long long으로 선언해야함
long long minPrice(int n, vector<long long> &road, vector<long long> &price) {
    long long min_cost = price[0]; //첫 도시는의 가격을 min_cost에 저장
    long long cost = 0; //최종 비용
    for (int i = 0; i < n - 1; i++) { //도시를 지나가면서
        if (min_cost > price[i]) { //만약 현재 도시의 가격이 더 싸다면
            min_cost = price[i]; //min_cost 업데이트해줌
        }
        cost += min_cost * road[i]; //최종 비용에 현재 도시의 비용*거리
    }
    return cost;
}

int main() {
    long long n;
    cin >> n;
    vector<long long> road(n - 1, 0);
    vector<long long> price(n, 0);
    for (int i = 0; i < n - 1; i++) {
        cin >> road[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }

    cout << minPrice(n, road, price);
    return 0;
}