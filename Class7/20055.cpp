#include <iostream>
#include <deque>
#include <vector>

using namespace std;
deque<int> belt;
deque<bool> robot;
int n, k;
int step = 1;

int checkZero() { //4. 내구도 0 개수 체크하기
    int count = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (belt[i] == 0) {
            count++;
        }
    }
    return count;

}


void moveRobot() { //2. 로봇 움직이기
    if (robot[n - 1]) { //내리는 벨트에 로봇이 있으면
        robot[n - 1] = false; //그 벨트에서는 로봇이 없는 상태로 변경
    }
    for (int i = n - 2; i >= 0; i--) {//내리는 벨트 직전까지
        if (robot[i] && !robot[i + 1] && belt[i + 1] != 0) {//다음 칸에 로봇이 없으면서 내구도가 0 보다 크면
            robot[i] = false; //현재 로봇이 있던 벨트는 로봇 없어짐
            belt[i + 1]--; //다음 벨트 내구도 감소
            if (i != n - 2) { //내리는 벨트 직전이아니라면
                robot[i + 1] = true; //현재 로봇이 있던 벨트의 다음 벨트는 true(로봇 이동)
            } else {
                robot[i + 1] = false;
            }

        }
    }
}

void addRobot() { //3. 로봇 올리기
    if (!robot.front() && belt.front() != 0) { //0번 벨트에 로봇이 없고 내구도가 0이 아니면
        robot.front() = true; //0번에 로봇을 올리고
        belt[0]--; //내구도 감소
    }
}

void rotateBelt() { //1. 벭트 회전시키기
    belt.push_front(belt.back());
    belt.pop_back();
    robot.push_front(robot.back());
    robot.pop_back();
}

void operate() {
    while (true) {
        rotateBelt();
        moveRobot();
        addRobot();
        if (checkZero() < k) {
            step++;
        } else {
            break;
        }
    }
    cout << step << "\n";
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < 2 * n; i++) {
        int input;
        cin >> input;
        belt.push_back(input);
        robot.push_back(false);
    }
    operate();
    return 0;
}