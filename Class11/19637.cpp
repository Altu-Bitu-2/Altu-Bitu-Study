#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m,strength_num, input;
    string strength_name;
    cin >> n >> m;
    vector<string> name; //칭호를 저장할 벡터
    vector<int> power; //전투력의 상한값 저장할 벡터
    while(n--){
        cin >> strength_name >> strength_num;
        name.push_back(strength_name);
        power.push_back(strength_num);
    }
    for (int i = 0; i < m; i++) {
        cin >> input;
        //lower_bound를 이용해 이분탐색
        cout << name[lower_bound(power.begin(), power.end(), input) - power.begin()] << '\n';
    }
    return 0;
}