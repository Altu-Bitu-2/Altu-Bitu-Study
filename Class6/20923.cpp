#include <iostream>
#include <deque>

using namespace std;

void playGame(deque<int> *ground, deque<int> *cards, bool turn) { //turn true=도도, false =수연
    cout << "OUT\n";
    if (ground[turn].front() + ground[!turn].front() == 5 && !ground[turn].empty() &&
        !ground[!turn].empty()) { //수연이가 종을 칠 수 있는 조건
        cout << "IF1 \n";
        for (auto iter = ground[turn].rbegin(); iter <= ground[turn].rend(); iter++) { //상대방 그라운드 카드를 자신의 덱 뒤에 추가
            cards[!turn].push_front(ground[turn].front());
            ground[turn].pop_front();
        }
    }
    if (ground[turn].front() == 5 || ground[!turn].front() == 5) { //도도가 종을 칠 수 있는 조건
        cout << "IF2 \n";
        for (auto iter = ground[!turn].rbegin(); iter <= ground[!turn].rend(); iter++) {
            cards[turn].push_front(ground[!turn].front());
            ground[!turn].pop_front();
        }
    }
    cout << "OUT2\n";
    cout << turn;
}

int main() {
    int n, m;
    cin >> n >> m;
    int x, y;
    string answer;
    deque<int> ground[2];
    deque<int> cards[2];
    while (n--) {
        cin >> x >> y;
        cards[0].push_front(x); // 도도의 카드덱
        cards[1].push_front(y); // 수연이의 카드덱
    }
    bool turn = false;
    while (m--) {
        cout << "[" << m << "]\n";
        ground[turn].push_front(cards[turn].front());
        cards[turn].pop_front();
        playGame(ground, cards, turn);
        turn = !turn; //차례를 바꿔줌
        if (cards[turn].empty() || cards[!turn].empty()) { //둘 중에 하나라도 카드가 0개가 되면 ㄱ
            if (turn) {
                cout << "su\n";
            } else {
                cout << "do\n";
            }
        }
    }
    if (!cards[turn].empty() || !cards[!turn].empty()) {
        if (cards[0].size() > cards[1].size()) { //도도의 카드 덱이 더 많으면
            cout << "do";
        } else if (cards[0].size() < cards[1].size()) { //수연이의 카드 덱이 더 많으면
            cout << "su";
        } else {
            cout << "dosu";
        }
    }
    return 0;
}