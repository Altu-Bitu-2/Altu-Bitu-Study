#include <iostream>
#include <map>
#include <string>

using namespace std;

long long calculateMin(int hour, int min) {
    return hour * 60 + min;
}

int main() {
    string s, e, q;
    map<string, int> m;
    cin >> s >> e >> q;
    int start_hour = stoi(s.substr(0, 2));
    int start_min = stoi(s.substr(3, 2));
    int end_hour = stoi(e.substr(0, 2));
    int end_min = stoi(e.substr(3, 2));
    int quit_hour = stoi(q.substr(0, 2));
    int quit_min = stoi(q.substr(3, 2));

    freopen("input.txt", "r", stdin);

    while (!cin.eof()) {
        string time, name;
        int hour, min;
        cin >> time >> name;
        hour = stoi(time.substr(0, 2));
        min = stoi(time.substr(3, 2));
        if (calculateMin(hour, min) <= calculateMin(start_hour, start_min)) {
            m[name] = 1;
        } else if ((calculateMin(hour, min) >= calculateMin(end_hour, end_min) &&
                    calculateMin(hour, min) <= calculateMin(quit_hour, quit_min))) {
            m[name] = 2;
        }
        int count = 0;
        for (auto iter = m.begin(); iter != m.end(); iter++) {
            if (iter->second == 2) {
                count++;
            }
        }
        cout << count << "\n";
    }
    return 0;
}