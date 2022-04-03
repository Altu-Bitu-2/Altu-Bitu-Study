#include <deque>
#include <iostream>
#include <vector>

using namespace std;

void getCards(deque<int> &cards, deque<int> &ground) { //그라운드에 있는 카드 가져오기
    while (!ground.empty()) {                          //그라운드가 빌때까지
        cards.push_back(ground.back());                //그라운드의 카드들을 카드덱으로 가져오기
        ground.pop_back();                             //그라운드 카드 빼기
    }
}

void playGame(vector<deque<int>> &ground, vector<deque<int>> &cards, bool turn, int m) { // turn true=도도, false =수연
    turn = false;                                                                        //현재 턴
    while (m--) {                                                                        //반복하면서
        int card = cards[turn].front();                                                  //카드덱 첫번째 카드 저장
        ground[turn].push_front(cards[turn].front());                                    //그라운드에 카드 놓기
        cards[turn].pop_front();

        if (cards[turn].empty()) { //카드덱이 비어있으면 break
            break
        }
        int bell = -1;   //종 치는 사람
        if (card == 5) { //도도가 종을 칠 수 있는 조건
            bell = 0;    //도도가 종을 친다

        } else if (!ground[turn].empty() && !ground[!turn].empty() && (card + ground[!turn].front() == 5)) { //수연이가 종을 칠 수 있는 조건
            bell = 1;                                                                                        //수연이가 종을 친다
        }
        if (bell != -1) {                         //종을 쳤다면 조건이라면
            getCards(cards[bell], ground[!bell]); //상대 그라운드 카드 가져오기
            getCards(cards[bell], ground[bell]);  //본인 그라운드 카드 가져오기
        }
        turn = !turn; //턴 바꿔주기
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