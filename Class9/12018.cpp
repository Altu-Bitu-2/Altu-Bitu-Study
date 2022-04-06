#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int person, max_person, input;
    int count = 0;
    priority_queue<int, vector<int>, greater<>> pq;
    while (n--) {
        cin >> person >> max_person;
        vector<int> v(person);
        while (person--) {
            cin >> input;
            v.push_back(input);
        }
        sort(v.begin(), v.end(), greater<>()); //내림차순 정렬
        if (person >= max_person) { //수강인원보다 신청 인원이 같거나 많으면
            pq.push(v[max_person - 1]); //수강신청이 가능한 마일리지를 pq에 푸시해줌
        } else {
            pq.push(1); //정원보다 신청인원이 작으면 1로도 수강 가능
        }
    }

    while (!pq.empty()) { //pq가 비어있지 않을때까지
        m -= pq.top(); //마일리지를 순서대로 차감
        pq.pop();
        if (m >= 0) { //마일리지가 남아있을 경우에
            count++; //수강신청 성공한 과목 수 추가
        } else {
            break;
        }
    }
    cout << count << '\n';
    return 0;
}