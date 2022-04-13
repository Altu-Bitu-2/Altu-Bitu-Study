#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int weight, I_before, T; //다이어트 전 체중, 다이어트 전 일일에너지 섭취량 & 기초대사량, 기초대사량 변화 역치
    int D, I, A; //다이어트 기간, 일일에너지섭취량, 일일활동대사량
    cin >> weight >> I_before >> T;
    cin >> D >> I >> A;

    int weight1 = weight; //기초대사량 변화 빈영 안한 체중
    int weight2 = weight; //기초대사량 변화 반영한 체중

    int I_after = I_before; //기초대사량 변화
    while (D--) { //D일동안
        weight1 += I - (I_before + A); //체중 계산
        weight2 += I - (I_after + A);
        if (abs(I - (I_after + A)) > T) { //기초대사량 변화 반영하는 경우 절댓값이 역치보다 크면
            float temp = (I - (I_after + A)) ; //변화 계산 -> 소수점 계산에 유의해야함!!
            I_after += floor(temp/2); //내림한 것을 기초대사량에 더해줌
        }
    }
    if (weight1 <= 0) { //몸무게가 0보다 작으면
        cout << "Danger Diet\n";
    } else {
        cout << weight1 << " " << I_before << "\n";
    }
    if (weight2 <= 0 || I_after <= 0) { //변한 기초대사량이 0보다 작거나 채중이 0보다 작으면
        cout << "Danger Diet\n";
    } else {
        if (I_after < I_before) { //변화된 기초대사량이 다이어트 전 기초대사량보다 작아지면
            cout << weight2 << " " << I_after << " YOYO\n"; //요요
        } else {
            cout << weight2 << " " << I_after << " NO\n";
        }
    }
    return 0;
}