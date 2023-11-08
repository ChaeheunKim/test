#include <iostream>
using namespace std;
const int numCell = 3; // 보드판의 가로 세로 길이
char board[numCell][numCell]{}; // 보드판을 나타내는 2차원 배열
bool isValid(int x, int y);
bool checkwin(char currentUser);
int main() {
    // 게임을 진행하는 데 필요한 변수 선언

    int k = 0; // 누구 차례인지 체크하기 위한 변수
    char currentUser = 'X'; // 현재 유저의 돌을 저장하기 위한 변수
    int x, y = 0; // 사용자에게 xy좌표값을 입력받기 위한 변수

    // 보드판 초기화
    for (int i = 0; i < numCell; i++) {
        for (int j = 0; j < numCell; j++) {
            board[i][j] = ' ';
        }
    }

    // 게임을 무한 반복
    while (true) {
        // 1. 누구 차례인지 출력
        // TODO 1.1: 3인용 게임으로 변경
        switch (k % 3) {
        case 0:
            currentUser = 'X';
            break;
        case 1:
            currentUser = 'O';
            break;
        case 2:
            currentUser = 'H';  // H번 유저 추가
        }
        cout << k % 3 + 1 << "번 유저(" << currentUser << ")의 차례입니다. -> ";

        // 2. 좌표 입력 받기
        cout << "(x, y) 좌표를 입력하세요: ";
        int x, y;
        cin >> x >> y;

        // 3. 입력받은 좌표의 유효성 체크
        // TODO FUNC 1: isValid 함수 생성 후 호출
        if (!isValid(x, y)) {
            continue;
        }

        // 4. 입력받은 좌표에 현재 유저의 돌 놓기
        board[x][y] = currentUser;

        // 5. 현재 보드 판 출력
        // TODO 1.2: numCell 숫자에 맞춘 보드판 출력
        for (int i = 0; i < numCell; i++) {
            for (int j = 0; j < numCell; j++) {
                cout << board[i][j];
                if (j < numCell - 1) {
                    cout << "  |";
                }
            }
            cout << endl;
            if (i < numCell - 1) {
                for (int t = 0; t < numCell; t++) {
                    cout << "----" ;
                }
                cout << endl;
            }
        }
        cout << endl;
    

        bool isWin = false; // 승리 여부
        // TODO FUNC2: 6.1부터 6.2까지 checkWin 함수 생성 후 호출
        // 6.1. 가로/세로 돌 체크하기
        isWin = checkwin(currentUser);

        // 6.2. 대각선을 체크하기
        // TODO 1.3: numCell에 맞춘 대각선 빙고 체크 코드로 확장
        int a = 0, b = 0; //대각선 빙고 체크 변수
        for (int i = 0; i < numCell; i++) {
            if (board[i][i] == currentUser) {
                a++;
                if (a >= numCell) {
                    cout << "왼쪽 위에서 오른쪽 아래 대각선으로 모두 돌이 놓였습니다!" << endl;
                    isWin = true;
                }
            }
            if (board[i][numCell - i - 1] == currentUser) {
                b++;
                if (b >= numCell) {
                    cout << "오른쪽 위에서 왼쪽 아래 대각선으로 모두 돌이 놓였습니다!" << endl;
                    isWin = true;
                }  
            }
        }
        // 승리자가 결정되었으면 해당 플레이어를 출력하고 게임을 종료한다.
        if (isWin == true) {
            cout << k % 3 + 1 << "번 유저(" << currentUser << ")의 승리입니다!" << endl;
            break;
        }

        // 7. 모든 칸 다 찼는지 체크하기
        int checked = 0;
        for (int i = 0; i < numCell; i++) {
            for (int j = 0; j < numCell; j++) {
                if (board[i][j] == ' ') {
                    checked++;
                }
            }
        }
        if (checked == 0) {
            cout << "모든 칸이 다 찼습니다.  종료합니다. " << endl;
            break;
        }

        k++;
    }

    return 0;
}
//checkwin 함수
bool checkwin(char currentUser) {
    bool isWin = false;
    int c = 0, d = 0; // 가로, 세로 빙고 체크 변수

    for (int i = 0; i < numCell; i++) {
        c = 0; // 가로 빙고 체크 변수 초기화
        d = 0; // 세로 빙고 체크 변수 초기화

        for (int j = 0; j < numCell; j++) {
            if (board[i][j] == currentUser) {
                c++;
            }
            if (board[j][i] == currentUser) {
                d++;
            }
        }

        if (c >= numCell) {
            isWin = true;
            cout << "가로에 모두 돌이 놓였습니다!!" << endl;
            break; 
        }

        if (d >= numCell) {
            isWin = true;
            cout << "세로에 모두 돌이 놓였습니다!!" << endl;
            break;
        }
    }
    return isWin;
}
//isValid 함수
bool isValid(int x, int y) {
    if (x >= numCell || y >= numCell) {
        cout << x << "," << y << ": x와 y 중 하나가 범위를 벗어납니다." << endl;
        return false;
    }
    else if (board[x][y] != ' ') {
        cout << x << "," << y << ": 이미 돌이 차있습니다." << endl;
        return false;
    }
    return true;
}