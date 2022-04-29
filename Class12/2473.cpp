#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;
const int INF = 2e9 + 1;

vector<int> findLiquid( vector<int> &liquid, int n) {
    int min_diff = INF;
    vector<int> ans(3, 0); //출력할 세가지 용액을 저장할 벡터 선언
    for (int i = 0; i <n; i++) {
        int left = i+1; //용액의 가장 왼쪽
        int right = n-1;//용액의 가장 오른쪽
        while (left < right) { //이분탐색(왼쪽이 오른쪽보다 작은 동안)
            long long mix = liquid[i] + liquid[left] + liquid[right]; //범위 고려해서 세가지 용액을 섞은 합 선언
            if (abs(mix) < min_diff) { //현재의 최솟값보다 작으면
                min_diff = abs(mix); //최솟값 업데이트
                ans[0] = liquid[i]; //정답 배열에 저장해줌
                ans[1] = liquid[left];
                ans[2] = liquid[right];
            }
            if (mix > 0) { //0보다 크면
                right--; //큰 값을 줄여줌
            } else { //0보다 작으면
                left++; //작은 값을 키움
            }
        }

    }
    return ans;

}

int main() {
    int n;
    cin >> n;
    vector<int> liquid(n, 0); //용액 저장할 벡터
    for (int i = 0; i < n; i++) {
        cin >> liquid[i]; //입력
    }
    sort(liquid.begin(), liquid.end()); //정렬
    vector<int> ans = findLiquid(liquid,  n);
    for (int i = 0; i < 3; i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}