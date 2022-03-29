#include <iostream>
#include <deque>
#include <vector>

using namespace std;

void getCards(vector<deque<int>> &ground, vector<deque<int>> &cards, bool turn) {
    while (!ground[!turn].empty()) {
        cards[turn].push_front(ground[!turn].front());
        ground[!turn].pop_front();
    }
}

void playGame(vector<deque<int>> &ground, vector<deque<int>> &cards, bool turn, int m) { //turn true=도도, false =수연
    turn = false;
    while (m--) {
        ground[turn].push_front(cards[turn].front());
        cards[turn].pop_front();

        if (cards[turn].empty()) {
            break;
        }
        if (cards[turn].front() == 5) { //도도가 종을 칠 수 있는 조건
            getCards(ground, cards, turn);

        } else if (!ground[turn].empty() && !ground[!turn].empty()
                   && cards[turn].front() + ground[!turn].front() == 5) { //수연이가 종을 칠 수 있는 조건
            getCards(ground, cards, turn);
        }
        turn = !turn;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int x, y;
    vector<deque<int>> ground(2);
    vector<deque<int>> cards(2);
    while (n--) {
        cin >> x >> y;
        cards[0].push_front(x); // 도도의 카드덱
        cards[1].push_front(y); // 수연이의 카드덱
    }
    playGame(ground, cards, false, m);

    if (cards[0].size() > cards[1].size()) { //도도의 카드 덱이 더 많으면
        cout << "do\n";
    } else if (cards[0].size() < cards[1].size()) { //수연이의 카드 덱이 더 많으면
        cout << "su\n";
    } else {
        cout << "dosu\n";
    }

    return 0;
}