#include <iostream>
#include <stack>
#include <map>

using namespace std;

int isBalanced(string &s) {
    stack<char> st;
    map<char, char> m;
    m[']'] = '[';
    m[')'] = '(';
    int sum = 1;
    int tot = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') { //소괄호면 스택에 넣어주고 2배 곱해준다.
            st.push(s[i]);
            sum *= 2;

        } else if (s[i] == '[') { //대괄호면 스택에 넣어주고 3배 곱해준다.
            st.push(s[i]);
            sum *= 3;

        } else if (s[i] == ')') { //닫는 소괄호가 입력된 경우
            if (st.empty()) { //스택이 비어있었다면 괄호쌍이 잘못된 것이므로 0
                tot = 0;
            } else if (!st.empty() && st.top() == '(') { //스택의 top이 여는 소괄호라면 맞는 괄호쌍이므로
                st.pop(); //pop해주고
                tot += sum; //전체 합에 지금까지의 sum합을 더해준다
                sum /= 2; //곱해진 값이 끝났으므로 다시 나누어준다
            }
        } else if (s[i] == ']') {
            if (st.empty()) {
                tot = 0;
            } else if (!st.empty() && st.top() == '[') {
                st.pop();
                tot += sum;
                sum /= 3;
            }
        }
    }

    return tot;
}

int main() {
    string str;
    getline(cin, str);
    cout << isBalanced(str) << '\n';
    return 0;
}