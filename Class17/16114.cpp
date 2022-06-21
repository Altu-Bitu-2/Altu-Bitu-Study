#include <iostream>

using namespace std;

string solution(int x, int n) {
    if (n > 1 && n % 2 == 1) { //n이 1보다 크고, 홀수라면
        return "ERROR"; //에러
    }
    if (n == 1 && x < 0) { //n이 1이면서 x는 음수인 경우
        return "INFINITE"; //항상 참이므로 infinite
    }
    if (n == 1 || x <= 0) { //n이 1이고 x가 양수이거나 x가 0보다 작거나 같으면
        return "0"; //while문이 실행되지 않음, 0 리턴
    }
    if (n == 0) { //n이 0이고 x는 양수이면
        return "INFINITE"; //while문 항상 참
    }
    return to_string((x - 1) / (n / 2)); //x-1을 n/2로 나눈 나머지를 string으로 변환해 리턴
}

/**
 * [화살표 연산자]
 *
 * 1. n이 1보다 큰 홀수인 경우 -> ERROR
 * 2. n이 1인데 x가 음수인 경우 -> while문 조건 항상 참 -> INFINITE
 * 3. n이 1인데 x가 양수인 경우 or x가 0보다 작거나 같은 경우 -> while문에 진입 못함 -> 0
 * 4. n이 0인데 x가 양수인 경우 -> while문 조건 항상 참 -> INFINITE
 * 5. 나머지 경우엔 (x - 1)을 (n / 2)로 나눈 몫을 출력
 *    - 연산했을 때 1 이상이 남을 때까지만 출력을 할 수 있으므로 1을 뺀 값에서 몫을 구함
 */

int main() {
    int x, n; //변수 x의 초기값, 화살표 길이

    //입력
    cin >> x >> n;

    //연산 & 출력
    cout << solution(x, n);
    return 0;
}