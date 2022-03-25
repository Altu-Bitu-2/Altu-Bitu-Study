#include <iostream>
#include <deque>

using namespace std;
deque<int> ground[2];
deque<int> cards[2];

string playGame(int turn) {
    while (turn) {
        if (ground[turn].front() + ground[1 - turn].front() == 5) { //더한게 5라면
            for (auto iter = ground[turn].rbegin(); iter <= ground[turn].rend(); iter++) { //상대방 그라운드 카드를 자신의 덱 뒤에 추가
                cards[1 - turn].push_front(ground[turn].front());
                ground[turn].pop_front();
            }
        } else { //5가 아니라면
            ground[turn].push_front(cards[turn].front()); //그라운드에 내려놓기
            cards[turn].pop_front();
        }
        turn = 1 - turn; //차례 바꿔주기
    }

    if (cards[0].size() > cards[1].size()) { //도도의 카드 덱이 더 많으면
        return "do";
    } else if (cards[0].size() < cards[1].size()) { //수연이의 카드 덱이 더 많으면
        return "su";
    } else {
        return "dosu";
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int x, y;
    string answer;
    while (n--) {
        cin >> x >> y;
        cards[0].push_front(x); // 도도의 카드덱
        cards[1].push_front(y); // 수연이의 카드덱
    }
    while (m--) {
        answer = playGame(0);
    }
    cout << answer;
    return 0;
}