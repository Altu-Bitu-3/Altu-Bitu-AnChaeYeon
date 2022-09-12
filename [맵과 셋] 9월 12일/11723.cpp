#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); //시간 빨라짐

    int n, x; //n:입력 개수 x:삽입할 수
    x >= 0 && x <= 20;
    string cmd; //명령
    set<int> set, all;

    //입력
    cin >> n;
    while (n--) {
        cin >> cmd;
        if (cmd == "add") {
            cin >> x;
            set.insert(x);
        }
        if (cmd == "remove") {
            cin >> x;
            set.erase(x);
        }
        if (cmd == "check") {
            cin >> x;
            if (set.find(x) == set.end()) { //x가 없으면
                cout << "0" << "\n"; //0을 출력
            }
            else { //x가 있으면
                cout << "1" << "\n"; //1을 출력
            }
        }
        if (cmd == "toggle") {
            cin >> x;
            if (set.find(x) == set.end()) { //x가 없으면
                set.insert(x); //x 추가
            }
            else { //x 있으면
                set.erase(x); //삭제
            }
        }
        if (cmd == "all") {
            for (int i = 1; i <= 21; i++) { //1부터 20이 있는 set 만들기
                all.insert(i);
            }
            set = all; //set을 all로 대체
        }
        if (cmd == "empty") {
            set.clear();
        }
    }

    return 0;
}