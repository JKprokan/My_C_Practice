#include <iostream>
#include <vector>

using namespace std;

int snail(int N, int M, int R, int C) {
    vector<vector<bool>> visited(N, vector<bool>(M, false)); // 방문한 방 체크
    int direction = 0; // 현재 바라보는 방향 (0: 동쪽, 1: 남쪽, 2: 서쪽, 3: 북쪽)
    int x = 0, y = 0; // 현재 위치
    int count = 0; // 방문한 방의 개수

    while (true) {
        // 방문한 방인지 체크
        if (!visited[x][y]) {
            visited[x][y] = true;
            count++;
        }
        
        // 보물을 찾았으면 루프 종료
        if (x == R - 1 && y == C - 1) {
            break;
        }

        // 다음 방향 계산
        int next_x = x, next_y = y;
        switch (direction) {
            case 0: // 동쪽
                next_y++;
                break;
            case 1: // 남쪽
                next_x++;
                break;
            case 2: // 서쪽
                next_y--;
                break;
            case 3: // 북쪽
                next_x--;
                break;
        }

        // 다음 방향이 유효한지 체크
        if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M || visited[next_x][next_y]) {
            direction = (direction + 1) % 4; // 시계방향으로 90도 회전
        } else {
            x = next_x;
            y = next_y;
        }
    }
    
    return count;
}