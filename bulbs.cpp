#include <iostream>
#include <vector>
using namespace std;

int bulbs1(int N, vector<int>& arr) {
    int count = 0; // 전구를 뒤집는 횟수를 세는 변수
    vector<int> current_state(N, 0); // 초기 상태는 모두 꺼져있다고 가정

    for (int i = 0; i < N; ++i) {
        if ((arr[i] + count) % 2 != current_state[i]) { // 현재 전구 상태와 원하는 상태가 다르면 뒤집기 필요
            count++; // 전구 뒤집는 횟수 증가
            if (i < N - 1) // 마지막 전구가 아니면 양 옆의 전구도 뒤집어야 함
                current_state[i+1] = 1 - current_state[i+1];
            if (i > 0) // 첫 번째 전구가 아니면 양 옆의 전구도 뒤집어야 함
                current_state[i-1] = 1 - current_state[i-1];
        }
    }

    return count;
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    int result = bulbs1(N, arr);
    cout << result << endl;

    return 0;
}
