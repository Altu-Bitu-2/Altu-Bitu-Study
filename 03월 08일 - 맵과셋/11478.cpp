#include <iostream>
#include <set>

using namespace std;
int main() {

    set<string> s;       //중복 제거할 set
    string input_string; //입력하는 string
    cin >> input_string;
    string str; //저장하는 substring

    for (int i = 0; i < input_string.size(); i++) {
        for (int j = 0; j < input_string.size(); j++) {
            s.insert(input_string.substr(i, j));
        }
    }
    cout << s.size() << "\n";
    return 0;
}