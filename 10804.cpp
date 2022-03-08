
#include <iostream>
#include <vector>

using namespace std;

//주소값으로 받아야 정렬이 됨!!
void swapArr(vector<int> &arr, int start, int end) {
    while (start < end || start == end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main() {
    int start, end;
    vector<int> arr;
    arr.assign(21, 0);

    for (int i = 1; i <= 20; i++) {
        arr[i] = i; //초기 배열
    }
    for (int i = 0; i < 10; i++) {
        cin >> start >> end;
        swapArr(arr, start, end);
    }
    for (int i = 1; i <= 20; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

